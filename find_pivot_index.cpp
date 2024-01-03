/*
https://leetcode.com/problems/find-pivot-index/
*/

class Solution {
public:
    inline int pivotIndex(vector<int>& nums) const noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        int sum = 0;
        int half = 0;
        for (const int & elem : nums) {
            sum += elem;
        }

        for (int i=0; i<nums.size(); i++) {
            if (half == sum - half - nums[i]) {
                return i;
            }
            half += nums[i];
        }

        return -1;
    }
};