class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        unordered_set<int> di;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (di.count(j) || strs[i][j] == strs[i - 1][j]) {
                    continue;
                }
                if (strs[i][j] < strs[i - 1][j]) {
                    di.insert(j);
                    i = 0;
                }
                break;
            }
        }

        return (int)di.size();
    }
};