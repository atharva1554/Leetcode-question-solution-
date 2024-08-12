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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* temp=head;
        ListNode* prev=temp;
        while(temp!=nullptr)
        {
            size++;
            temp=temp->next;
        }
        cout<<size;
        if(n>size)
        {
            return head;
        }
        int x=size-n;
        cout<<"x:"<<x<<endl;
        temp=head;
        if(x==0)
        {
            head=head->next;
            return head;
        }
        while(x--)
        {  prev=temp;
            temp=temp->next;
        } 
           prev->next=temp->next;
          cout<<temp->val<<endl;
        return head;
    }
};