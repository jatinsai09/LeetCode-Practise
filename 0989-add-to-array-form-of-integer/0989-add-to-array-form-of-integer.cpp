class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(begin(num), end(num));

        int i = 0, got;
        while (i < num.size() || k) {
            if (i < num.size()) {
                got = num[i] + (k % 10);
                num[i] = got % 10;
                k = k / 10 + got / 10; 
            } else {
                num.push_back(k % 10);
                k /= 10;
            }
            i++;
        }

        reverse(begin(num), end(num));
        return num;
    }
};