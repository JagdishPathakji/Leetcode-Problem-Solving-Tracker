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
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
    
        using node = ListNode;
        node *curr = head;
        node *prev = nullptr;
        
        while(curr) {
            node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;

        node *h1 = nullptr;
        node *t1 = h1;

        curr = head;

        int carry = 0;
        while(curr) {
            int num = (curr->val * 2) + carry;
            carry = num/10;
            int rem = num%10;

            node *temp = new node(rem);
            if(h1 == nullptr) {
                h1 = temp;
            }
            else {
                temp->next = h1;
                h1 = temp;
            }

            curr = curr->next;
        }

        if(carry) {
            node *temp = new node(carry);
            temp->next = h1;
            h1 = temp;
        }
        return h1;
    }
};