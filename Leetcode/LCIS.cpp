class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        if(nums.size() == 1)
        {
            return 1;
        }
        int startLoc = 0;
        int endLoc = 0;
        int longestLength = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums.at(i) > nums.at(i-1))
            {
                endLoc = i;
            }
            else
            {
                startLoc = i;
                endLoc = i;
            }
            if(endLoc - startLoc + 1 > longestLength)
            {
                longestLength = endLoc - startLoc + 1;
            }
        }
        return longestLength;
    }
};
