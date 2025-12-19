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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);

        ListNode *first = dummy, *second = dummy;
        for (int i = 1; i <= n; i++) {
            first = first->next;
        }

        while (first->next) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;

        return dummy->next;
    }
};