/* Note this code is directly from my leetcode, you will need to write a main */

class Solution {
public:
    void permute(vector<vector<int>>& results, vector<int>& nums,
	    vector<bool>& visited, vector<int>& current)
    {
        if(current.size() == nums.size())
        {
            results.push_back(current);
            return;
        }
        for(int i = 0; i < visited.size(); i++)
        {
            if(visited.at(i) == false)
            {
                visited.at(i) = true;
                current.push_back(nums.at(i));
                permute(results, nums, visited, current);
                current.pop_back();
                visited.at(i) = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<bool> visited(nums.size(), false);
        vector<int> current;

        for(int i = 0; i < nums.size(); i++)
        {
                visited.at(i) = true;
                current.push_back(nums.at(i));
                permute(results, nums, visited, current);
                current.pop_back();
                visited.at(i) = false;
        }
        return results;
    }
};
