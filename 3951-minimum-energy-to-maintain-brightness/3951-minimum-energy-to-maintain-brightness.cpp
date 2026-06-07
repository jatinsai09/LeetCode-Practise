class Solution {
#define ll long long int
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        
        sort(begin(intervals), end(intervals));
        int req = (brightness + 2) / 3;

        ll res = intervals[0][1] - intervals[0][0] + 1;
        int mx = intervals[0][1];
        for (auto &i: intervals) {
            if (i[1] > mx) {
                res += i[1] - max(i[0] - 1, mx);
                mx = i[1];
            }
        }

        return res * req;
    }
};