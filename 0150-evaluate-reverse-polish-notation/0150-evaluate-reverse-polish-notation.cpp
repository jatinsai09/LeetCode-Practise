class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();

        stack<int> st;
        for (auto& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int res = 0;
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if (s == "+")
                    res = b + a;
                else if (s == "-")
                    res = b - a;
                else if (s == "*")
                    res = b * a;
                else
                    res = b / a;

                st.push(res);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};