class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        int i1 = -1, i2 = -1;
        int n = s1.size();

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (i2 != -1) {
                    return false;
                }

                if (i1 == -1) {
                    i1 = i;
                } else {
                    i2 = i;
                }
            }
        }
        
        if (i2 == -1) {
            return i1 == -1;
        }

        return (s1[i1] == s2[i2] && s1[i2] == s2[i1]);
    }
};