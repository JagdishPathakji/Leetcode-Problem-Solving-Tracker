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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == nullptr) {
            return {};
        }

        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        int count = 0;
        while(!q.empty()) {

            int k = q.size();
            ans.push_back(vector<int>());
            while(k--) {

                TreeNode *temp = q.front();
                q.pop();
                
                ans.back().push_back(temp->val);
                // Left to right
                if(count%2 == 1) {
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
                // Right to left
                else {
                    if(temp->right) q.push(temp->right);
                    if(temp->left) q.push(temp->left);
                }

            }

            count++;
        
        }

        return ans;
    }
};