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
    pair<int,int> find(TreeNode *root, int &maxi) {

        if(!root)
        return make_pair(-1,-1);

        if(!root->left && !root->right)
        return make_pair(root->val,root->val);
    
        auto left = find(root->left,maxi);
        auto right = find(root->right,maxi);

        int leftmin = left.first;
        int leftmax = left.second;
        int rightmin = right.first;
        int rightmax = right.second;

        if(leftmin != -1)
        maxi = max(maxi,abs(root->val-leftmin));
        
        if(rightmin != -1)
        maxi = max(maxi,abs(root->val-rightmin));
        
        if(leftmax != -1)
        maxi = max(maxi,abs(root->val-leftmax));
        
        if(rightmax != -1)
        maxi = max(maxi,abs(root->val-rightmax));

        int minimum = min({root->val,leftmin == -1 ? INT_MAX : leftmin, leftmax == -1 ? INT_MAX : leftmax, rightmin == -1 ? INT_MAX : rightmin, rightmax == -1 ? INT_MAX : rightmax});

        int maximum = max({root->val,leftmin == -1 ? INT_MIN : leftmin, leftmax == -1 ? INT_MIN : leftmax, rightmin == -1 ? INT_MIN : rightmin, rightmax == -1 ? INT_MIN : rightmax});
        
        return make_pair(minimum,maximum);
    }

    int maxAncestorDiff(TreeNode* root) {
        
        int maxi = 0;
        find(root,maxi);

        return maxi;
    }
};