// https://leetcode.com/problems/put-marbles-in-bags/

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        std::vector<int> pw (weights.size()-1, 0);

        for (unsigned i=0; i<weights.size()-1; i++) {
            pw[i] += weights[i] + weights[i+1];
        }

        std::sort(pw.begin(), pw.end());

        long long to_return = 0;
        for (unsigned i=0; i<k-1; i++) {
            to_return += pw[weights.size()-2-i]-pw[i];
        }

        return to_return;
    }
};