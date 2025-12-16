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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, stk;
        int i = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            while (!stk.empty() && res[stk.back()] < cur->val) {
                res[stk.back()] = cur->val;
                stk.pop_back();
            }
            stk.push_back(i++);
            res.push_back(cur->val);
        }

        for (auto &ind: stk) {
            res[ind] = 0;
        }

        return res;
    }
};