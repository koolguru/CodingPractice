/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.size() == 0)
        {
            return result;
        }
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b)
			{return a.start < b.start;});
        result.push_back(intervals.at(0));
        for(int i = 1; i < intervals.size(); i++)
        {
            if(result.at(result.size()-1).end >= intervals.at(i).start)
            {
                result.at(result.size()-1).end =
			max(intervals.at(i).end,
				result.at(result.size()-1).end);
            }
            else
            {
                result.push_back(intervals.at(i));
            }
        }
        return result;
    }
};
