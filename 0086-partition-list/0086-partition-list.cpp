/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* d1 = new ListNode(-1);
        ListNode* d2 = new ListNode(-1);

        ListNode *a = d1, *b = d2, *cur = head;
        while (cur) {
            if (cur->val < x) {
                a->next = new ListNode(cur->val);
                a = a->next;
            } else {
                b->next = new ListNode(cur->val);
                b = b->next;
            }

            cur = cur->next;
        }
        a->next = d2->next;

        return d1->next;
    }
};