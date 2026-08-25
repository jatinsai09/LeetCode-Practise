class Solution {
public:
    int missingMultiple(vector<int>& a, int k) {
        vector<int> f(102);
        for (const auto &i:a){
            if(i % k == 0) {
                f[i / k]++;
            }
        }

        for (int i = 1; i <= 101; i++) {
            if(f[i] == 0) {
                return i * k;
            }
        }
        return 0;
    }
};