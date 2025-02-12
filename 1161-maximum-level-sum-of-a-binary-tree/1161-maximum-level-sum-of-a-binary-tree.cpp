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
        vector<int> ans;

        if(root == nullptr) 
        return {};

        while(!q.empty()) {
            
            int sum = 0;
            int k = q.size();

            while(k--) {

                TreeNode *temp = q.front();
                q.pop();

                sum = sum + temp->val;

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);

            }

            ans.push_back(sum);
        }

        int max = 0;
        for(int i=0; i<ans.size(); i++) {
            if(ans[max] < ans[i]) {
                max = i;
            }
        }

        return (max + 1);
    }
};