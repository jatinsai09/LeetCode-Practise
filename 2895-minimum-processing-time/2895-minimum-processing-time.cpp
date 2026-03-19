
class Solution {
#define sort(a) sort(begin(a), end(a))
#define ll long long int
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(processorTime);
        sort(tasks);

        int n = processorTime.size(), m = 4 * n, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            int mn = processorTime[i];
            int k = (m - 1) - (4 * i);
            for (int j = 0; j < 4; j++) {
                maxi = max(maxi, mn + tasks[k - j]);
            }
        }
        
        return maxi;
    }
};