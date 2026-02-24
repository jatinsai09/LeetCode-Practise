class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;


        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i + 1});
        }

        int res = 0, mod = 1e9 + 7;
        for (int i = 1; i <= right; i++) {
            auto p = pq.top();
            pq.pop();
            
            if (i >= left) {
                res = (res + p.first) % mod;
            }

            if (p.second < n) {
                p.first += nums[p.second++];
                pq.push(p);
            }
        }
        return res;
    }
};