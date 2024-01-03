/*
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        std::sort(events.begin(), events.end());

        std::vector<int> starts;
        for(auto & event : events) starts.push_back(event[0]);

        for(int cur_index = n - 1; cur_index >= 0; --cur_index) {
            int next_index = upper_bound(starts.begin(), starts.end(), events[cur_index][1]) - starts.begin();
            for(int count = 1; count <= k; ++count) {
                dp[count][cur_index] = max(dp[count][cur_index + 1], events[cur_index][2] + dp[count - 1][next_index]);
            }
        }

        return dp[k][0];
        

    }
};