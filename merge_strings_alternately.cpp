// https://leetcode.com/problems/merge-strings-alternately/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        unsigned i=0, j=0;
        std::string to_return = "";

        while (!(i > word1.size() && j > word2.size())) {
            if (i < word1.size()) {
                to_return += word1[i];
            }

            if (j < word2.size()) {
                to_return += word2[j];
            }

            i++;
            j++;
        }


        return to_return;
    }
};