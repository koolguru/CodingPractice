// Solution to Leetcode #48: Rotate Image
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int maxLayers = matrix.size()/2-1;
        int currLayer = 0;
        while(currLayer <= maxLayers)
        {
            for(int j = currLayer; j < matrix.size() - currLayer - 1; j++)
            {
                int val1 = matrix[currLayer][j];
                int val2 = matrix[j][matrix.size() - 1 - currLayer];
                int val3 = matrix[matrix.size() - currLayer - 1][matrix.size() - j - 1];
                int val4 = matrix[matrix.size() - 1 - j][currLayer];

                matrix[currLayer][j] = val4;
                matrix[j][matrix.size() - 1 - currLayer] = val1;
                matrix[matrix.size() - currLayer - 1][matrix.size() - j - 1] = val2;
                matrix[matrix.size() - 1 - j][currLayer] = val3;
            }
            currLayer++;
        }
    }
};
