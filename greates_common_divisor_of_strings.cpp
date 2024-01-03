// https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    inline string gcdOfStrings(const string str1, const string str2) noexcept {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);

        if (str1 + str2 != str2 + str1) {
            return "";
        }

        const int gcdb = gcd(str1.size(), str2.size());

        return str1.substr(0, gcdb);
        
    }
};