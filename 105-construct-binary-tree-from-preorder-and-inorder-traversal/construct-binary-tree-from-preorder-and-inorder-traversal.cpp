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

    int find(vector<int> &inorder, int element, int start, int end) {

        for(int i=start; i<=end; i++) {
            if(element == inorder[i])
            return i;
        }

        // never becames true
        return -1;
    }

    TreeNode* MakeTree(vector<int> &preorder, vector<int> &inorder, int start, int end, int index) {

        if(start > end)
        return nullptr;

        TreeNode *root = new TreeNode(preorder[index]);
        int pos = find(inorder,preorder[index],start,end);

        root->left = MakeTree(preorder,inorder,start,pos-1,index+1); 
        root->right = MakeTree(preorder,inorder,pos+1,end,index+(pos-start)+1);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        // start from 0 index because 0 index element is the root node if preorder traversal is given
        return MakeTree(preorder,inorder,0,preorder.size()-1,0);
    }
};