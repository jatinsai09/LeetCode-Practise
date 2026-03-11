class Solution {
public:
    int bitwiseComplement(int n) {
        int msk = 1;
        while (msk < n) {
            msk = (msk << 1) + 1;
        }

        return msk ^ n;
    }
};