// https://leetcode.com/problems/determine-if-two-strings-are-close/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);

        if (word2.length() != word1.length()) {
            return false;
        }

        std::vector<int> count1(26, 0), count2(26, 0);
        std::unordered_set<char> set1, set2;

        for (const char & letter : word1) {
            count1[letter - 'a']++;
            set1.insert(letter);
        }
        for (const char & letter : word2) {
            count2[letter - 'a']++;
            set2.insert(letter);
        }

        std::sort(count1.begin(), count1.end());
        std::sort(count2.begin(), count2.end());

        return count1 == count2 && set1 == set2;
    }
};