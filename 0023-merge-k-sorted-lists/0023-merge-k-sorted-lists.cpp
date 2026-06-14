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
#define pil pair<int, ListNode*>
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        priority_queue<pil, vector<pil>, greater<pil>> pq;

        for (auto& l : lists) {
            if (l) {
                pq.push({l->val, l});
            }
        }

        if (pq.empty()) {
            return NULL;
        }

        ListNode* dummy = new ListNode(0);

        ListNode* cur = dummy;
        while (!pq.empty()) {
            ListNode *node = pq.top().second;
            pq.pop();

            cur->next = node;
            cur = cur->next;

            if (node->next) {
                pq.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};