class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        stack<int> p, n;
        int l = arr.size();

        vector<int> nse(l), psse(l);
        for (int i = l - 1; i >= 0; i--) {
            while (!n.empty() && arr[n.top()] >= arr[i]) {
                n.pop();
            }
            nse[i] = n.empty() ? l : n.top();
            n.push(i);
        }
        for (int i = 0; i < l; i++) {
            while (!p.empty() && arr[p.top()] > arr[i]) {
                p.pop();
            }
            psse[i] = p.empty() ? -1 : p.top();
            p.push(i);
        }

        long long res = 0, mod = 1e9 + 7;
        for (int i = 0; i < l; i++) {
            int left = i - psse[i], right = nse[i] - i;
            long long c = (left * right) % mod;

            res += (1LL * arr[i] * c) % mod;
            res %= mod;
        }
        return (int)res;
    }
};