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
    ListNode* mergeNodes(ListNode* head) {
        if (!head->next) {
            return NULL;
        }

        ListNode* st = head->next;
        int sum = 0;
        while (st->val != 0) {
            sum += st->val;
            st = st->next;
        }

        head->val = sum;
        head->next = mergeNodes(st);
        return head;
    }
};