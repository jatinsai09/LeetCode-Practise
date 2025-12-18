class Solution {
public:
    long long maxProfit(vector<int>& p, vector<int>& s, int k) {
        int n = p.size();
        
        vector<long long> pre(n), p2(n);
        pre[0] = p[0] * s[0];
        p2[0] = p[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + p[i] * s[i];
            p2[i] = p2[i - 1] + p[i];
        }

        long long got, res = pre[n - 1], total = pre[n - 1];
        for(int i = k - 1; i < n; i++) {
            got = total - pre[i] + (i - k >= 0 ? pre[i - k] : 0);
            got += (p2[i] - p2[i - (k / 2)]);

            res = max(res, got);
        }

        return res;
    }
};