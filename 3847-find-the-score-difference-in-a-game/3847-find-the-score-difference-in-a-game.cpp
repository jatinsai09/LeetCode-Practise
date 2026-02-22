class Solution {
public:
    int scoreDifference(vector<int>& a) {
        int n = a.size();
        int f[2] = {0}, p = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2) {
                p = 1 - p;
            }
            if ((i + 1) % 6 == 0) {
                p = 1 - p;
            } 
            f[p] += a[i];
        }

        return f[0] - f[1];
    }
};