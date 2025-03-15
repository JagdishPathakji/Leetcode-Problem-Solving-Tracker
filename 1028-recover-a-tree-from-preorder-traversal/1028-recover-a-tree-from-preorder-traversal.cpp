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

    TreeNode* recoverFromPreorder(string traversal) {
        
        int num = 0;
        int i = 0;
        while(i < traversal.size() && isdigit(traversal[i])) {
            num = num * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode *root = new TreeNode(num);

        stack<TreeNode*> st;
        st.push(root);

        while(i < traversal.size()) {

            int count = 0;
            while(traversal[i] == '-') {
                count++;
                i++;
            }

            // Extract the full value (handles multi-digit values)
            int num = 0;
            while(i < traversal.size() && isdigit(traversal[i])) {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* newNode = new TreeNode(num);

            while(st.size() != count) {
                st.pop();
            }
                
            if(st.top()->left == nullptr) {
                st.top()->left = newNode;
            }
            else {
                st.top()->right = newNode;
            }
            
            st.push(newNode);
        }
       
        return root;
    }
};