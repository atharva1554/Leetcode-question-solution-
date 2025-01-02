//{ Driver Code Starts
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

void printList(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) {
        cout << "NULL";
    }
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}


// } Driver Code Ends
/*
structure of the node of the linked list is
struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// Function to merge two linked lists
class Solution {
  public:
    vector<Node*> mergeList(struct Node **head1, struct Node **head2) {
    // If either list is empty, return the original heads
    if (!(*head1)) return {nullptr, *head2};
    if (!(*head2)) return {*head1, nullptr};

    Node* curr1 = *head1;
    Node* curr2 = *head2;
    Node* next1 = nullptr;
    Node* next2 = nullptr;

    // Merge nodes from head2 into head1 at alternate positions
    while (curr1 && curr2) {
        // Save the next pointers
        next1 = curr1->next;
        next2 = curr2->next;

        // Insert curr2 into the first list
        curr1->next = curr2;
        curr2->next = next1;

        // Move to the next nodes in both lists
        curr1 = next1;
        curr2 = next2;
    }

    // At this point, curr2 points to the remaining nodes of the second list, if any
    *head2 = curr2;

    // Return the two modified heads in their original order
    return {*head1, *head2};
}

};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        vector<Node *> new_heads = obj.mergeList(&head1, &head2);
        printList(new_heads[0]);
        printList(new_heads[1]);
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends