class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for (const auto& i: nums) {
            if (i >= a) {
                b = a;
                a = i;
            } else if(i > b) {
                b = i;
            }
        }

        return (a - 1) * (b - 1);
    }
};