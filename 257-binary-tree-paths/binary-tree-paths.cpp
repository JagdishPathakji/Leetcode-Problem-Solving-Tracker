/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void traverse(TreeNode *root, string temp, vector<string> &ans) {

        if(!root) 
        return;

        temp += to_string(root->val);
        temp += "->";
        
        if(!root->left && !root->right) {
            temp = temp.substr(0,temp.size()-2);
            ans.push_back(temp);
            return;
        }

        traverse(root->left,temp,ans);
        traverse(root->right,temp,ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        string temp = "";

        traverse(root,temp,ans);

        return ans;
    }
};