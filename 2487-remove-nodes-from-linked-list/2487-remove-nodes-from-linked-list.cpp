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
    ListNode* reverseLL(ListNode* head) {
        ListNode *prev = NULL, *cur = head;
        while (cur) {
            ListNode* nxt = cur->next;

            cur->next = prev;

            prev = cur;
            cur = nxt;
        }

        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* rhead = reverseLL(head);
        ListNode* prev = rhead;

        ListNode* cur = prev->next;
        prev->next = NULL;
        while (cur) {
            ListNode* nxt = cur->next;
            if (cur->val >= prev->val) {
                cur->next = prev;
                prev = cur;
            }
            cur = nxt;
        }
        return prev;
    }
};