class Solution {
#define ll long long int
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = arrivalTime.size(), m = lights.size();
    
        ll mx = lights[0];
        for (const auto &i: lights) {
            mx = max(mx, 1LL * i);
        }
        
        ll rem, res = 0;
        for (int i = 0; i < n; i++) {
            rem = arrivalTime[i] % period;

            if (rem >= mx) {
                res = max(res, period - rem);
            }
        }

        return res;
    }
};