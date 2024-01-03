// https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);

        std::unordered_set<unsigned> buff;
        unsigned counter = 0, l = 0, r = 0;

        std::sort(arr.begin(), arr.end());

        while (r < arr.size()) {
            while (r < arr.size() && arr[l] == arr[r]) {
                r++;
                counter++;
            }

            if (!buff.emplace(counter).second) {
                return false;
            }

            l = r;
            counter = 0;
        }

        return true;
    }
};