class Solution {
public:
    bool canFinish(vector<int>& piles, int speed, int h) {
        int hoursNeeded = 0;
        for (int banana : piles) {
            hoursNeeded += std::ceil((double)banana / speed);
        }
        return hoursNeeded <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, mid, h)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};
