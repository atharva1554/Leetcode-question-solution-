//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// A node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node at the end of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // Allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // Since we are adding at the end, next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // Change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // Forward traversal
    if (head == NULL)
        return;

    DLLNode *last = NULL;
    while (head != NULL) {
        cout << head->data << " ";
        last = head;
        head = head->next;
    }
    cout << "\n";

    // Backward traversal
    while (last != NULL) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << "\n";
}


// } Driver Code Ends

/* Structure of the node of the list is as
class DLLNode {
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    DLLNode *sortDoubly(DLLNode *head) {
        // Your code here
        vector<int>a;
        DLLNode*temp=head;
        while(temp)
        {
            a.push_back(temp->data);
            temp=temp->next;
        }
        temp=head;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
        {
            temp->data=a[i];
            temp=temp->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

// Driver code
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "List is empty.\n";
            continue;
        }

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }

        Solution ob;
        head = ob.sortDoubly(head);

        printList(head);
    }
    return 0;
}

// } Driver Code Ends