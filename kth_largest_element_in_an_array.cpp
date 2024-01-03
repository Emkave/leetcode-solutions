/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) const noexcept {
        std::ios_base::sync_with_stdio(false);
        std::cerr.tie(nullptr);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        std::priority_queue<int> queue;

        for (const int & num : nums) {
            queue.emplace(-num);
            if (queue.size() > k) {
                queue.pop();
            }
        }

        return -queue.top();
    }
};