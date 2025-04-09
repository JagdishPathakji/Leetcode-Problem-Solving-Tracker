/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(!head) return nullptr;

        vector<Node*> ans;
        stack<Node*> st;

        st.push(head);

        while(!st.empty()) {

            Node *temp = st.top();
            st.pop();

            ans.push_back(temp);

            if(temp->next)
            st.push(temp->next);
            if(temp->child) {
                st.push(temp->child);
                temp->child = nullptr;
            }

        }

        Node *Head = new Node(0);
        Node *Tail = Head;
        for(int i=0; i<ans.size(); i++) {
            Tail->next = ans[i];
            ans[i]->prev = Tail;
            Tail = ans[i];
        }

        Head->next->prev = nullptr;
        return Head->next;
    }
};