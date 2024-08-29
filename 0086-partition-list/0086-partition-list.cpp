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
    ListNode* partition(ListNode* head, int x) {
        vector<int>l;
        vector<int>s;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            if(temp->val>=x)
            {
                  l.push_back(temp->val);
            }
            else
            {
                s.push_back(temp->val);
            }
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<s.size();i++)
        {
            temp->val=s[i];
            temp=temp->next;
        }
        for(int i=0;i<l.size();i++)
        {
             temp->val=l[i];
               temp=temp->next;
        }
        return head;
    }
};