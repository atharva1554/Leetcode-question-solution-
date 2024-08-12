//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    // Function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;
        
        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    // Function to add one to the number represented by the linked list
    Node* addOne(Node* head) {
        // Reverse the linked list
        head = reverseList(head);
        
        // Add 1 to the reversed list
        Node* temp = head;
        int carry = 1; // Initial carry is 1 since we are adding one
        
        while (temp != NULL) {
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;
            
            // If there's no carry left, break out of the loop
            if (carry == 0) break;
            
            // If this is the last node and there's still a carry
            if (temp->next == NULL && carry > 0) {
                temp->next = new Node(carry);
                carry = 0; // Reset carry since it's handled
            }
            temp = temp->next;
        }
        
        // Reverse the list back to original order
        head = reverseList(head);
        
        return head;
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

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends