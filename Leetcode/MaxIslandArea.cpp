// Solution to Leetcode #695: Maximum Area of Island
class Solution {
public:
    int exploreIsland(vector<vector<int>>& grid, int row, int col)
    {
        int total = 1;
        grid[row][col] = 0;
        if(row > 0 && grid[row-1][col] == 1)
        {
            total = total + exploreIsland(grid, row-1, col);
        }
        if(row < grid.size()-1 && grid[row+1][col] == 1)
        {
            total = total + exploreIsland(grid, row+1, col);
        }
        if(col > 0 && grid[row][col-1] == 1)
        {
            total = total + exploreIsland(grid, row, col-1);
        }
        if(col < grid[row].size()-1 && grid[row][col+1] == 1)
        {
            total = total + exploreIsland(grid, row, col+1);
        }
        return total;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int maxArea = 0;
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[row].size(); col++)
            {
                if(grid[row][col] == 1)
                {
                    maxArea = max(maxArea, exploreIsland(grid, row, col));
                }
            }
        }
        return maxArea;
    }
};
