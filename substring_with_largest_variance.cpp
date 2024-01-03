// https://leetcode.com/problems/substring-with-largest-variance/

class Solution {
public:
    inline int max(int & a, int b) const noexcept {
        return (a > b) ? a : b;
    }

    inline int min(int & a, int b) const noexcept {
        return (a < b) ? a : b;
    }

    int largestVariance(string s) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);
        std::map<char, int> counter;
        int globalMax = 0;
        unsigned majorCount = 0;
        unsigned minorCount = 0;
        unsigned restMinor = 0;
        char major;
        char minor;

        for (const char & ch : s) {
            counter[ch]++;
        }

        for (unsigned short i = 0; i < 26; i++) {
            for (unsigned short j = 0; j < 26; j++) {
                if (i == j || counter['a' + i] == 0 || counter['a' + j] == 0) {
                    continue;
                }

                major = 'a' + i;
                minor = 'a' + j;
                majorCount = 0;
                minorCount = 0;
                restMinor = counter[minor];

                for (const char & ch : s) {
                    if (ch == major) {
                        majorCount++;
                    }

                    if (ch == minor) {
                        minorCount++;
                        restMinor--;
                    }

                    if (minorCount > 0) {
                        globalMax = this->max(globalMax, majorCount - minorCount);
                    }

                    if (majorCount < minorCount && restMinor > 0) {
                        majorCount = 0;
                        minorCount = 0;
                    }
                }
            }
        }

        return globalMax;
    }
};