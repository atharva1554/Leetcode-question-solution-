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
    int getDecimalValue(ListNode* head) {
        vector<int>st;
        ListNode* node=head;
        while(node!=nullptr)
        {
            st.push_back(node->val);
            node=node->next;
        }
        int ans=0;
        int j=0;
        reverse(st.begin(),st.end());
        for(int i=0;i<st.size();i++)
        {
           ans=ans+(st[i]*pow(2,j));
           cout<<ans<<endl;
           j++;
        }
      return ans;
    }
};