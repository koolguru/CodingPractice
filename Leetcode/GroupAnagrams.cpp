// Solution to Leetcode #49
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stringMap;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            stringMap[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto m : stringMap) {
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};
