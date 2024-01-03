/*
https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

class Solution {
public:
    inline int findNumberOfLIS(std::vector<int>& nums) const noexcept {
        int n = nums.size();
        std::vector<int> lenght(n, 1);
        std::vector<int> count(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (lenght[j] + 1 > lenght[i]) {
                        lenght[i] = lenght[j] + 1;
                        count[i] = 0;
                    }
                    if (lenght[j] + 1 == lenght[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }

        int maxLength = *max_element(lenght.begin(), lenght.end());
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (lenght[i] == maxLength) {
                result += count[i];
            }
        }

        return result;
    }
};