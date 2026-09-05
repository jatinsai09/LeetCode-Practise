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
    ListNode* reverseList(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ListNode *prev = NULL, *cur = head, *nxt;
        while (cur) {
            nxt = cur->next;
            
            cur->next = prev;

            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};