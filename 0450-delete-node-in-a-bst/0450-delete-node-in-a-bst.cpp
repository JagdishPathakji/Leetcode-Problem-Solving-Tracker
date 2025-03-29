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

    TreeNode *find(TreeNode *&root, int key) {

        if(!root) return nullptr;

        if(root->val == key) {

            if(!root->left and root->right) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if(!root->right and root->left) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->right and !root->left) {
                delete root;
                return nullptr;
            }
            else {

                TreeNode *child = root->left;
                TreeNode *parent = root;
                while(child->right) {
                    parent = child;
                    child = child->right;
                }

                if(parent != root) {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
                else {
                    child->right = parent->right;
                    delete root;
                    return child;
                }
            }
        }
        else if(root->val < key) {
            root->right = find(root->right,key);
            return root;
        }
        else {
            root->left = find(root->left,key);
            return root;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(!root) return nullptr;

        root = find(root,key);
        return root;

    }
};