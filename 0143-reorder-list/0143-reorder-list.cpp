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
    ListNode* findMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* reverseLL(ListNode* head) {
        ListNode *prev = NULL, *cur = head, *nxt;
        while (cur) {
            nxt = cur->next;

            cur->next = prev;

            prev = cur;
            cur = nxt;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }

        ListNode* middle = findMiddle(head);
        ListNode* second = reverseLL(middle->next);
        middle->next = NULL;

        ListNode* first = head;
        while (second) {
            ListNode *t1 = first->next, *t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};