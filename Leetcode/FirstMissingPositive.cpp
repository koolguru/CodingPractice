// Solution to Leetcode #41: Find the First Missing Postive Number in an Array
// Note this must be done in O(n) time and constant space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums.at(i) < 0 || nums.at(i) > nums.size())
            {
                nums.at(i) = 0;
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums.at(i) != 0)
            {
                if(nums.at(abs(nums.at(i))-1) == 0)
                {
                    // If the number at the index is 0, give it it's index value and set that to negative
                    nums.at(abs(nums.at(i)) - 1) = -1*abs(nums.at(i));
                }
                else
                {
                    // Set value at index to -1
                    nums.at(abs(nums.at(i))-1) = abs(nums.at(abs(nums.at(i))-1)) * -1;
                }
            }
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums.at(i) >= 0)
            {
                return i+1;
            }
        }
        return nums.size()+1;

    }
};
