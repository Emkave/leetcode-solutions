// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    int longestSubarray(vector<int> & nums) {
        int l = 0, r = 0;
        int f = 0;
        int longest = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) {
                f++;
            }
            r++;

            while (f > 1) {
                if (nums[l] == 0) {
                    f--;
                }
                l++;
            }
            if (f == 1 && r - l - 1 > longest) {
                longest = r - l - 1;
            }
        }

        if (f == 0) {
            longest = r - l - 1;
        }

        return longest;
    }
};