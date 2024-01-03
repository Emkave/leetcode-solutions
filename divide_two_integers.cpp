// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    long long divide(const long long dividend, const long long divisor) noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        if (dividend == -2147483648 && divisor == -1) {
            return 2147483648-1;
        }


        return dividend / divisor;
    }
};