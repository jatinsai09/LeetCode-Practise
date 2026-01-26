class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        sort(begin(arr), end(arr));

        vector<vector<int>> res;
        int mdif = INT_MAX, n = arr.size();
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == mdif) {
                res.push_back({arr[i - 1], arr[i]});
            } else if (arr[i] - arr[i - 1] < mdif) {
                res = {{arr[i - 1], arr[i]}};
                mdif = arr[i] - arr[i - 1];
            }
        }
        return res;
    }
};