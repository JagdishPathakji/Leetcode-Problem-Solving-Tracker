/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_map<ListNode*,bool> mp;

        ListNode *curr = head;
        while(curr) {
            if(mp.find(curr) != mp.end())
            return true;

            mp[curr] = true;
            curr = curr->next;
        } 

        return false;
    }
};