// Solution to Leetcode #41: Find the First Missing Postive Number in an Array
// Note this must be done in O(n) time and constant space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums.at(i) <= 0 || nums.at(i) > nums.size())
            {
                nums.at(i) = 1;
            }
            else if (nums.at(i) == 1) {
                nums.at(0) = -1 * abs(nums.at(0));
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            int num = abs(nums.at(i));
            if(num > 0 && num != 1)
            {
                nums.at(num - 1) = -1 * abs(nums.at(num - 1));
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums.at(i) > 0 || nums.at(i) == 0) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
