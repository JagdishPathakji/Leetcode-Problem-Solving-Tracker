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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        int i=0;
        int j=0;

        node *curr1 = list1;
        node *curr2 = list1;
        while(i < a-1 and curr1) {
            curr1 = curr1->next;
            i++;
        }

        while(j < b+1 and curr2) {
            curr2 = curr2->next;
            j++;
        }

        node *tail = list2;
        while(tail->next)
        tail = tail->next;

        curr1->next = list2;
        tail->next = curr2;

        return list1;

    }
};