class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> zeros(n);
        for (int i = 0; i < n; i++) {
            int ct = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                ct++;
            }
            zeros[i] = ct;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int req = n - i - 1;

            int j = i;
            while (j < n) {
                if (zeros[j] >= req) {
                    break;
                }
                j++;
            }
            if (j == n) {
                return -1;
            }

            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                j--;
                swaps++;
            }
        }

        return swaps;
    }
};