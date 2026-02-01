class Solution {
public:
    int countMonobit(int n) {
        int res = 1;
        res += (int)log2(n + 1);

        return res;
    }
};