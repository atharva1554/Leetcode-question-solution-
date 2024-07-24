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
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode*temp=head;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        int k=cnt/2;
        int x=0;
        ListNode *t=head;
        while(x<k)
        {
           x++;
        t=t->next;
        }
        return t;
    }
};