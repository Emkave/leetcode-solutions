// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    inline const int min(const int & a, const int & b) const noexcept {
        return (a < b) ? a : b;
    }

    int maxArea(vector<int> & height) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        int l = 0, r = height.size() - 1;
        int biggest = 0;
        int local = 0;
        int min = 0;

        while (l < r) {
            min = this->min(height[l], height[r]);
            local = min * (r - l);
            biggest = (local > biggest) ? local : biggest;
            
            if (min == height[l]) {
                l++;
            } else {
                r--;
            }
        }
        return biggest;
    }
};