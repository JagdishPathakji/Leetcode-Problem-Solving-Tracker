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

    void find(TreeNode *root, vector<TreeNode*> &v) {

        if(!root)
        return;

        v.push_back(root);

        find(root->left,v);

        find(root->right,v);
    }

    void flatten(TreeNode* root) {
        
        if(!root)
        return;
        
        vector<TreeNode*> v;

        find(root,v);

        for(int i=0; i<v.size()-1; i++) {
            v[i]->right = v[i+1];
            v[i]->left = nullptr;
        }
        
    }
};