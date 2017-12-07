class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> counts;
        for(int i = 0; i < nums.size(); i++)
        {
            //cout << nums.at(i) << endl;
            if(counts.count(nums.at(i))==0)
            {
                //cout << "Added: " << nums.at(i) << endl;
                counts[nums.at(i)] = 1;
            }
            if(counts[nums.at(i)] == 2)
            {
                //cout << "Removed: " << nums.at(i) << endl;
                counts.erase(nums.at(i));
            }
            else
            {
                counts[nums.at(i)]++;
            }
        }
        vector<int> results;
        results.push_back(counts.begin()->first);
        auto it = counts.begin();
        it++;
        results.push_back((it)->first);
        return results;
    }
};
