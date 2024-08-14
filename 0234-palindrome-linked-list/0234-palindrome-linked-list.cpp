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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        vector<int>ans;
        while(temp!=nullptr)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n=ans.size();
        for(int i=0;i<n;i++)
        {
            if(ans[i]!=ans[n-i-1])
            {
                return false;
            }
        }
        return true;
    }
};