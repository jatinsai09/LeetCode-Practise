class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;

        while (n) {
            res++;
            n = n & (n - 1); // sets the righmost set bit to zero
        }

        return res;
        // Brain Kernighan algorithm
    }
};