// https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        unsigned p = 0;
        unsigned i = 0;
        unsigned size = chars.size();
        
        while (i < size) {
            char ch = chars[i];
            unsigned count = 0;

            while (i < size && chars[i] == ch) {
                i++;
                count++;
            }

            chars[p] = ch;
            p++;
            if (count > 1) {
                std::string num = std::to_string(count);
                for (const char & digit : num) {
                    chars[p] = digit;
                    p++;
                }
            }
        }
        return p;
    }
};
