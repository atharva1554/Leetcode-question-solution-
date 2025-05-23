//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {

  public:
    // Function to reverse the circular linked list
    Node* reverse(Node* head) {
        if (!head || !head->next || head->next == head) {
            return head; // Empty list or single node
        }

        Node *prev = NULL, *curr = head, *nextNode;

        do {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        } while (curr != head);

        // Fix the circular connection
        head->next = prev;
        head = prev;

        return head;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if (!head) {
            return NULL; // Empty list
        }

        Node *curr = head, *prev = NULL;

        // Handle the case where the head needs to be deleted
        if (head->data == key) {
            // Find the last node
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            // If there is only one node
            if (head->next == head) {
                delete head;
                return NULL;
            }

            // Update the head and adjust the last node's next pointer
            last->next = head->next;
            Node* newHead = head->next;
            delete head;
            return newHead;
        }

        // Traverse the list to find the node to delete
        do {
            prev = curr;
            curr = curr->next;

            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return head;
            }
        } while (curr != head);

        // If the key is not found, return the unchanged list
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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends