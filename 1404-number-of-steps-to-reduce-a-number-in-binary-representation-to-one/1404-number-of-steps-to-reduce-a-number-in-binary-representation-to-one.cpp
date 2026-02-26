class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), c1 = 0, c0 = 0, s0 = 0;
        for (auto &c: s) {
            if (c == '1') {
                c1++;
                s0 = 0;
            } else {
                s0++;
                c0++;
            }
        }

        if (c1 == 1) {
            return n - 1;
        }
    
        return n + (c0 - s0) + 1;
    }
};