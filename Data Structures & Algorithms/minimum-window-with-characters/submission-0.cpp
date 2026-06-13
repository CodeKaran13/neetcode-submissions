class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        std::unordered_map<char, int> need;
        std::unordered_map<char, int> window;

        for (const char c : t) {
            need[c]++;
        }

        int required = need.size();
        int formed = 0;

        int left = 0;
        int minLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (need.contains(c) && window[c] == need[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need.contains(leftChar) && window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};
