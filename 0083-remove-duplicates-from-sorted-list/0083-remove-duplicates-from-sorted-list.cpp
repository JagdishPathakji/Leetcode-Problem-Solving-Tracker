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
 using node = ListNode;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        // given an sorted list where i have to remove the duplicates and only one occurance of each should be present
        node *curr = head;
        node *prev = nullptr;

        while(curr) {
            if(prev and prev->val == curr->val) {
                prev->next = curr->next;
            }
            else {
                prev = curr;
            }
            
            if(curr)
            curr = curr->next; 
        }

        return head;
    }
};