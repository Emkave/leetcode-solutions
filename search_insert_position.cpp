/*
https://leetcode.com/problems/search-insert-position/
*/

class Solution {
public:
    inline int searchInsert(const vector<int> & nums, const int target) const noexcept {
        return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};