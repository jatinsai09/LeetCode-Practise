class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), len = word.size();

        function<bool(int, int, int)> backtrack = [&](int r, int c, int i) -> bool {
            if (i == len) {
                return true;
            }
            if (r < 0 || r == m || c < 0 || c == n || board[r][c] != word[i]) {
                return false;
            }

            char og = board[r][c];
            board[r][c] = '*';
            if (backtrack(r + 1, c, i + 1) || backtrack(r - 1, c, i + 1) ||
                backtrack(r, c + 1, i + 1) || backtrack(r, c - 1, i + 1)) {
                return true;
            }
            board[r][c] = og;
            return false;
        };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (backtrack(r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};