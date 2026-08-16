class Solution {
public:
// ext * p == ref == q 
    int mirrorReflection(int p, int q) {
        int ext = 1, ref = 1;

        while (1) {
            if (ext * p == ref * q) {
                if ((ext & 1) || (ref & 1)) {
                    break;
                }
            } else if (ext * p < ref * q) {
                ext++;
            } else {
                ref++;
            }
        }

        if (ext % 2 == 0) {
            return 0;
        } else if (ref % 2 == 0) {
            return 2;
        } else {
            return 1;
        }
    }
};