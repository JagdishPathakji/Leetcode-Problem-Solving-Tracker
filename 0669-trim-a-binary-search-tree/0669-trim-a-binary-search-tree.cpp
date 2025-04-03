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

    TreeNode *find(TreeNode *&root, int low, int high) {

        if(!root) return nullptr;
        
        root->right = find(root->right,low,high);
        root->left = find(root->left,low,high);
        
        if(root->val < low or root->val > high) {

            // if no child exists
            if(!root->left and !root->right) {
                return nullptr;
            }
            // if only left child exists
            else if(root->left and !root->right) {
                TreeNode *temp = root->left;
                return temp;
            }
            // if only right child exists
            else if(root->right and !root->left) {
                TreeNode *temp = root->right;
                return temp;
            }
            // if both left and right child exists
            else {
                TreeNode *child = root->left;
                TreeNode *parent = root;
                while(child->right) {
                    parent = child;
                    child = child->right;
                }

                if(parent == root) {
                    child->right = parent->right;
                    return child;
                }
                else {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    return child;
                }

            }
        }

        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        return find(root,low,high);
    }
};