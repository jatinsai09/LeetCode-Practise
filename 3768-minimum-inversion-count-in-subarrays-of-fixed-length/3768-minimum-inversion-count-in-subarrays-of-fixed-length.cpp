class Solution {
#define ll long long int
public:
    long long minInversionCount(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<int> bits(n + 1);

        vector<int> unq = nums;
        sort(begin(unq), end(unq));
        unq.erase(unique(begin(unq), end(unq)), end(unq));

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            int val =
                lower_bound(begin(unq), end(unq), nums[i]) - begin(unq) + 1;
            a[i] = val;
        }

        auto update = [&](int ind, int val) -> void {
            while (ind <= n) {
                bits[ind] += val;
                ind += (ind & -ind);
            }
        };

        auto query = [&](int ind) -> int {
            int sum = 0;
            while (ind > 0) {
                sum += bits[ind];
                ind -= (ind & -ind);
            }
            return sum;
        };

        ll cur = 0;
        for (int i = 0; i < k; i++) {
            cur += i - query(a[i]);
            update(a[i], 1);
        }

        ll res = cur;
        for (int i = k; i < n; i++) {
            {
                cur -= query(a[i - k] - 1);
                update(a[i - k], -1);
            }
            {
                cur += (k - 1) - query(a[i]);
                update(a[i], 1);
            }
            res = min(res, cur);
        }

        return res;
    }
};