class Solution {
public:
    int getLiveNeighbours(vector<vector<int>>& curr, int i, int j, int m,
                          int n) {
        int liveNeighbours = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0)
                    continue; // skip the current cell
                int ni = i + dx, nj = j + dy;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (curr[ni][nj] == 1 || curr[ni][nj] == 3)
                        liveNeighbours++;
                }
            }
        }
        return liveNeighbours;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num = getLiveNeighbours(board, i, j, m, n);
                if (board[i][j] == 0) {
                    if (num == 3) {
                        board[i][j] = 2;
                    }
                } else if (board[i][j] == 1) {
                    if (num < 2 || num > 3) {
                        board[i][j] = 3;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 1;
                else if (board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }
};