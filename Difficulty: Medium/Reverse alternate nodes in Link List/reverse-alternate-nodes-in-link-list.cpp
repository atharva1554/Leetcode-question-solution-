//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* A linked list node */
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void insert(Node*& start, const vector<int>& arr) {
    Node* temp;
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0) {
            start = new Node(arr[i]);
            temp = start;
        } else {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
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
class Solution {
  public:
    void rearrange(Node* head) {
        if (!head || !head->next) {
            return; // If the list has 0 or 1 nodes, no rearrangement is needed
        }

        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;

        // Separate odd and even nodes
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = NULL; // End the odd list

        // Reverse the even list
        Node* prev = NULL;
        Node* curr = evenHead;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Append the reversed even list to the end of the odd list
        odd->next = prev;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore newline after t input

    while (t--) {
        vector<int> arr;
        string input;

        // Read the array of linked list elements
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* start = NULL;
        insert(start, arr);

        Solution ob;
        ob.rearrange(start);
        printList(start);

        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends