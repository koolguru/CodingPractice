class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestLength = 0;
        int start = 0;
        unordered_map<char,int> charMap;
        for(int i = 0; i < s.size(); i++)
        {
            if(charMap.count(s.at(i)) == 0)
            {
                charMap[s.at(i)] = i;
            }
            else if(charMap[s.at(i)] == start)
            {
                start++;
            }
            else if(charMap[s.at(i)] > start)
            {
                start = charMap[s.at(i)]+1;
            }
            charMap[s.at(i)] = i;
            if(i-start+1 > longestLength)
            {
                longestLength = i-start+1;
            }
        }
        return longestLength;
    }
};
