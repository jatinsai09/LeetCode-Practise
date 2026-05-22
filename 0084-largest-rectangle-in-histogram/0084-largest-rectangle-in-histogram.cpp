class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        stack<int> st;
        int n = heights.size(), maxi = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();

                int nse = i, pse = (st.empty() ? -1 : st.top());

                maxi = max(maxi, h * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();

            int nse = n, pse = (st.empty() ? -1 : st.top());
            maxi = max(maxi, h * (nse - pse - 1));
        }

        return maxi;
    }
};