// Solution to Leetcode #64 Minimum Path Sum
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(j != 0 && i != 0)
                {
                    grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
                }
                else if(j == 0 && i != 0)
                {
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                }
                else if(j != 0 && i == 0)
                {
                    grid[i][j] = grid[i][j-1] + grid[i][j];
                }
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
