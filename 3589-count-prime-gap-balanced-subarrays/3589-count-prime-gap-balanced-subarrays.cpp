class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> isPrime;
        for (const auto& x : nums) {
            bool prime = 1;
            if (x == 1) {
                isPrime.push_back(0);
                continue;
            }

            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    prime = 0;
                    break;
                }
            }
            isPrime.push_back(prime);
        }

        deque<int> q;
        multiset<int> s;
        int res = 0;
        for (int l = 0, r = 0; r < n; r++) {
            if (isPrime[r]) {
                s.insert(nums[r]);
                q.push_back(r);
            }

            while (!s.empty() && *s.rbegin() - *s.begin() > k) {
                if (isPrime[l]) {
                    s.erase(s.find(nums[l]));
                    q.pop_front();
                }
                l++;
            }

            if (q.size() >= 2) {
                int i1 = q.back(); q.pop_back();

                int i2 = q.back();
                res += (i2 - l + 1);

                q.push_back(i1);
            }
        }

        return res;
    }
};