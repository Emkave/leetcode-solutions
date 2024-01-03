// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        

        if (nums.size() < 3) {
            return false;
        }

        int first = INT_MAX;
        int second = INT_MAX;

        for (const int & n : nums) {
            if (n <= first) {
                first = n;
            } else if (n <= second) {
                second = n;
            } else {
                return true;
            }
        }

        return false;
    }
};