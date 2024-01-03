// https://leetcode.com/problems/maximum-average-subarray-i/

class Solution {
public:
    double findMaxAverage(const vector<int> & nums, int k) noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);

        unsigned l = 0, r = 0;
        const unsigned size = nums.size();
        double local_sum = nums[0];
        double ans = INT_MIN;

        while (r < k - 1) {
            r++;
            local_sum += nums[r];
        }

        while (r < size) {
            ans = (local_sum / k > ans) ? local_sum / k : ans;
            r++;
            local_sum += (r < size) ? nums[r] : 0;
            local_sum -= nums[l];
            l++;
        }

        return ans;
    }
};