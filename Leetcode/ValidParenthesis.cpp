class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        unordered_map<char,char> parens;
        parens['['] = ']';
        parens['{'] = '}';
        parens['('] = ')';
        parens['}'] = '{';
        parens[']'] = '[';
        parens[')'] = '(';
        for(int i = 0; i < s.size(); i++)
        {
            if(s.at(i) == ']' || s.at(i) == '}' || s.at(i) == ')')
            {
                if(brackets.empty())
                {
                    return false;
                }
                if(brackets.top() != parens[s.at(i)])
                {
                    return false;
                }
                brackets.pop();
            }
            else
            {
                brackets.push(s.at(i));
            }
        }
        if(brackets.empty())
        {
            return true;
        }
        return false;
    }
};
