//Solution to LC # 238 Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products;
        products.reserve(nums.size());
        products.push_back(1);
        for(int i = 1; i < nums.size(); i++) {
            products.push_back(products.at(i-1) * nums.at(i-1));
        }
        int right = nums.at(nums.size() - 1);
        for(int i = nums.size() - 2; i >= 0; i--) {
            products.at(i) = products.at(i) * right;
            right = right * nums.at(i);
        }
        return products;
    }
};
