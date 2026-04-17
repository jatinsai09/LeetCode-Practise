class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        reverse(begin(num), end(num));

        int i = 0, got;
        while (i < n || k) {
            if (i < n) {
                got = num[i] + (k % 10);
                
                num[i] = got % 10;
                k = k / 10 + got / 10; 

                i++;
            } else {
                num.push_back(k % 10);
                k /= 10;
            }
        }

        reverse(begin(num), end(num));
        return num;
    }
};