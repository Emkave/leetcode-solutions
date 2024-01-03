/*
https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
*/

class Solution {
public:
    const int longestSubsequence(vector<int> & arr, const int difference) const noexcept {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);

        std::unordered_map<int, int> ref;
        
        const unsigned size = arr.size();
        int ans = 1, lenght = 0;

        for (unsigned i = 0; i < size; i++) {
            if (ref.find(arr[i] - difference) == ref.end()) {
                lenght = 0;
            } else {
                lenght = ref[arr[i] - difference];
            }
            ref[arr[i]] = lenght + 1;
            ans = (ans > ref[arr[i]]) ? ans : ref[arr[i]];
        }

        return ans;
    }
};