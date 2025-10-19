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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *head = new ListNode(0);
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>> > pq;

        for(int i=0; i<lists.size(); i++) {
            if(lists[i])
            pq.push({lists[i]->val,lists[i]});
        }

        ListNode *temp = nullptr;
        ListNode *dummyhead = head;
        while(!pq.empty()) {

            auto node = pq.top();
            pq.pop();

            temp = new ListNode(node.first);
            dummyhead->next = temp;
            dummyhead = dummyhead->next;

            if(node.second->next)
            pq.push({node.second->next->val,node.second->next});
        }

        return head->next;
    }
};