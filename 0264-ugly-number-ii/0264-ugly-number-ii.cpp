class Solution {
public:
    int nthUglyNumber(int n) {
        long cur = 1;
        set<long> s = {1};

        for (int i = 0; i < n; i++) {
            cur = *s.begin();
            s.erase(begin(s));

            s.insert(cur * 2);
            s.insert(cur * 3);
            s.insert(cur * 5);
        }

        return cur;
    }
};