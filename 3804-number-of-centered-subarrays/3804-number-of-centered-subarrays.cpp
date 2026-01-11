class Solution {
public:
    int centeredSubarrays(vector<int>& a) {
        int n = a.size(), res = 0;
        
        for (int i = 0; i < n; i++) {
            set<int> st;
            int sum = 0;
            for (int j = i; j < n; j++) {
                st.insert(a[j]);
                sum += a[j];
                if (st.count(sum)) {
                    res++;
                }
            }
        }

        return res;
    }
};