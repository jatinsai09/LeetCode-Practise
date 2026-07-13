class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), res = 0;

        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int sz = q.size();
            res++;

            while (sz--){
                int x = q.front();
                q.pop();
                for (int i = 1; i <= 6; i++) {
                    int y = x + i;
                    if (y > n * n) {
                        break;
                    }

                    int r = (y - 1) / n;
                    int c = (y - 1) % n;
                    int& dest =
                        board[n - r - 1][(r % 2 == 0 ? c : (n - c - 1))];
                    if (!dest) {
                        continue;
                    }
                    if (dest > 0) {
                        y = dest;
                    }
                    if (y == n * n) {
                        return res;
                    }
                    dest = 0;
                    q.push(y);
                }
            }
        }
        return -1;
    }
};