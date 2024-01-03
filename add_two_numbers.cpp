/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * https://leetcode.com/problems/add-two-numbers/
 */
class Solution {
public:
    ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
        ListNode * sum = new ListNode();
        ListNode * head = sum;
        ListNode * ptr1 = l1;
        ListNode * ptr2 = l2;
        int carry = 0;
        int s = 0;

        while (ptr1 != NULL || ptr2 != NULL || carry != 0) {
            s = ((ptr1 != NULL) ? ptr1->val : 0) + ((ptr2 != NULL) ? ptr2->val : 0) + carry;
            carry = s / 10;
            sum->next = new ListNode(s % 10);

            sum = sum->next;

            if (ptr1 != NULL) {
                ptr1 = ptr1->next;
            }

            if (ptr2 != NULL) {
                ptr2 = ptr2->next;
            }
        }

        return head->next;
    }
};