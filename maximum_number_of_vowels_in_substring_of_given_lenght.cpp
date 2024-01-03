// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    constexpr inline const bool is_vowel(const char & ch) const noexcept(true) {
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }

    inline const int maxVowels(const string s, const int k) const noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);

        int l = 0, r = -1;
        int ans = 0;
        int local = 0;
        const int size = s.length();

        while (r < k - 1) {
            r++;
            if (this->is_vowel(s[r])) {
                local++;
            }
            ans = (local > ans) ? local : ans;
        }

        while (r < size) {
            r++;
            if (r < size && this->is_vowel(s[r])) {
                local++;
            }

            if (this->is_vowel(s[l])) { 
                local--;
            }
            l++;

            ans = (local > ans) ? local : ans;
        }
        return ans;
    }
};