// https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        std::unordered_map<int, int> st;
        int ans = 0;

        for (unsigned i=0; i<nums.size(); i++) {
            auto iter = st.find(k - nums[i]);
            if (iter != st.end()) {
                ans++;
                if (--iter->second == 0) {
                    st.erase(iter);
                }
            } else {
                st[nums[i]]++;
            }
        }

        return ans;
    }
};