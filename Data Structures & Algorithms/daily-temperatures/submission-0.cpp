class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<int> st;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int previousDay = st.top();
                st.pop();
                result[previousDay] = i - previousDay;
            }
            st.push(i);
        }
        return result;
    }
};
