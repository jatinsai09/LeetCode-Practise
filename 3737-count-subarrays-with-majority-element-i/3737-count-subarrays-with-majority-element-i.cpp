class Solution {
public:
    int countMajoritySubarrays(vector<int>& a, int target) {
        int res = 0, n = a.size();
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = i; j >= 0; j--) {
                c += (a[j] == target ? 1 : -1);
                res += (c > 0);
            }
        }
        return res;
    }
};