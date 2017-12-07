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
        if(root == NULL)
        {
            return results;
        }
        queue<TreeNode*> queue;
        int comparisonsRemaining = 0;
        int currentMax = -2147483648;

        if(root->left != NULL)
        {
            queue.push(root->left);
            comparisonsRemaining++;
        }
        if(root->right != NULL)
        {
            queue.push(root->right);
            comparisonsRemaining++;
        }
        results.push_back(root->val);
        if(queue.empty())
        {
            return results;
        }

        while(!queue.empty())
        {
            if(comparisonsRemaining == 0)
            {
                comparisonsRemaining = queue.size();
                results.push_back(currentMax);
                currentMax = -2147483648;
            }
            else
            {
                root = queue.front();
                if(root->val > currentMax)
                {
                    currentMax = root->val;
                }
                comparisonsRemaining--;
                if(root->left != NULL)
                {
                    queue.push(root->left);
                }
                if(root->right != NULL)
                {
                    queue.push(root->right);
                }
                queue.pop();
            }
        }
        results.push_back(currentMax);
        return results;
    }
};
