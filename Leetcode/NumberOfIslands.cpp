class Solution {
public:
    void exploreIsland(vector<vector<char>>& grid, int row, int col)
    {
        grid.at(row).at(col) = '0';
        if(row < grid.size()-1)
        {
            if(grid.at(row+1).at(col) == '1')
            {
                exploreIsland(grid, row+1, col);
            }
        }
        if(row > 0)
        {
            if(grid.at(row-1).at(col) == '1')
            {
                exploreIsland(grid, row-1, col);
            }
        }
        if(col < grid.at(row).size()-1)
        {
            if(grid.at(row).at(col+1) == '1')
            {
                exploreIsland(grid, row, col+1);
            }
        }
        if(col > 0)
        {
            if(grid.at(row).at(col-1) == '1')
            {
                exploreIsland(grid, row, col-1);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid.at(row).size(); col++)
            {
                if(grid.at(row).at(col) == '1')
                {
                    count++;
                    exploreIsland(grid, row, col);
                }
            }
        }
        return count;
    }
};
