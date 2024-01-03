/*
https://leetcode.com/problems/max-consecutive-ones-iii/
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) const noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);
        int l = 0, r = 0;
        const int size = nums.size();
        int ans = 0;
        int reversible = k;

        while (r < size) {
            if (nums[r] == 0) {
                if (reversible > 0) {
                    reversible--;
                } else {
                    while (nums[l] != 0) {
                        l++;
                    }
                    l++;
                }
            }
            ans = std::max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
