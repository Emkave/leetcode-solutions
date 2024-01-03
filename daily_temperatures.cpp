/*
https://leetcode.com/problems/daily-temperatures/
*/

class Solution {
public:
    vector<int> dailyTemperatures(const vector<int> & temperatures) const noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);
        
        if (temperatures.size() == 1) {
            return std::vector<int>{1};
        }

        std::stack<std::pair<int, int>> st;
        std::vector<int> ans (temperatures.size(), 0);
        st.emplace(0, temperatures[0]);

        unsigned i=1;
        
        while (i < temperatures.size()) {
            while (!st.empty() && temperatures[i] > st.top().second) {
                ans[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.emplace(i, temperatures[i]);
            i++;
        }

        return ans;
    }
};