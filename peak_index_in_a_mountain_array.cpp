/*
https://leetcode.com/problems/peak-index-in-a-mountain-array/
*/

class Solution {
public:
    inline int peakIndexInMountainArray(const vector<int> & arr) const noexcept {
        std::ios_base::sync_with_stdio(false);
        std::cerr.tie(nullptr);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        unsigned l = 0, r = arr.size()-1;
        unsigned mid = arr.size() / 2;

        while (l - r > 1) {
            mid = (r + l) / 2;
            if (arr[mid] < arr[mid + 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};