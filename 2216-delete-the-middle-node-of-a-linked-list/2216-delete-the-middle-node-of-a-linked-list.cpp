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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            cnt++;
            temp=temp->next;
        }
        ListNode* prev=head;
        ListNode*t=head;
        for(int i=0;i<cnt/2;i++)
        {
            prev=t;
            t=t->next;
        }
        if(cnt==1)
        {
            return nullptr;
        }
        prev->next=t->next;
        t->next=nullptr;
        return head;
    }
};