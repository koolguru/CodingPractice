// Solution for LC # 515: Find the largest value in each tree row
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> largestValues(TreeNode* root) {
        vector<int> results;
        if(root == NULL) {
            return results;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        int levelSize = 1;
        int currentMax = std::numeric_limits<int>::min();;
        while(!queue.empty()) {
            TreeNode* front = queue.front();
            queue.pop();
            levelSize--;
            if(front->left != NULL) {
                queue.push(front->left);
            }
            if(front->right != NULL) {
                queue.push(front->right);
            }
            if(front->val > currentMax) {
                currentMax = front->val;
            }
            if(levelSize == 0) {
                levelSize = queue.size();
                results.push_back(currentMax);
                currentMax = std::numeric_limits<int>::min();;
            }
        }
        return results;
    }
};
