class Solution {
#define ll long long int
public:
    long long countConsistent(vector<int>& a) {
        ll n = a.size();

        vector<int> l(n, -1), st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && (a[i] & a[st.back()]) == a[i] && a[i] < a[st.back()]) {
                st.pop_back();
            }

            if (!st.empty()) {
                l[i] = st.back();
            }
            st.push_back(i);
        }

        st.clear();

        ll res = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && (a[st.back()] & a[i]) == a[i]) {
                st.pop_back();
            }

            int r = n;
            if (!st.empty()) {
                r = st.back();
            }
            st.push_back(i);

            res += 1LL * (i - l[i]) * (r - i);

        }
        return res;
    }
};