// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stak;

        for (const char & ch : s) {
            switch (ch) {
                case '(':
                case '{':
                case '[':
                    stak.emplace(ch);
                    break;
                
                case ')':
                    if (!stak.empty() && stak.top() == '(') {
                        stak.pop();
                    } else {
                        return false;
                    }
                    break;
                
                case '}':
                    if (!stak.empty() && stak.top() == '{') {
                        stak.pop();
                    } else {
                        return false;
                    }
                    break;
                
                case ']':
                    if (!stak.empty() && stak.top() == '[') {
                        stak.pop();
                    } else {
                        return false;
                    }
                    break;
            }
        }
        if (stak.empty()) {
            return true;
        }

        return false;
    }
};