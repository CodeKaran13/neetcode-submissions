class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen;
        int left = 0;
        int maxLen = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            while (seen.contains(c)) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(c);
            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
