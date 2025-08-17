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
    
    string find(TreeNode *root, unordered_map<string,int> &mp, vector<TreeNode*> &ans) {

        if(!root) {
            return "N";
        }
 
        string value = to_string(root->val) + "," + find(root->left,mp,ans) + "," + find(root->right,mp,ans);

        if(mp.find(value) == mp.end()) {
            mp[value] = 1;
        }
        else if(mp[value] == 1) {
            ans.push_back(root);
            mp[value]++;
        }

        return value;
    }
  
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> ans;
        unordered_map<string,int> mp;

        find(root,mp,ans);
        return ans;
    }
};