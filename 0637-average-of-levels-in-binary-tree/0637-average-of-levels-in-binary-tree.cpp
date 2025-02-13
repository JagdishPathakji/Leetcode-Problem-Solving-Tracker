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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> v;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int k = q.size();
            double sum = 0;
            int count = 0;
            
            while(k--) {
                TreeNode *temp = q.front();
                q.pop();

                sum = sum + temp->val;
                count++;

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);

            }

            v.push_back(sum/count);
        }

        return v;
    }
};