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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);

        int count = 0;
        while(!q.empty()) {

            vector<int> odd;
            vector<int> even;
            int k = q.size();
            
            while(k--) {

                TreeNode *temp = q.front();
                q.pop();

                if(count%2 == 0) {
                    if(temp->val % 2 == 0) {
                        return false;
                    }
                    odd.push_back(temp->val);
                }
                else {
                    if(temp->val % 2 == 1) {
                        return false;
                    }
                    even.push_back(temp->val);
                }

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }

            if(odd.size() != 0) {

                for(int i=0; i<odd.size()-1; i++) {
                    if(odd[i] >= odd[i+1]) {
                        return false;
                    }
                }
            }
            else if(even.size() != 0) {

                for(int i=0; i<even.size()-1; i++) {
                    if(even[i] <= even[i+1]) {
                        return false;
                    }
                }
            }
            count++;
        }

        return true;
    }
};