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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        ListNode* temp1=temp;
        int x=0;
        while(x<a-1)
        {   temp1=temp;
            temp=temp->next;
            x++;
        }
        temp1=temp->next;
        temp->next=list2;
        ListNode* temp2=list2;
        while(temp2->next!=nullptr)
        {
            temp2=temp2->next;
        }
        while(x!=b)
        {  temp1=temp1->next;
            x++;
        }
        temp2->next=temp1;
        return list1;
    }
};