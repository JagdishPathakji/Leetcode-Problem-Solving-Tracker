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
    long long mod = 1e9 + 7;
    void findSum(TreeNode *root, long long &sum) {

        if(!root)
        return;

        sum += root->val;
        findSum(root->left,sum);
        findSum(root->right,sum);
    }

    long long findAns(TreeNode *root,long long &sum, long long &ans) {

        if(!root)
        return 0;

        long long left = findAns(root->left,sum,ans);
        long long right = findAns(root->right,sum,ans);
    
        long long subtreesum = left + right + root->val;
        long long mult = ((subtreesum)*(sum-subtreesum));
        ans = max(ans,mult);

        return subtreesum;
    }

    int maxProduct(TreeNode* root) {

        long long ans = 0;
        long long sum = 0;
        findSum(root,sum);

        findAns(root,sum,ans);

        return ans%mod;
    }

};