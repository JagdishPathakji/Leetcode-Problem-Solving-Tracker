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

    TreeNode* invertTree(TreeNode* root) {
        
        if(root == nullptr)
        return nullptr;

        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // O(n) time and space complexity

        if(!p and !q)
        return true;
        
        if(!p and q)
        return false;
        
        if(p and !q)
        return false;

        if(p->val != q->val)
        return false;
    
        return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);

    }

    bool isSymmetric(TreeNode* root) {
        
        TreeNode *rootleft = root->left;
        TreeNode *rootright = root->right;

        rootright = invertTree(rootright);
        return isSameTree(rootleft,rootright);
    }
};