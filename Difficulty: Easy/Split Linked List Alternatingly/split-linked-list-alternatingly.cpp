//{ Driver Code Starts
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


// } Driver Code Ends
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
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
    // Vector to store the heads of the two lists
    vector<Node*> ans;

    // Edge case: If the list is empty
    if (!head) {
        ans.push_back(nullptr);
        ans.push_back(nullptr);
        return ans;
    }

    // Dummy nodes for the two new lists
    Node* dummy1 = new Node(0); // Dummy node for the first list
    Node* dummy2 = new Node(0); // Dummy node for the second list

    Node* t1 = dummy1; // Pointer to the current node in the first list
    Node* t2 = dummy2; // Pointer to the current node in the second list
    Node* temp = head;

    int i = 0; // Counter to alternate between the lists

    while (temp) {
        if (i % 2 == 0) {
            t1->next = temp; // Add to the first list
            t1 = t1->next;   // Move to the next node in the first list
        } else {
            t2->next = temp; // Add to the second list
            t2 = t2->next;   // Move to the next node in the second list
        }
        temp = temp->next; // Move to the next node in the original list
        i++;
    }

    // Terminate the two new lists
    t1->next = nullptr;
    t2->next = nullptr;

    // Store the heads of the two new lists
    ans.push_back(dummy1->next);
    ans.push_back(dummy2->next);

    // Free the dummy nodes
    delete dummy1;
    delete dummy2;

    return ans;
}

};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends