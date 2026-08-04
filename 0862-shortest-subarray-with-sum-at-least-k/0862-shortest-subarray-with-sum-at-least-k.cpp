class Solution {
public:
    int shortestSubarray(vector<int> nums, int k) {
        long n = nums.size(), res = n + 1;

        vector<long> ps(n);
        deque<long> dq;

        for (long i = 0; i < n; i++) {
            ps[i] = nums[i] + (i ? ps[i - 1] : 0);

            if (ps[i] >= k) {
                res = min(res, i + 1);
            }

            while (!dq.empty() && ps[i] - ps[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && ps[dq.back()] >= ps[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }

        return (res <= n ? res : -1);
    }
};