class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int n = a.size();
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                st.insert(a[i]);
            }
        }

        return st.size();
    }
};