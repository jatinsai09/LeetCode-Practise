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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* cur = head;
        while (cur->next) {
            int g = __gcd(cur->val, cur->next->val);
            ListNode* gcdNode = new ListNode(g);

            gcdNode->next = cur->next;
            cur->next = gcdNode;

            cur = gcdNode->next;
        }

        return head;
    }
};