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

    void makeserialize(TreeNode *root, ostringstream &ans) {

        if(!root) return;
        ans << root->val << ',';
        makeserialize(root->left,ans);
        makeserialize(root->right,ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        ostringstream ans;
        makeserialize(root,ans);
        return ans.str();
    }

    TreeNode *deserialising(string data, int &index, int min, int max) {
        
        if (index >= data.size()) return nullptr;

        // Extract the next number from the string
        int start = index;
        while (index < data.size() && data[index] != ',') {
            index++;
        }

        int num = stoi(data.substr(start, index - start));
        index++; // Move past ','

        // **Key Fix: If num is out of range, reset index and return nullptr**
        if (num < min || num > max) {
            index = start; // Roll back index so that parent node can process correctly
            return nullptr;
        }

        TreeNode* root = new TreeNode(num);
        root->left = deserialising(data, index, min, num);
        root->right = deserialising(data, index, num, max);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int index = 0;
        return deserialising(data,index,INT_MIN,INT_MAX);
           
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;