/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    using LNode = ListNode;
    using TNode = TreeNode;


    TNode *createBST(vector<int> &v, int start, int end) {
        
        if(start > end) {
            return nullptr;
        }
        
        int mid = start + (end - start)/2;
        TNode *root = new TNode(v[mid]);
        
        root->left = createBST(v,start,mid-1);
        
        root->right = createBST(v,mid+1,end);
        
        return root;
        
    }

    TreeNode* sortedListToBST(ListNode* head) {
        

        vector<int> v;
        LNode *curr = head;
        while(curr) {
            v.push_back(curr->val);
            curr = curr->next;
        }
        
        return createBST(v,0,v.size()-1);
                
    }
};