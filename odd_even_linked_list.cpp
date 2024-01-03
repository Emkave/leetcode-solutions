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
 * https://leetcode.com/problems/odd-even-linked-list/
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);

        if (!head) {
            return nullptr;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        
        return head;
    }
};
