//Serialize a Binary tree, and then deserialize it
//Use case: sending a tree over a server
//Solution to leetcode problem #297
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serialize(TreeNode* root, string& traversal)
    {
        if(root == nullptr)
        {
            traversal.push_back('#');
            return;
        }
        traversal.append(to_string(root->val) + ".");
        serialize(root->left, traversal);
        serialize(root->right, traversal);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string traversal = "";
        serialize(root, traversal);
        return traversal;
    }

    int valueParser(string& data) {
        int position = data.find('.');
        int value = stoi(data.substr(0, position));
        data = data.substr(position + 1);
        return value;
    }

    TreeNode* deserializeHelper(string& data)
    {
        if(data[0] == '#')
        {
            if(data.size() > 1)
            {
                data = data.substr(1);
            }
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(valueParser(data));
        newNode->left = deserializeHelper(data);
        newNode->right = deserializeHelper(data);
        return newNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        return deserializeHelper(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
