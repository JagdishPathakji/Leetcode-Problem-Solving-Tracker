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

    int find(vector<int> &inorder, int element, int  start, int end) {

        for(int i = start; i<=end; i++) {
            if(element == inorder[i])
            return i;
        }

        // never became true
        return -1;
    }

    TreeNode* MakeTree(vector<int> &postorder, vector<int> &inorder, int start, int end, int index) {

        if(start > end)
        return nullptr;

        TreeNode *root = new TreeNode(postorder[index]);
        int pos = find(inorder,postorder[index],start,end);

        root->left = MakeTree(postorder,inorder,start,pos-1,index-1-(end-pos));
        root->right = MakeTree(postorder,inorder,pos+1,end,index-1); 

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return MakeTree(postorder,inorder,0,inorder.size()-1,inorder.size()-1);
    }
};