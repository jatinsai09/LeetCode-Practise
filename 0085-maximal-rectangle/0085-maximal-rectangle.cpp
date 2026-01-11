auto speedup = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return NULL;
}();

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), maxi = 0;

        int sum;
        vector<vector<int>> psum(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            sum = 0;
            for (int i = 0; i < n; i++) {
                sum += matrix[i][j] - '0';
                if (matrix[i][j] == '0') {
                    sum = 0;
                }
                psum[i][j] = sum;
            }
        }

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, Largest(psum[i]));
        }
        return maxi;
    }

    int Largest(vector<int>& arr) {
        stack<int> st;
        int maxi = 0, n = arr.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int e = arr[st.top()];
                st.pop();

                int nse = i, pse = st.empty() ? -1 : st.top();

                maxi = max(maxi, e * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int nse = n;
            int e = arr[st.top()];
            st.pop();

            int pse = st.empty() ? -1 : st.top();

            maxi = max(maxi, e * (nse - pse - 1));
        }

        return maxi;
    }
};