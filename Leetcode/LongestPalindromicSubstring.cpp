// Solutions to Leetcode longestPalindromic substring
class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int left = 0;
        int right = 0;
        for(int i = 0; i < s.size();)
        {
            left = i;
            right = i;
            while(right < s.size()-1 && s.at(right+1) == s.at(i))
            {
                right++;
            }
            i = right+1;
            while(right < s.size()-1 && left > 0 && s.at(left-1) == s.at(right+1))
            {
                right++;
                left--;
            }
            if(result.size() < right-left+1)
            {
                result= s.substr(left, right-left+1);
            }
        }
        return result;
    }
};
