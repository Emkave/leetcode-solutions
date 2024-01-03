// https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    inline std::string reverseVowels(std::string s) noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int l = 0, r = s.size()-1;

        while (l <= r) {
            
            while (vowels.find(s[l]) == vowels.end() && l < r) {
                l++;
            }

            while (vowels.find(s[r]) == vowels.end() && r > l) {
                r--;
            }

            std::swap(s[l], s[r]);

            l++;
            r--;
        }
        return s;
    }
};