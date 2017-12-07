class Solution {
public:
    int numDecodings(string s) {
        vector<int> totals(s.size(), 0);
        if(s == "")
        {
            return 0;
        }
        if(s.at(0) != '0')
        {
            totals.at(0) = 1;
        }
        for(int i = 1; i < s.size(); i++)
        {
            if(s.at(i) != '0')
            {
                totals.at(i) = totals.at(i-1);
            }
            if(s.at(i-1) == '1' || (s.at(i-1) == '2') && (s.at(i) < '7'))
            {
                if(i == 1)
                {
                     totals.at(i) = totals.at(i) + 1;
                }
                else
                {
                    totals.at(i) = totals.at(i) + totals.at(i-2);
                }

            }
        }

        return totals.at(s.size()-1);
    }
};
