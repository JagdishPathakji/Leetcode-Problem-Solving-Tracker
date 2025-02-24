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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;

        while(root) {

            if(root->left == nullptr) {
                ans.push_back(root->val);
                root = root->right;
            }
            else {

                TreeNode *curr = root->left;
                while(curr->right and curr->right != root) {
                    curr = curr->right;
                }

                if(curr->right == nullptr) {
                    curr->right = root;
                    root = root->left;
                }
                if(curr->right == root) {
                    curr->right = nullptr;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }

        return ans;
    }
};