class Solution {
public:
    bool parseBoolExpr(string s) {
        int n = s.size();

        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == ',') {
                continue;
            }

            if (s[i] == ')') {
                int t = 0, f = 0;
                while (1) {
                    char c = st.top();
                    st.pop();
                    if (c == '(') {
                        break;
                    }
                    
                    (c == 't' ? t++ : f++);
                }
                char c = st.top();
                st.pop();

                if (c == '&') {
                    st.push(f ? 'f' : 't');
                } else if (c == '|') {
                    st.push(t ? 't' : 'f');
                } else if (c == '!') {
                    st.push(t ? 'f' : 't');
                }
            } else {
                st.push(s[i]);
            }
        }
        return (st.top() == 't');
    }
};