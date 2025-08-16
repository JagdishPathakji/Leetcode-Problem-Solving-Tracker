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

    const int MOD = 1e9 + 7;
    int find(TreeNode *root) {

        if(!root)
        return 0;

        return root->val + find(root->left) + find(root->right);
    }

    long long int findmaxprod(TreeNode *root, long long int &ans, long long int &totalSum) {

        if(!root)
        return 0;

        int leftNode = findmaxprod(root->left,ans,totalSum);
        int rightNode = findmaxprod(root->right,ans,totalSum);
    
        long long int total = root->val + leftNode + rightNode;
        long long int prod = total * (totalSum - total);

        ans = max(ans,prod);
        return total;
    }


    int maxProduct(TreeNode* root) {
        
        long long int totalSum = find(root);

        long long int ans = 0;
        findmaxprod(root,ans,totalSum);

        return ans%(MOD);
    }
};