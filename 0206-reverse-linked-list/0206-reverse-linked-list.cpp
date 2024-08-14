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
    ListNode* reverseList(ListNode* head) {
        stack<int>st;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        ListNode*dummy=new ListNode(-1);
        ListNode* dummyhead=dummy;
        while(!st.empty())
        {
            ListNode*a=new ListNode(st.top());
            st.pop();
            dummy->next=a;
            dummy=dummy->next;
        }
        return dummyhead->next;
    }
};