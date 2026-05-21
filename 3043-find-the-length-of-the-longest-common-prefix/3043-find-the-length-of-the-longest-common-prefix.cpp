class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for (auto& v : arr1) {
            string s = to_string(v), cur = "";
            int n = s.size(), val;

            for (int i = 0; i < n; i++) {
                cur += s[i];
                val = stoi(cur); 
                st.insert(val);
            }
        }

        int res = 0;
        for (auto& v : arr2) {
            string s = to_string(v);
            int n = s.size();

            for (int i = res; i < n; i++) {
                int cur = stoi(s.substr(0, i + 1));

                if (st.count(cur)) {
                    res = i + 1;
                }
            }
        }

        return res;
    }
};