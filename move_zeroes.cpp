// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        unsigned countzero = 0;

        for (const int & elem : nums) {
            countzero = (elem == 0) ? countzero + 1 : countzero;
        }

        nums.reserve(countzero);

        for (unsigned i=0; i<nums.size();) {
            if (nums[i] == 0 && countzero > 0) {
                nums.erase(nums.begin() + i);
                nums.emplace_back(0);
                countzero--;
                continue;
            }
            i++;
        }
    }
};