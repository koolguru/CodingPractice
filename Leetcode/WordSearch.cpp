// Solution to Leetcode #79: Word Search
class Solution {
public:
    bool exist(vector<vector<char>>& board, string& word, int index, int row, int col)
    {
        if(index == word.size() - 1)
        {
            return true;
        }
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;
        char restore = board[row][col];
        board[row][col] = '0';
        if(row+1 < board.size())
        {
            if(board[row+1][col] != '0' && board[row+1][col] == word.at(index+1))
            {
                down = exist(board, word, index+1, row+1, col);
            }
        }
        if(!down && row-1 >= 0)
        {
            if(board[row-1][col] != '0' && board[row-1][col] == word.at(index+1))
            {
                up = exist(board, word, index+1, row-1, col);
            }
        }
        if(!down && !up && col-1 >= 0)
        {
            if(board[row][col-1] != '0' && board[row][col-1] == word.at(index+1))
            {
                right =  exist(board, word, index+1, row, col-1);
            }
        }
        if(!down && !up && !right && col+1 < board.at(row).size())
        {
            if(board[row][col+1] != '0' && board[row][col+1] == word.at(index+1))
            {
                left = exist(board, word, index+1, row, col+1);
            }
        }
        board[row][col] = restore;
        return up || down || right || left;
    }
    bool exist(vector<vector<char>>& board, string& word) {
        if(word.size() > board.size()*board.at(0).size())
        {
            return false;
        }
        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board.at(row).size(); col++)
            {
                if(board[row][col] == word[0])
                {
                    if(exist(board,word,0,row,col) == true)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
