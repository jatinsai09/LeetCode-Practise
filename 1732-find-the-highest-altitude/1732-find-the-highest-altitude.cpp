class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int maxi = 0, cur = 0;


        for (auto &g: gain) {
            cur += g;
            maxi = max(maxi, cur);
        }
        return maxi;
    }
};