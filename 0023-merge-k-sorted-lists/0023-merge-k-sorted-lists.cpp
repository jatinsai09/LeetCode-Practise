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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        priority_queue<int, vector<int>, greater<int>> q;

        for (auto& l : lists) {
            while (l) {
                q.push(l->val);
                l = l->next;
            }
        }

        if (q.empty()) {
            return NULL;
        }

        ListNode* dummy = new ListNode(0);

        ListNode* cur = dummy;
        while (!q.empty()) {
            cur->next = new ListNode(q.top());
            q.pop();
            cur = cur->next;
        }
        
        return dummy->next;
    }
};