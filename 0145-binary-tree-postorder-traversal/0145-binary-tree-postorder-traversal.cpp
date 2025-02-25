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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> v;

        while(root) {

            if(root->right == nullptr) {
                v.push_back(root->val);
                root = root->left;
            }
            else {

                TreeNode *curr = root->right;
                while(curr->left and curr->left != root) {
                    curr = curr->left;
                }

                if(curr->left == nullptr) {
                    v.push_back(root->val);
                    curr->left = root;
                    root = root->right;
                }
                if(curr->left == root) {
                    curr->left = nullptr;
                    root = root->left;
                }
            }
        }

        reverse(v.begin(),v.end());
        return v;

    }
};