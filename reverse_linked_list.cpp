/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 
 * https://leetcode.com/problems/reverse-linked-list/
 */
class Solution {
public:
    inline ListNode * insert(ListNode ** head, const int & val) noexcept {
        ListNode * new_ = new ListNode(val);
        new_->next = *head;
        *head = new_;
        return *head;
    }

    ListNode * reverseList(ListNode * head) noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);
        
        ListNode * reversed = nullptr;

        for (ListNode * ptr = head; ptr != nullptr; ptr = ptr->next) {
            reversed = this->insert(&reversed, ptr->val);
        }

        return reversed;
    }
};