class Solution {
public:
    bool hasAlternatingBits(int n) {
        int got = n ^ (n >> 2);

        return (got & (got - 1)) == 0;
    }
};