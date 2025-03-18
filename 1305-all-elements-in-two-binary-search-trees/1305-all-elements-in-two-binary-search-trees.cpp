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

        if(!root) return;

        find(root->left,v);
        v.push_back(root->val);
        find(root->right,v);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1,v2;

        find(root1,v1);
        find(root2,v2);

        int i=0;
        int j=0;

        vector<int> ans;

        while(i < v1.size() and j<v2.size()) {

            if(v1[i] <= v2[j]) {
                ans.push_back(v1[i]);
                i++;
            }
            else {
                ans.push_back(v2[j]);
                j++;
            }
        }

        while(i < v1.size()) {
            ans.push_back(v1[i]);
            i++;
        }

        while(j < v2.size()) {
            ans.push_back(v2[j]);
            j++;
        }

        return ans;

    }
};