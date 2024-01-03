// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    inline vector<bool> kidsWithCandies(vector<int>& candies, const int extraCandies) noexcept {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);

        unsigned biggest = 0;
        std::vector<bool> to_return = {};
        for (const int & elem : candies) {
            biggest = (elem > biggest) ? elem : biggest;
        }

        for (const int & elem : candies) {
            if (elem + extraCandies >= biggest) {
                to_return.emplace_back(true);
            } else {
                to_return.emplace_back(false);
            }
        }

        return to_return;
    }
};