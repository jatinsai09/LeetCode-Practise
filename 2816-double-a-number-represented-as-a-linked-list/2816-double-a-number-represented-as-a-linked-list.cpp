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
    ListNode* doubleIt(ListNode* head) {
        if (head->val > 4) {
            head = new ListNode(0, head);
        }

        for (ListNode* cur = head; cur; cur = cur->next) {
            cur->val = (cur->val * 2) % 10;
            if (cur->next && cur->next->val > 4) {
                cur->val++;
            }
        }

        return head;
    }
};