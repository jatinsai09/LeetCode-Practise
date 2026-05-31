class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        int n = a.size();
        sort(begin(a), end(a));

        long long cur = mass;
        for (auto &i: a) {
            if (cur < i) {
                return false;
            }
            cur += i;
        } 
        return true;
    }
};