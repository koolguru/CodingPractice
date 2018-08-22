class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                minOpen++;
                maxOpen++;
            }
            if(s[i] == '*') {
                minOpen--;
                maxOpen++;
            }
            if(s[i] == ')') {
                minOpen--;
                maxOpen--;
            }
            if(maxOpen < 0) {
                return false;
            }
            if(minOpen < 0) {
                minOpen = 0;
            }
        }
        return minOpen == 0;
    }
};
