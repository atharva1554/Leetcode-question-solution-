class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;  // If the list is empty or has only one element, return it as is
        }

        ListNode* odd = head;             // Initialize odd to the first node
        ListNode* even = head->next;      // Initialize even to the second node
        ListNode* evenHead = even;        // Keep the head of the even list to reconnect later

        while (even && even->next) {
            odd->next = even->next;       // Link odd nodes
            odd = odd->next;              // Move odd pointer to the next odd node
            even->next = odd->next;       // Link even nodes
            even = even->next;            // Move even pointer to the next even node
        }

        odd->next = evenHead;             // Connect odd list to the head of the even list
        return head;                      // Return the head of the modified list
    }
};
