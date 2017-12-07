class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numRed = 0;
        int numWhite = 0;
        int numBlue = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums.at(i) == 0)
            {
                numRed++;
            }
            else if(nums.at(i)  == 1)
            {
                numWhite++;
            }
            else
            {
                numBlue++;
            }
        }
        cout << numRed << " " << numWhite << endl;
        for(int i = 0; i < nums.size(); i++)
        {
            if(numRed > 0)
            {
                nums.at(i) = 0;
                numRed--;
            }
            else if(numWhite > 0)
            {
                nums.at(i) = 1;
                numWhite--;
            }
            else
            {
                nums.at(i) = 2;
                numBlue--;
            }
        }
    }
};
