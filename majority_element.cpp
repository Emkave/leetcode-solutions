// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        std::sort(nums.begin(), nums.end());

        int majority = 0;
        int count = 0;
        int maxCount = 0;

        for (unsigned i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] == nums[i - 1]) {
                count++;
            } else {
                if (count > maxCount) {
                    majority = nums[i - 1];
                    maxCount = count;
                }
                count = 1;
            }
        }
        if (count > maxCount) {
            majority = nums.back();
        }

        return majority;
    }
};