class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(begin(bank), end(bank));
        if (st.find(endGene) == st.end()) {
            return -1;
        }

        vector<char> v = {'A', 'C', 'G', 'T'};
        queue<string> q;
        q.push(startGene);
        int c = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string cur = q.front();
                q.pop();

                if (cur == endGene) {
                    return c;
                }

                for (int j = 0; j < cur.size(); j++) {
                    for (auto &c: v) {
                        if (c == cur[j]) {
                            continue;
                        }

                        string next = cur;
                        next[j] = c;

                        if (st.count(next)) {
                            q.push(next);
                            st.erase(next);
                        }
                    }
                }
            }
            c++;
        }
        return -1;
    }
};