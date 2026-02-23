class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int l = left, r = right;
        int sft = 0;
        while (l != r) {
            l >>= 1;
            r >>= 1;
            sft++;
        }
        return (l << sft);
    }
};