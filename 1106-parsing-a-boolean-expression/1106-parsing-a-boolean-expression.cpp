class Solution {
private:
    bool parse_or(vector<int>& res) {
        int mask = res[0];
        for (int i = 1; i < res.size(); i++) {
            mask |= res[i];
        }
        return mask;
    }

    bool parse_and(vector<int>& res) {
        int mask = res[0];
        for (int i = 1; i < res.size(); i++) {
            mask &= res[i];
        }
        return mask;
    }

public:
    bool parseBoolExpr(string s) {
        int n = s.size();

        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == ',') {
                continue;
            }

            if (s[i] == ')') {
                vector<int> res;
                while (1) {
                    char c = st.top();
                    st.pop();
                    if (c == '(') {
                        break;
                    }

                    res.push_back(c == 'f' ? 0 : 1);
                }
                char c = st.top();
                st.pop();

                if (c == '&') {
                    st.push(parse_and(res) ? 't' : 'f');
                } else if (c == '|') {
                    st.push(parse_or(res) ? 't' : 'f');
                } else if (c == '!') {
                    st.push(res[0] ? 'f' : 't');
                }
            } else {
                st.push(s[i]);
            }
        }
        return (st.top() == 't');
    }
};