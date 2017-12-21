//Solution to Leetcode #540
class Solution {
public:
    int find(vector<int>& nums, int l, int r)
    {
        if (r >= l)
        {
            int mid = l + (r - l)/2;

            if(mid > 0 && mid < nums.size()-1)
            {
                if (nums.at(mid+1) != nums.at(mid) && nums.at(mid-1) != nums.at(mid))  return mid;
            }
            else if(mid == nums.size()-1)
            {
                if (nums.at(mid-1) != nums.at(mid))  return mid;
            }
            else if(mid == 0)
            {
                if (nums.at(mid+1) != nums.at(mid))  return mid;
            }
            if(find(nums, l, mid-1) != -1)
            {
                return find(nums, l, mid-1);
            }
            return find(nums, mid+1, r);
        }

        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        return nums.at(find(nums,0,nums.size()-1));
    }
};
