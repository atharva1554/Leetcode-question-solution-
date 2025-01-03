//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *head) {
    if (head == NULL)
        return;

    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\n";
}


// } Driver Code Ends
/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }

};
 */

// This function should return head of
// the modified list
class Solution {
  public:
   Node* sortedInsert(Node* head, int data) {
    Node* newNode = new Node(data);

    // Case 1: Empty list
    if (!head) {
        newNode->next = newNode;  // The new node points to itself
        return newNode;
    }

    Node* curr = head;

    // Case 2: Insert before the head (new smallest node)
    if (data <= head->data) {
        // Find the last node to update its next pointer
        while (curr->next != head) {
            curr = curr->next;
        }
        newNode->next = head;
        curr->next = newNode;
        return newNode;  // New node becomes the new head
    }

    // Case 3: Insert in the middle or at the end
    while (curr->next != head && curr->next->data < data) {
        curr = curr->next;
    }

    // Insert the new node
    newNode->next = curr->next;
    curr->next = newNode;

    return head;  // Head remains unchanged
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        Node *head = new Node(arr[0]);
        Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make it circular
        Solution ob;
        Node *ans = ob.sortedInsert(head, x);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends