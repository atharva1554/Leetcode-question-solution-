//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* root) {
    Node* temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
        // Step 1: Reverse the linked list
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next;  // Save the next node
            curr->next = prev;  // Reverse the current node's pointer
            prev = curr;        // Move prev to current
            curr = next;        // Move to the next node
        }
        
        head = prev;  // Set head to the new head of the reversed list
        
        // Step 2: Traverse the reversed list and remove nodes
        Node* maxNode = head;
        Node* temp = head;
        
        while (temp != nullptr && temp->next != nullptr) {
            // If the next node's value is smaller than the current max node's value, remove it
            if (temp->next->data < maxNode->data) {
                temp->next = temp->next->next;
            } else {
                // Update maxNode to the next node if it's larger
                maxNode = temp->next;
                temp = temp->next;
            }
        }
        
        // Step 3: Reverse the list back to its original order
        prev = nullptr;
        curr = head;
        
        while (curr != nullptr) {
            next = curr->next;  // Save the next node
            curr->next = prev;  // Reverse the current node's pointer
            prev = curr;        // Move prev to current
            curr = next;        // Move to the next node
        }
        
        head = prev;  // Set head to the new head of the reversed list
        
        return head;  // Return the modified list
    }
};



//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }
        Solution ob;
        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Node* result = ob.compute(head);
        print(result);
        cout << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends