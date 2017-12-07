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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](const Interval& i1, const Interval& i2){
	 return i1.start < i2.start; };
        sort(intervals.begin(), intervals.end(), comp);
        int current = 0;
        int count = 0;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals.at(i).start < intervals.at(current).end)
            {
                count++;
                if(intervals.at(i).end < intervals.at(current).end)
                {
                    current = i;
                }
            }
                            else
                {
                    current  = i;
                }
        }
        return count;
    }
};
