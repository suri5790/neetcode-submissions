class Solution {
public:
    bool valid(int i, int j, vector<vector<char>>& cur) {
        int n = cur.size();

        // check column
        for (int x = 0; x < n; x++) {
            if (cur[x][j] == 'Q') return false;
        }

        // top-left diagonal
        for (int x = i, y = j; x >= 0 && y >= 0; x--, y--) {
            if (cur[x][y] == 'Q') return false;
        }

        // top-right diagonal
        for (int x = i, y = j; x >= 0 && y < n; x--, y++) {
            if (cur[x][y] == 'Q') return false;
        }

        return true;
    }

    void f(int n, vector<vector<string>>& res, vector<vector<char>>& cur, int c) {
        if (c == n) {
            vector<string> board;
            for (int i = 0; i < n; i++) {
                board.push_back(string(cur[i].begin(), cur[i].end()));
            }
            res.push_back(board);
            return;
        }

        int i = c; // row
        for (int j = 0; j < n; j++) {
            if (valid(i, j, cur)) {
                cur[i][j] = 'Q';
                f(n, res, cur, c + 1);
                cur[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<char>> cur(n, vector<char>(n, '.'));
        f(n, res, cur, 0);
        return res;
    }
};