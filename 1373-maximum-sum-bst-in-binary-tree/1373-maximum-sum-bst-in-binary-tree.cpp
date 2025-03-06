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

using Node = TreeNode;

class Box {

public:   

    bool BST;
    int size;
    int max;
    int min;
    int sum;

    Box() {
        BST = 1;
        size = 0;
        min = INT_MAX;
        max = INT_MIN;
        sum = 0;
    }

};
class Solution {
public:
    
    Box *find(Node *root, int &Finalsum) {

        // if node doesn't exists
        if(!root) {
            return new Box();
        }

        // if node exists
        Box *lefthead = find(root->left,Finalsum);
        Box *righthead = find(root->right,Finalsum);

        if(lefthead->BST and righthead->BST and root->val > lefthead->max and root->val < righthead->min) {
            Box *head = new Box();
            head->size = 1 + lefthead->size + righthead->size;
            head->min = min(root->val,lefthead->min);
            head->max = max(root->val,righthead->max);
            head->sum = root->val + lefthead->sum + righthead->sum;
            Finalsum = max(Finalsum,head->sum);
            return head;
        }
        else {
            Box *head = new Box();
            head->BST = 0;
            return head;
        }
    }

    int maxSumBST(TreeNode* root) {

        int Finalsum = 0;
        find(root,Finalsum);
        
        return Finalsum;    
    }
};