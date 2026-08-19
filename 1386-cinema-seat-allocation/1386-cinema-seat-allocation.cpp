class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(begin(reservedSeats), end(reservedSeats));
        int m = reservedSeats.size(), res = n * 2;

        for (int i = 0; i < m;) {
            res -= 2;
            vector<int> vis(11, 1);

            int j = i;
            while (j < m) {
               if (reservedSeats[i][0] != reservedSeats[j][0]) {
                break;
               }

               vis[reservedSeats[j][1]] = 0;
               j++;
            }

            for (int i = 1; i <= 10; i++) {
                if (vis[i]) {
                    vis[i] += vis[i - 1];
                }
            }

            int has1 = (vis[5] >= 4 | vis[7] >= 4 | vis[9] >= 4);
            int has2 = (vis[9] >= 8);

            if (has2) {
                res += 2;
            }  else if (has1) {
                res++;
            }

            i = j;
        }

        return res;
    }
};