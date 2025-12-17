class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> res(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && t[st.top()] < t[i]) {
                int ind = st.top();
                st.pop();
                res[ind] = i - ind;
            }

            st.push(i);
        }

        return res;
    }
};