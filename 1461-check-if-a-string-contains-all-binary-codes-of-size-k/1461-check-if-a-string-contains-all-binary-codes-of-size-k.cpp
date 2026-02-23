class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        set<int> st;

        int total = (1 << k), msk = total - 1, hash = 0;

        for (int i = 0; i < n; i++) {
            hash = ((hash << 1) & msk) | (s[i] - '0');
            if (i + 1 >= k) {
                st.insert(hash);
            }
            if (st.size() == total) {
                return true;
            }
        }

        return false;
    }
};