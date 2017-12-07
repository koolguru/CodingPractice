class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> numPaths(m,vector<int>(n,1));
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                numPaths.at(i).at(j) = numPaths.at(i-1).at(j) +
				numPaths.at(i).at(j-1);
            }
        }
        return numPaths.at(m-1).at(n-1);

    }
};
