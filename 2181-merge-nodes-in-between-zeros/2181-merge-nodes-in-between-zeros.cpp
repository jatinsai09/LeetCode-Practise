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
        ListNode* left = head->next;
        ListNode* right = left;

        while (right) {
            int sum = 0;
            while (right->val) {
                sum += right->val;
                right = right->next;
            }
            left->val = sum;
            right = right->next;
            left->next = right;
            left = right;
        }

        return head->next;
    }
};