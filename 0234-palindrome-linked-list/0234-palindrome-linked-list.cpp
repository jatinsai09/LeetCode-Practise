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
    bool isPalindrome(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (!head || !head->next) {
            return true;
        }

        ListNode *slow = head, *fast = head, *prev, *temp;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        prev = nullptr;
        while (slow) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        fast = head, slow = prev;
        while (slow) {
            if (fast->val != slow->val) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};