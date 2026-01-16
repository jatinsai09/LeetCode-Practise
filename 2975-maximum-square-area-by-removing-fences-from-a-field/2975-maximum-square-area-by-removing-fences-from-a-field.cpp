class Solution {
#define ll long long int
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        ll res = 0, mod = 1e9 + 7;
        unordered_set<int> st;

        hFences.push_back(1);
        hFences.push_back(m);

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = 0; j < hFences.size(); j++) {
                if (i == j) {
                    continue;
                }
                st.insert(abs(hFences[i] - hFences[j]));
            }
        }

        vFences.push_back(1);
        vFences.push_back(n);

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = 0; j < vFences.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (st.count(abs(vFences[i] - vFences[j]))) {
                    res = max(res, llabs(vFences[i] - vFences[j]));
                }
            }
        }

        if (!res) {
            return -1;
        }

        return (res * res) % mod;
    }
};