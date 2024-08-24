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
        ListNode* temp=head;
        map<ListNode* ,int>mpp;
        while(temp!=NULL)
        {
         mpp[temp]++;
         if(mpp[temp]>1)
         {
            return true;
         }
         temp=temp->next;
        }
        return false;
    }
};