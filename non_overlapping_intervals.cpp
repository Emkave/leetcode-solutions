/*
https://leetcode.com/problems/non-overlapping-intervals/
*/


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) const noexcept {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::cerr.tie(nullptr);
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> & a, const std::vector<int> & b) {
            return a[1] < b[1];
        });
        
        int ans = 0, p = INT_MIN;

        for (size_t i=0; i<intervals.size(); i++) {
            int _1 = intervals[i][0];
            int _2 = intervals[i][1];
            if (_1 >= p) {
                p = _2;
            } else {
                ans++;
            }
        }
        return ans;
    }
};