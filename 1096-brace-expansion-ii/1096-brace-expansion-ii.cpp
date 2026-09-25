class Solution {
public:
    vector<string> braceExpansionII(string s) {

        function<vector<string>(string)> f = [&](string s) {
            set<string> st;
            vector<string> cur = {""};

            int n = s.size(), i = 0;
            while (i < n) {
                if (s[i] == '{') {
                    int j = i, d = 0;
                    while (j < n) {
                        if (s[j] == '{') {
                            d--;
                        } else if (s[j] == '}') {
                            d++;
                        }

                        if (d == 0) {
                            break;
                        }
                        j++;
                    }

                    vector<string> got = f(s.substr(i + 1, j - i - 1));

                    vector<string> nxt;
                    for (auto &s1: cur) {
                        for (auto &s2: got) {
                            nxt.push_back(s1 + s2);
                        }
                    }
                    
                    cur = nxt;
                    i = j;
                } else if(s[i] == ',') {
                    for (auto &s1: cur) {
                        st.insert(s1);
                    }
                    cur = {""};
                } else {
                    for (auto &s1: cur) {
                        s1 += s[i];
                    }
                }

                i++;
            }

            for (auto &s1: cur) {
                st.insert(s1);
            }
            vector<string> res(begin(st), end(st));

            return res;
        };

        vector<string> res = f(s);
        sort(begin(res), end(res));

        return res;
    }
};