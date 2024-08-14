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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * a=headA;
        ListNode * b=headB;
        int x=0;
        int y=0;
        while(a!=nullptr)
        {
            a=a->next;
            x++;
        }

        while(b!=nullptr)
        {
            b=b->next;
            y++;
        }
        a=headA;
        b=headB;
        if(x>y)
        {
          while(x!=y)
          {
            a=a->next;
            x--;
          }
        }
        else
        {
            while(x!=y)
            {
                b=b->next;
                y--;
            }
        }
        while(a!=nullptr && b!=nullptr)
        {
            if(a==b)
            {
                return a;
            }
            a=a->next;
            b=b->next;
        }
        return nullptr;
    }
};