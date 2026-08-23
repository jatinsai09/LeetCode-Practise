class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), mx = 0;

        for (const auto &i: nums) {
            mx = max(mx, i);
        }

        vector<int> spf(mx + 1);
        for (int i = 2; i <= mx; i++) {
            if (spf[i] == 0) {
                for (int j = i; j <= mx; j += i) {
                    if (spf[j] == 0) {
                        spf[j] = i;
                    } 
                }
            }
        }

        vector<vector<int>> pf(n);
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            vector<int> primes;
            while (x > 1) {
                int p = spf[x];
                primes.push_back(p);

                while (x % p == 0) {
                    x /= p;
                }
            }

            pf[i] = primes;
        }
        

        unordered_map<int, int> f;

        int unq = 0, res = 0;
        for (int l = 0, r = 0; r < n; r++) {
            for (auto &p: pf[r]) {
                if (++f[p] == 1) {
                    unq++;
                }
            }

            while (unq > k) {
                for (auto &p: pf[l]) {
                    if (--f[p] == 0) {
                        unq--;
                    }
                }
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};