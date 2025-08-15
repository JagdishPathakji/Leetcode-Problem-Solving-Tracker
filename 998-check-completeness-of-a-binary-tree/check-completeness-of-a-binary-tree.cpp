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

    void find(TreeNode *root, int &size) {

        if(!root)
        return;

        size++;

        find(root->left,size);
        find(root->right,size);
    }

    void traverse(TreeNode *root, int index, int &size, bool &ans) {

        if(!root)
        return;

        if(!ans)
        return;

        if(index >= size) {
            ans = false;
            return;
        }

        traverse(root->left,2*index+1,size,ans);
        traverse(root->right,2*index+2,size,ans);
    }

    bool isCompleteTree(TreeNode* root) {
        
        int size = 0;
        find(root,size);

        int index = 0;
        bool ans = true;
        traverse(root,index,size,ans);

        return ans;
    }
};