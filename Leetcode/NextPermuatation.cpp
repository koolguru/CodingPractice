class Solution {
public:
    void swapAndSort(vector<int>& nums, int index)
    {
        //cout << "Got here" << endl;
        int min = 2147483647;
        int minIndex = -1;
        for(int i = index+1; i < nums.size(); i++)
        {
            if(nums.at(i) < min && nums.at(i) > nums.at(index))
            {
                min = nums.at(i);
                minIndex = i;
            }
        }
        //cout << "first: " << index << " min: " << minIndex << endl;
        std::iter_swap(nums.begin()+index, nums.begin()+minIndex);
        for(int i = 0; i < nums.size(); i++)
        {
            //cout << nums.at(i) << endl;
        }
        std::sort(nums.begin()+index+1, nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            //cout << nums.at(i) << endl;
        }


    }
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-2; i >= 0; i--)
        {
            if(nums.at(i) < nums.at(i+1))
            {
                swapAndSort(nums,i);
                return;
            }
        }
        std::sort(nums.begin(), nums.end());
    }
};
