class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nge;
        int n = nums1.size(), m = nums2.size();

        for (int i = m - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }
            nge[nums2[i]] = (st.empty() ? -1 : st.top());
            st.push(nums2[i]);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nge[nums1[i]];
        }

        return res;
    }
};