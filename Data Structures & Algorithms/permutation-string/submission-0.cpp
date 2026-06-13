class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if (m > n) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (int i = 0; i < m; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        if (freq1 == freq2) return true;

        for (int right = m; right < n; right++) {
            freq2[s2[right] - 'a']++;

            int left = right - m;
            freq2[s2[left] - 'a']--;

            if (freq1 == freq2) return true;
        }

        return false;
    }
};
