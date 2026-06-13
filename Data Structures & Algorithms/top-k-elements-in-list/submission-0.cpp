class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq;
        for (const int num: nums)
        {
            freq[num]++;
        }

        using Pair = std::pair<int, int>;
        priority_queue<Pair, vector<Pair>, greater<Pair>> minHeap;

        for (auto& pair : freq)
        {
            int num = pair.first;
            int count = pair.second;
            minHeap.push({count, num});
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
