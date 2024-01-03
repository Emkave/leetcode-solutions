// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        int l=0, r=0;
        int longest = 0;
        int local = 0;
        const int size = s.size();

        std::unordered_set<char> set_;

        while (r < size) {
            if (set_.count(s[r])) {
                while (s[l] != s[r]) {
                    set_.erase(s[l]);
                    l++;
                }
                set_.erase(s[l]);
                l++;
            }

            set_.emplace(s[r]);
            r++;
            longest = max(longest, r - l);
        }

        return longest;
    }
};