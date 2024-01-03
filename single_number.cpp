// https://leetcode.com/problems/single-number/

class Solution {
public:
    inline int singleNumber(vector<int>& nums) const noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);
        int least = 0;

        for (const int & elem : nums) {
            least = elem ^ least;
        }
        

        return least;
    }
};