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
    ListNode* reverse(ListNode* head) {
        if (head->next == NULL) {
            return head;
        }

        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;

        return newhead;
    }

    ListNode* get(ListNode* temp, int n) {
        if (n == 0) {
            return NULL;
        }

        int c = 1;
        while (c < n) {
            temp = temp->next;
            c++;
        }
        return temp;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head->next == NULL) {
            return head;
        }

        ListNode* d1 = get(head, left - 1);

        ListNode* l;
        if (d1 != NULL) {
            l = d1->next;
        } else {
            l = head;
        }
        ListNode* r = get(head, right);

        ListNode* d2 = r->next;
        r->next = NULL;

        ListNode* th = reverse(l);
        l->next = d2;
        if (d1) {
            d1->next = r;
        } else {
            head = r;
        }

        return head;
    }
};