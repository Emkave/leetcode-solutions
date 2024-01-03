// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    inline vector<int> productExceptSelf(const vector<int> & nums) noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        const int size = nums.size();
        std::vector<int> to_return (size, 0);
        to_return[0] = 1;
        
        int l = 1, r = size-2;

        while (l < size) {
            to_return[l] = nums[l-1] * to_return[l-1];
            l++;
        }

        int prev = 1;
        while (r >= 0) {
            to_return[r] *= nums[r+1] * prev;
            prev *= nums[r+1];
            r--;
        }

        return to_return;
    }
};