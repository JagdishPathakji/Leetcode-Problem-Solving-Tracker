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

    TreeNode* makeBST(TreeNode* root, vector<int> &preorder, int index) {

        if(root == nullptr) return new TreeNode(preorder[index]);

        if(root->val < preorder[index]) {
            root->right = makeBST(root->right,preorder,index);
        }
        else {
            root->left = makeBST(root->left,preorder,index);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode *root = nullptr;

        for(int i=0; i<preorder.size(); i++) {
            root = makeBST(root,preorder,i);
        }

        return root;
    }
};