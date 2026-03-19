
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
        for (int i = 0, j = m - 1; i < n; i++, j -= 4) {
            int avl = processorTime[i];

            maxi = max(maxi, avl + tasks[j]);
        }

        return maxi;
    }
};