class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount,
                        vector<vector<int>>& queries) {
        int q = queries.size(), n = candiesCount.size();
        vector<bool> res(q);
        vector<long long> pre(n + 1);

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + candiesCount[i];
        }

        for (int i = 0; i < q; i++) {
            long long ind = queries[i][0], favDay = queries[i][1],
                dailyCap = queries[i][2];
            long long p = pre[ind + 1], prev = pre[ind];

            long long r = p - 1, l = prev / dailyCap;
            if (l <= favDay && r >= favDay) {
                res[i] = true;
            } else {
                res[i] = false;
            }
        }

        return res;
    }
};