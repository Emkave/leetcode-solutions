// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        unsigned count = 0;

        for (const int & elem : nums) {
            if (target == elem) {
                count++;
            }
        }

        return (count > nums.size() / 2) ? true : false;
    }
};