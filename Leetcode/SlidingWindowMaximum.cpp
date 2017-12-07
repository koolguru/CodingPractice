class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int windowMin = 0;
        int windowMax = k-1;
        for(windowMax = k-1; windowMax < nums.size(); windowMax++)
        {

                int currentMax = nums.at(windowMin);
                int index = windowMin;
                for(int i = windowMin; i <= windowMax; i++)
                {
                    if(nums.at(i) > currentMax)
                    {
                        currentMax = nums.at(i);
                        index = i;
                    }
                }
                result.push_back(currentMax);
                windowMin++;
        }
        return result;
    }
};
