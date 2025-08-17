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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> children;

        for(int i=0; i<descriptions.size(); i++) {
            
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            bool isleft = descriptions[i][2];

            TreeNode *root;
            TreeNode *bacha;

            if(mp.find(parent) == mp.end()) {
                root = new TreeNode(parent);
                mp[parent] = root;
            }
            else {                
                root = mp[parent];
            }

            if(mp.find(child) == mp.end()) {
                bacha = new TreeNode(child);
                mp[child] = bacha;
            }
            else {
                bacha = mp[child];
            }

            children.insert(child);

            if(isleft) {
                root->left = bacha;
            }
            else {
                root->right = bacha;
            }
        }

        // return parent who is not children
        for(int i=0; i<descriptions.size(); i++) {
            if(children.find(descriptions[i][0]) == children.end())
            return mp[descriptions[i][0]];
        }

        return nullptr;
    }
};