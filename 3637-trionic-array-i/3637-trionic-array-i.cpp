class Solution {
public:
    bool isTrionic(vector<int>& a) {
        if (a[1] <= a[0]) {
            return 0;
        }
        
        int n = a.size(), slope = 1, c = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                return 0;
            }

            if (slope) {
                if (a[i] < a[i - 1]) {
                    slope = 1 - slope;
                    c++;
                }
            } else {
                if (a[i] > a[i - 1]) {
                    slope = 1 - slope;
                    c++;
                }
            }
        }
        return c == 3;
    }
};