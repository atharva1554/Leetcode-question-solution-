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
        int cnt=0;
         ListNode* temp=head;
         while(temp!=nullptr)
         {
            cnt++;
            temp=temp->next;
         }
        int x = cnt - n;
        
        // Special case: if the head needs to be removed
        if (x == 0) {
            ListNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return head;
        }
        
        // Traverse to the node just before the one to remove
        temp = head;
        for (int i = 1; i < x; i++) {
            temp = temp->next;
        }
        
        // Remove the nth node from the end
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        
        return head;
    }
};