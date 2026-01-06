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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode *> q;
        q.push(root);
        int ans = INT_MIN;
        int index = 0;
        int ansindex = 0;

        if(root == nullptr) 
        return {};

        while(!q.empty()) {
            
            int sum = 0;
            int k = q.size();
            index++;

            while(k--) {

                TreeNode *temp = q.front();
                q.pop();

                sum = sum + temp->val;

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);

            }

            if(ans < sum) {
                ans = sum;
                ansindex = index;
            }
        }
        
        return ansindex;
    }
};