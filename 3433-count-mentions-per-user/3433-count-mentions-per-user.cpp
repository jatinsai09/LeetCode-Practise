class Solution {
public:
    vector<int> give(string& s) {
        vector<int> to;
        stringstream ss(s);
        string id;
        while (ss >> id) {
            to.push_back(stoi(id.substr(2)));
        }
        return to;
    }
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> res(n), status(n, 1), offline(n, 0);
        sort(begin(events), end(events), [&](auto& a, auto& b) {
            if (stoi(a[1]) == stoi(b[1])) {
                return a[0][0] > b[0][0];
            }
            return stoi(a[1]) < stoi(b[1]);
        });

        int all = 0;
        for (auto& e : events) {
            if (e[0] == "OFFLINE") {
                offline[stoi(e[2])] = stoi(e[1]);
                continue;
            }

            if (e[2] == "ALL") {
                all++;
            } else if (e[2] == "HERE") {
                for (int i = 0; i < n; i++) {
                    if (offline[i] == 0 || offline[i] + 60 <= stoi(e[1])) {
                        res[i]++;
                    }
                }
            } else {
                vector<int> to = give(e[2]);
                for (auto& id : to) {
                    res[id]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            res[i] += all;
        }
        return res;
    }
};