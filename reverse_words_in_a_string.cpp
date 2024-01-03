// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL); 
    std::cout.tie(NULL);

    std::istringstream iss(s);
    std::string token;
    std::string to_return = "";

    while(std::getline(iss, token, ' ')) {
        if (!token.empty()) {
            token += " ";
            to_return.insert(0, token);
        }
    }

    if (!to_return.empty() && to_return[0] == ' ') {
        to_return.erase(to_return.begin());
    }
    to_return.pop_back();
    
    return to_return;
    }
};