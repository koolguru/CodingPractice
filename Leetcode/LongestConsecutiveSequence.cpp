// Solution to LC# 128 Longest Consecutive Sequence
// O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> numSet;
       for(int i = 0; i < nums.size(); i++) {
           numSet.insert(nums.at(i));
       }
       int max = 0;
       int currentCount = 0; 
       while(!numSet.empty()){
           currentCount = 1;
           int num = *(numSet.begin());
           int low = num - 1;
           numSet.erase(numSet.begin());
           while(numSet.find(low) != numSet.end()) {
               numSet.erase(numSet.find(low));
               currentCount++;
               low--;
           }
           int hi = num + 1;
           while(numSet.find(hi) != numSet.end()) {
               numSet.erase(numSet.find(hi));
               currentCount++;
               hi++;
           }
           if(currentCount > max) {
               max = currentCount;
           }
       }
       return max;
    }
};
