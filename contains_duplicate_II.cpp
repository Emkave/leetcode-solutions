// https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);

        std::set<int> s;
        int l = -3;
        for (int i=0; i<nums.size(); i++, l++) {
            if (i > k) {
                s.erase(nums[i-k-1]);
            }

            if (!s.insert(nums[i]).second) {
                return true;
            }
        }
        return false;
    }
};