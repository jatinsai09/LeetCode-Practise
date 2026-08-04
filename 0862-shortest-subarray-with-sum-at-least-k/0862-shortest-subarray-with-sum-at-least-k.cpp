class Solution {
public:
    int shortestSubarray(vector<int> nums, int k) {
        long n = nums.size(), res = n + 1;

        vector<long> ps(n);
        deque<long> dq;

        ps[0] = nums[0];
        for (long i = 0; i < n; i++) {
            if (i) {
                ps[i] += nums[i] + ps[i - 1];
            } 

            if (ps[i] >= k) {
                res = min(res, i + 1);
            }

            while (!dq.empty() && ps[i] - ps[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && ps[i] <= ps[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return (res <= n ? res : -1);
    }
};