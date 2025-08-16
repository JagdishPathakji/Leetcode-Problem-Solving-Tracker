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

using node = TreeNode;
class Solution {
public:

    TreeNode *find(TreeNode *root, int val, int currdepth, int depth) {

        if(!root)
        return nullptr;

        if(currdepth+1 == depth) {
            TreeNode *leftNode = new TreeNode(val);
            TreeNode *rightNode = new TreeNode(val);

            leftNode->left = root->left;
            rightNode->right = root->right;

            root->left = leftNode;
            root->right = rightNode;

            return root;
        }

        root->left = find(root->left,val,currdepth+1,depth);
        root->right = find(root->right,val,currdepth+1,depth);
    
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1) {
            TreeNode *newnode = new TreeNode(val);
            newnode->left = root;
            return newnode;
        }

        return find(root,val,1,depth);
    }
};