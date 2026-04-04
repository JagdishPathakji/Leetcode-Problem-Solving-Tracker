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

    bool checksame(TreeNode *root, TreeNode *subroot) {

        if(!root && !subroot)
        return true;

        if(!root->left && subroot->left)
        return false;

        if(root->left && !subroot->left)
        return false;

        if(root->left && subroot->left && subroot->left->val != root->left->val)
        return false;

        if(!root->right && subroot->right)
        return false;

        if(root->right && !subroot->right)
        return false;

        if(root->right && subroot->right && subroot->right->val != root->right->val)
        return false;
        
        return checksame(root->left,subroot->left) && checksame(root->right,subroot->right);
    }

    void find(TreeNode *root, int &data, vector<TreeNode*> &v) {

        if(!root)
        return;

        if(root->val == data) {
            v.push_back(root);
        }

        find(root->left,data,v);
        find(root->right,data,v);
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        
        vector<TreeNode*> v;
        find(root,subroot->val,v);

        for(int i=0; i<v.size(); i++) {
            if(checksame(v[i],subroot))
            return true;
        }

        return false;
    }
};