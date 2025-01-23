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
    ListNode* mergeNodes(ListNode* head) {

        using node = ListNode;
        node *curr = head->next;
        int sum = 0;
        node *HEAD = new node(0);
        node *CURR = HEAD;

        while(curr) {
            if(curr->val == 0) {
                node *temp = new node(sum);
                CURR->next = temp;
                CURR = temp;
                sum = 0;        
            }
            else {
                sum = sum + curr->val;
            }
            curr = curr->next;
        }

        return HEAD->next;
    }
};