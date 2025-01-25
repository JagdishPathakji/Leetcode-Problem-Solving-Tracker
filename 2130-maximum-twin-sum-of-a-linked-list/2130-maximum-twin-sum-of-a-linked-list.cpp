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
    int pairSum(ListNode* head) {
        
        using node = ListNode;
        node *curr = head;
        node *nxt = head->next;

        if(nxt->next == NULL) {
            return (curr->val + nxt->val);
        }

        vector<int> v;
        while(curr) {
            v.push_back(curr->val);
            curr = curr->next;
        }

        int i = 0;
        int j = v.size()-1;

        int sum = 0;
        while(i < j) {
            sum = max(sum,v[i]+v[j]);
            i++;
            j--;
        }

        return sum;
    }
};