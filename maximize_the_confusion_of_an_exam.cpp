// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);

        int l = 0, r = 0;
        int t = 0, f = 0;
        int longest = 0;
        int maxFreq = 0;

        while (r < answerKey.size()) {
            if (answerKey[r] == 'T') {
                t++; 
            } else {
                f++; 
            }

            maxFreq = max(maxFreq, max(t, f));
            while ((r - l + 1) - maxFreq > k) {
                if (answerKey[l] == 'T') {
                    t--; 
                } else {
                    f--; 
                }
                l++;
            }
            longest = max(longest, r - l + 1);
            r++;
        }
        return longest;
    }
};