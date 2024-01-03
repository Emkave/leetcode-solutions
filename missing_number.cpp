// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

        int total_sum = (nums.size() * (nums.size() + 1)) / 2;

        for (const int & num : nums) {
            total_sum -= num;
        }

        return total_sum;
    }
};