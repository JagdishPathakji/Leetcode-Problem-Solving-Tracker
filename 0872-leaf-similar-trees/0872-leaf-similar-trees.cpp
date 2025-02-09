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

    void first(TreeNode *root, vector<int> &v1) {

        if(root == nullptr)
        return;

        if(root->left == nullptr and root->right == nullptr) 
        v1.push_back(root->val);
    
        first(root->left,v1);

        first(root->right,v1);

    }

    void second(TreeNode *root, vector<int> &v2) {

        if(root == nullptr)
        return;

        if(root->left == nullptr and root->right == nullptr)
        v2.push_back(root->val);

        second(root->left,v2);

        second(root->right,v2);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1;
        vector<int> v2;

        first(root1,v1);
        second(root2,v2);

        return (v1 == v2);
    }
};