// Solution to LC # 130 Surrounded Regions
class Solution {
public:
    bool isBorder(vector<vector<char>>& board, int row, int col) {
        if(row == 0 || row == board.size() - 1) {
            return true;
        }
        if(col == 0 || col == board[row].size() - 1) {
            return true;
        }
        return false;

    }
    void exploreSurrounded(vector<vector<char>>& board, int row, int col) {
        if((row >= 0 && row < board.size()) && (col >= 0 && col < board[0].size()) && board[row][col] == 'O') {
            board[row][col] = '*';
            exploreSurrounded(board, row, col + 1);
            exploreSurrounded(board, row + 1, col);
            exploreSurrounded(board, row - 1, col);
            exploreSurrounded(board, row, col - 1);
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.at(i).size(); j++) {
                if(board[i][j] == 'O' && isBorder(board, i, j)) {
                    exploreSurrounded(board, i, j);
                }
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == '*') {
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
