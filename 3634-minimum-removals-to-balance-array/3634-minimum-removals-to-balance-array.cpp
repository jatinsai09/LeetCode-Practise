class Solution {
public:
    //k * mn >= mx
    int minRemoval(vector<int>& a, int k) {
        int n = a.size();

        auto& b = a;
        int res = 0;

        sort(begin(b), end(b));
        for(int i = 0; i < n; i++) {
            int j = upper_bound(begin(b), end(b), (long long)k * b[i]) - begin(b);
            res = max(res, j - i);
        }
        return n - res;
    }
};