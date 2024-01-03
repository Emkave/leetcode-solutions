/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

class Solution {
public:
    void sortColors(vector<int> & nums) const noexcept {
        std::ios_base::sync_with_stdio(false);
        std::cerr.tie(nullptr);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int p1 = 0, curr = 0, p2 = nums.size() - 1;

        while (curr <= p2) {
            switch (nums[curr]) {
                case 0:
                    std::swap(nums[curr++], nums[p1++]);
                    break;
                
                case 2:
                    std::swap(nums[curr], nums[p2--]);
                    break;
                
                default:
                    curr++;
                    break;
            }
        }
    }
};