// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string to_return = "";

        for (unsigned i=0; i<strs[0].size(); i++) {
            char ch = strs[0][i];
            for (unsigned j=1; j<strs.size(); j++) {
                if (ch != strs[j][i]) {
                    ch = '0';
                    break;
                }
            }
            if (ch != '0') {
                to_return += ch;
            } else {
                break;
            }
        }
        return to_return;
    }
};