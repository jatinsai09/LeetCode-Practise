class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string t;

        while (getline(ss, t, '/')) {
            if (t == "" || t == ".") {
                continue;
            }

            if (t == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(t);
            }
        }

        string res = "";
        for (const auto& s: st) {
            res += "/" + s;
        }

        return st.empty() ? "/" : res;
    }
};