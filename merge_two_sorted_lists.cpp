struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};


class Solution {
public:
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) {
            return nullptr;
        }

        ListNode * to_return = nullptr;
        ListNode * end_ptr = to_return;

        while (list1 && list2) {
            ListNode * node = nullptr;
            int value;

            if (list1->val <= list2->val) {
                value = list1->val;
                list1 = list1->next;
            } else {
                value = list2->val;
                list2 = list2->next;
            }

            node = new ListNode(value);

            if (!to_return) {
                to_return = node;
                end_ptr = to_return;
            } else {
                end_ptr->next = node;
                end_ptr = end_ptr->next;
            }
        }

        ListNode * ptr = nullptr;
        if (list1) {
            ptr = list1;
        } else if (list2) {
            ptr = list2;
        }

        while (ptr) {
            ListNode * node = new ListNode(ptr->val);

            if (!to_return) {
                to_return = node;
                end_ptr = to_return;
            } else {
                end_ptr->next = node;
                end_ptr = end_ptr->next;
            }

            ptr = ptr->next;
        }

        return to_return;
    }
};