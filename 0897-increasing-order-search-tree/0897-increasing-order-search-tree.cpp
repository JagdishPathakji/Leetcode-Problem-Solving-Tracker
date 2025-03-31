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

    void find(TreeNode *root, TreeNode *&head, TreeNode *&prev) {

        if(!root) return;

        find(root->left,head,prev);
        if(prev == nullptr) {
            head = root;
        }
        else {
            prev->right = root;
        }

        prev = root;
        root->left = nullptr;
        
        find(root->right,head,prev);

    }

    TreeNode* increasingBST(TreeNode* root) {

        TreeNode *head = nullptr;
        TreeNode *prev = nullptr;
        find(root,head,prev);

        return head;
    }

};