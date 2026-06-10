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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);

        ListNode *cur = dummy, *t1 = l1, *t2 = l2;
        int carry = 0;
        while (t1 || t2 || carry) {
            int sum = carry;

            if (t1) {
                sum += t1->val;
                t1 = t1->next;
            }
            if (t2) {
                sum += t2->val;
                t2 = t2->next;
            }

            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            carry = sum / 10;
        }

        return dummy->next;
    }
};