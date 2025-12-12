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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        int n = 0;
        ListNode* cur = head;
        ListNode* tail = nullptr;
        while (cur) {
            n++;
            tail = cur;
            cur = cur->next;
        }

        k = k % n;
        if (k == 0) {
            return head;
        }

        cur = head;
        for (int i = 1; i < n - k; i++) {
            cur = cur->next;
        }
        tail->next = head;
        ListNode* newHead = cur->next;
        cur->next = nullptr;

        return newHead;
    }
};