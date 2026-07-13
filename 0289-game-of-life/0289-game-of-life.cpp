class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> cur = board;
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int ln = LiveNeighbours(cur, i, j, m, n);
                if (board[i][j]) {
                    if (ln < 2 || ln > 3) {
                        board[i][j] = 0;
                    }
                } 
                else {
                    if (ln == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
    int LiveNeighbours(vector<vector<int>>& cur, int i, int j, int m, int n) {
        int ln = 0;

        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                if (di == 0 && dj == 0) {
                    continue;
                } else {
                    if (i + di >= 0 && i + di < m && j + dj >= 0 &&
                        j + dj < n) {
                        if (cur[i + di][j + dj] == 1) {
                            ln++;
                        }
                    }
                }
            }
        }
        return ln;
    }
};