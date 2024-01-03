// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/

class Solution {
public:
    std::string greatestLetter(std::string s) {
        std::set<char> st;
        std::string biggest = "";
        std::set<char>::iterator iter;

        for (unsigned i=0; i<s.size(); i++) {
            if (s[i] > 90) {
                iter = st.find(static_cast<int>(s[i] - 32));
                if (iter != st.end() && s[i] - 32 > biggest[0]) {
                    biggest = s[i] - 32;
                } else {
                    st.emplace(s[i]);
                }
            } else {
                iter = st.find(static_cast<int>(s[i] + 32));
                if (iter != st.end() && s[i] > biggest[0]) {
                    biggest = s[i];
                } else {
                    st.emplace(s[i]);
                }
            }
        }
        return biggest;
    }
};