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
    
    void find(TreeNode *root, vector<int> &v) {

        if(!root)
        return;

        v.push_back(root->val);

        find(root->left,v);
        find(root->right,v);

    }
  
    int findSecondMinimumValue(TreeNode* root) {
        
        if(root == nullptr) {
            return -1;
        }

        vector<int> v;
        find(root,v);
        sort(v.begin(),v.end());

        for(int i=1; i<v.size(); i++) {
            if(v[i] != v[0]) {
                return v[i];
            }
        }

        return -1;
    }
};