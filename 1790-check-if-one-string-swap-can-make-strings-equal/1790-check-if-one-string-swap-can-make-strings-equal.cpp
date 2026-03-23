class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c = 0, i1 = -1, i2 = -1;
        int n = s1.size();

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                c++;
                if (c > 2) {
                    return false;
                }

                if (i1 == -1) {
                    i1 = i;
                } else {
                    i2 = i;
                }
            }
        }
        
        if (c == 0) {
            return true;
        } else if (c == 1) {
            return false;
        }
        return (s1[i1] == s2[i2] && s1[i2] == s2[i1]);
    }
};