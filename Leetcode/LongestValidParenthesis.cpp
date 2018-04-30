// Solution to Leetcode #32 Longest Valid Parentheses
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> parens;
        parens.push(-1);
        int valid = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                parens.push(i);
            }
            else
            {
                parens.pop();
                if(parens.empty())
                {
                    parens.push(i);
                }
                else
                {
                    valid = max(valid, i - parens.top());
                }
            }
        }
        return valid;
    }
};
