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

    void find(TreeNode *root, int target, int sum, vector<int> temp, vector<vector<int>> &ans) {

        if(!root) return;

        if(!root->left and !root->right) {
            if(root->val+sum == target) {
                temp.push_back(root->val);
                ans.push_back(temp);
            }
        }
        else {
            temp.push_back(root->val);
            find(root->left,target,sum+root->val,temp,ans);
            find(root->right,target,sum+root->val,temp,ans); 
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        find(root,targetSum,sum,temp,ans);

        return ans;
    }
};