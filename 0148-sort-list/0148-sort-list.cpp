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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *a = head, *b = slow->next;
        slow->next = NULL;

        a = sortList(a);
        b = sortList(b);

        return merge(a, b);
    }
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(-1);

        ListNode* temp = c;
        while (a && b) {
            if (a->val < b->val) {
                temp->next = a;
                a = a->next;
            } else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }

        if (a) {
            temp->next = a;
        } else {
            temp->next = b;
        }

        return c->next;
    }
};