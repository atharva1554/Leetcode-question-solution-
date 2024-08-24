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
    ListNode*findnthnode(ListNode* head,int t)
    { int cnt=1;
        while(head!=nullptr)
        {  if(cnt==t)
        {
            return head;
        }
        cnt++;
            head=head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
         ListNode* tail=head;
         
          if(head==nullptr ||head->next==nullptr||k==0)
          {
            return head;
          }
          int len=1;
          while(tail->next!=nullptr)
          {
            len++;
            tail=tail->next;
          }
          if(k%len==0)
          {
            return head;
          }
         else
         {
            k=k%len;
            tail->next=head;
         }
         ListNode* newlastnode=findnthnode(head,len-k);
         head=newlastnode->next;
         newlastnode->next=nullptr;
        return head;
    }
};