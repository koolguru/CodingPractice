class Solution {
public:
    void generatePair(vector<string>& results, string str, int right, int left)
    {
        if(right == 0 && left == 0)
        {
            results.push_back(str);
            return;
        }
        if(left > 0)
        {
            generatePair(results, str+")", right,left-1);
        }
        if(right > 0)
        {
            generatePair(results, str+"(", right-1,left+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        generatePair(results, "", n,0);
        return results;
    }
};
