// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    inline bool isSubsequence(const string s, const string t) noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        unsigned l = 0, r = 0;
        unsigned correct = 0;

        while (r < t.length()) {
            if (t[r] == s[l]) {
                correct++;
                r++;
                l++;
                continue;
            }
            r++;
        }

        return correct == s.length();
    }
};