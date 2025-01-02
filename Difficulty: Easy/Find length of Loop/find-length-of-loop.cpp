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

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        if (!head || !head->next) {
            return 0;  // No loop possible if the list is empty or has only one node
        }
        
        Node *slow = head;
        Node *fast = head;

        // Step 1: Detect if there's a loop using Floyd's Cycle-Finding Algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;         // Move slow pointer by 1 step
            fast = fast->next->next;   // Move fast pointer by 2 steps
            
            if (slow == fast) {
                // Step 2: Loop detected, now count the number of nodes in the loop
                int loopLength = 1;   // We know there's at least 1 node in the loop
                Node *temp = slow->next;
                while (temp != slow) {
                    temp = temp->next;
                    loopLength++;
                }
                return loopLength;
            }
        }
        
        // No loop found
        return 0;
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
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        cout << ob.countNodesinLoop(head) << endl;
    }
    return 0;
}

// } Driver Code Ends