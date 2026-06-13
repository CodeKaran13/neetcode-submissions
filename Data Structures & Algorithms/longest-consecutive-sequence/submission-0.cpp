class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;
        for (const int num : nums) {
            if (!set.count(num - 1)) {
                int current = num;
                int length = 1;
                while (set.count(current + 1)) {
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
