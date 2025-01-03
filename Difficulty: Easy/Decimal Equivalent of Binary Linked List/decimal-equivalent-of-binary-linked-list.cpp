//{ Driver Code Starts

#include <bits/stdc++.h>
#include <map>
using namespace std;

const long long unsigned int MOD = 1000000007;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution {
  public:
    // Should return decimal equivalent modulo 1000000007 of binary linked list
    long long unsigned int decimalValue(Node *head) {
        long long unsigned int result = 0;
        const long long MOD = 1e9 + 7;  // Use modulo to avoid overflow

        // Traverse the linked list
        while (head != nullptr) {
            result = (result * 2 + head->data) % MOD; // Shift left and add current node's data, modulo
            head = head->next; // Move to the next node
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t input

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

        if (arr.empty()) {
            cout << -1 << endl; // handle empty input
            continue;
        }

        // Create linked list from the input array
        Node* head = new Node(arr[0]);
        Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Node* failure = new Node(-1);
        Solution obj;

        cout << obj.decimalValue(head) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends