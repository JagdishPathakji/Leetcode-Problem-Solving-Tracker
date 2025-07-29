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
class FindElements {
public:
    TreeNode *ans = nullptr;
    TreeNode* recover(TreeNode *root) {

        if(!root) return nullptr;

        if(root->left) {
            root->left->val = root->val * 2 + 1;
            recover(root->left);
        }
        if(root->right) {
            root->right->val = root->val * 2 + 2;
            recover(root->right);
        }

        return root;
    }

    FindElements(TreeNode* root) {
        ans = root;
        ans->val = 0;
        ans = recover(ans);
    }
    
    bool found(TreeNode *ans, int target) {

        if(ans == nullptr)
        return false;

        if(ans->val == target)
        return true;

        return found(ans->left,target) || found(ans->right,target);
    }

    bool find(int target) {

        return found(ans,target);    
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */