class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        int n = a.size();
        sort(begin(a), end(a));

        int cur = mass;
        for (auto &i: a) {
            if (cur < i) {
                return false;
            }
            if (cur >= 100000) {
                return true;
            }
            cur += i;
        } 
        return true;
    }
};