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
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        int maxi = 0;

        // get middle node of the linked list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second part of linked list
        ListNode *nxt, *prev = NULL;
        while (slow) {
            nxt = slow->next;

            slow->next = prev;
            
            prev = slow;
            slow = nxt;
        }

        // get the sum
        ListNode* temp = head;
        while (prev) {
            maxi = max(maxi, temp->val + prev->val);
            temp = temp->next;
            prev = prev->next;
        }
        return maxi;
    }
};