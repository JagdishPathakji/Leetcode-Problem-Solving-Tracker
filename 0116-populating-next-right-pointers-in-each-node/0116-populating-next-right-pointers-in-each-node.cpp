/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node *> q;
        q.push(root);
        
        if(root == nullptr) 
        return root;
        
        while(!q.empty()) {
            
            int k = q.size();
            
            while(k--) {
                
                Node *temp = q.front();
                q.pop();
                
                if(k == 0) {
                    temp->next = nullptr;    
                }
                else if(k > 0) {
                    temp->next = q.front();
                }
            
                if(temp->left)
                q.push(temp->left);
            
                if(temp->right)
                q.push(temp->right);
                
            }
        }
        
        return root;

    }
};