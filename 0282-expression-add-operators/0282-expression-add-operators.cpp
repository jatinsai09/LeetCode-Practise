class Solution {
public:
    vector<string> res;
    string s;
    int target;
    vector<string> addOperators(string num, int Target) {
        s = num;
        target = Target;

        dfs(0, "", 0LL, 0LL);
        return res;
    }

    void dfs(int i, const string& path, long got, long prev) {
        if (i == s.size()) {
            if (got == target) {
                res.push_back(path);
            }
            return;
        }

        string ss = "";
        long cur = 0;

        for (int j = i; j < s.size(); j++) {
            if (j > i && s[i] == '0') {
                break;
            }

            ss += s[j];
            cur = cur * 10 + (s[j] - '0');

            if (i == 0) {
                dfs(j + 1, ss, cur, cur);
            } else {
                dfs(j + 1, path + '+' + ss, got + cur, cur);
                dfs(j + 1, path + '-' + ss, got - cur, -cur);
                dfs(j + 1, path + '*' + ss, got - prev + cur * prev, cur * prev);
            }
        }
    }
};