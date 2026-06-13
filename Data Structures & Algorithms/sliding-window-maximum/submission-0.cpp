class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        for (int right = 0; right < nums.size(); right++) {
            // remove indices outside window
            while (!dq.empty() && dq.front() <= right - k) {
                dq.pop_front();
            }

            // remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }

            dq.push_back(right);

            // window formed
            if (right >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
