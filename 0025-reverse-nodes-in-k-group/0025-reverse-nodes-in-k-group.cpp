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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;

        while (1) {
            ListNode* kth = prevGroupEnd;

            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (kth == nullptr) {
                break;
            }

            ListNode* cur = prevGroupEnd->next;
            ListNode* start = cur;
            
            ListNode* nextGroupStart = kth->next;
            ListNode* prev = nextGroupStart;

            while (cur != nextGroupStart) {
                ListNode* nextNode = cur->next;

                cur->next = prev;
                prev = cur;
                cur = nextNode;
            }

            prevGroupEnd->next = kth;
            prevGroupEnd = start;
            cur = nextGroupStart;
        }

        return dummy->next;
    }
};