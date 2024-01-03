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
 * https://leetcode.com/problems/add-two-numbers-ii/
 */
class Solution {
public:
    ListNode * addTwoNumbers(ListNode * l1, ListNode* l2) const noexcept {
        std::stack<int> s1, s2;

        while (l1 != nullptr) {
            s1.emplace(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            s2.emplace(l2->val);
            l2 = l2->next;
        }

        int totalSum = 0, carry = 0;
        ListNode * ans = new ListNode();
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                totalSum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                totalSum += s2.top();
                s2.pop();
            }

            ans->val = totalSum % 10;
            carry = totalSum / 10;
            ListNode * newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            totalSum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};