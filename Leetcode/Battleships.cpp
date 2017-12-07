class Solution {
public:
    void exploreBattleShip(vector<vector<char>>& board, int x, int y, int dir)
    {
        board.at(x).at(y) = '.';
        if(dir == 0)
        {
            if(x < board.size()-1)
            {
                if(board.at(x+1).at(y) == 'X')
                {
                    dir = 1;
                }
            }
            if(y < board.at(x).size()-1)
            {
                if(board.at(x).at(y+1) == 'X')
                {
                    dir = 2;
                }
            }
        }
        if(dir == 1)
        {
            if(x < board.size()-1)
            {
                if(board.at(x+1).at(y) == 'X')
                {
                    exploreBattleShip(board,x+1,y,dir);
                }
            }
        }
        else if(dir == 2)
        {
            if(y < board.at(x).size()-1)
            {
                if(board.at(x).at(y+1) == 'X')
                {
                    exploreBattleShip(board,x,y+1,dir);
                }
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board.at(i).size(); j++)
            {
                if(board.at(i).at(j) == 'X')
                {
                    count++;
                    exploreBattleShip(board,i,j,0);
                }
            }
        }
        return count;
    }
};
