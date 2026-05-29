class Solution {
public:
    int sd(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int res = INT_MAX;

        for (auto &i: nums) {
            res = min(res, sd(i));
        }
        return res;
    }
};