// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);

        int l=0, r=0;
        int ans=INT_MAX;
        int sum = 0;

        while (r < nums.size()) {
            sum += nums[r];
            while (sum >= target) {
                ans = (r - l + 1 < ans) ? r - l + 1 : ans;
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};