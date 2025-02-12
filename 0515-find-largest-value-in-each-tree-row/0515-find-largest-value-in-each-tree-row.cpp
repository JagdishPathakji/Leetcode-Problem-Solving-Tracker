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
    vector<int> largestValues(TreeNode* root) {
        
        queue<TreeNode *> q;
        q.push(root);
        vector<int> ans;

        if(root == nullptr) 
        return {};

        while(!q.empty()) {
            
            vector<int> v;
            int k = q.size();

            while(k--) {

                TreeNode *temp = q.front();
                q.pop();

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);

                v.push_back(temp->val);
            }

            int max = INT_MIN;
            for(int i=0; i<v.size(); i++) {
                if(max < v[i]) {
                    max = v[i];
                }
            }

            ans.push_back(max);
        }

        return ans;
    }
};