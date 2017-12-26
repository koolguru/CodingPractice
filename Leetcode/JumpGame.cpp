// Solution to Leetcode #55
// Goal is to check if the end of the vector can be reached
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > maxReach)
            {
                return false;
            }
            maxReach = max(i + nums.at(i), maxReach);

        }
        return true;
    }
};
