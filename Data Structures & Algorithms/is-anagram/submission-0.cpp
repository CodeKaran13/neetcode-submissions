class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        std::array<int, 26> freq = {0};
        for (auto& c : s)
        {
            freq[c - 'a']++;
        }

        for (auto& c : t)
        {
            freq[c - 'a']--;
        }

        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};
