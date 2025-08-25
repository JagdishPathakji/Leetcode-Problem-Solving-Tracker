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
   
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)
        return 0;

        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        long long maxWidth = 0;
        while(!q.empty()) {

            int size = q.size();
            long long firstkaindex = q.front().second;
            long long lastkaindex = q.back().second;
            maxWidth = max(maxWidth,lastkaindex-firstkaindex+1);

            while(size--) {
                pair<TreeNode*,long long> node = q.front();
                q.pop();

                // to prevent overflow
                int currIdx = node.second - firstkaindex;

                if(node.first->left) {
                    q.push({node.first->left,currIdx * 1LL * 2+1});
                }
                if(node.first->right) {
                    q.push({node.first->right,currIdx * 1LL * 2+2});
                }
            }
        }   
        

        return maxWidth;
    }
};