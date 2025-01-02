//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(NULL) {}
};

void append(Node*& head, Node*& tail, int new_data) {
    Node* new_node = new Node(new_data);
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}


// } Driver Code Ends
/* Link list Node

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

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        // Edge case: if head is null or k is 0
        if (!head || k <= 0) {
            return head;
        }

        // If k is 1, delete all nodes
        if (k == 1) {
            Node* temp = head;
            while (temp) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            return nullptr; // List is empty after deleting all nodes
        }

        // Initialize the current node and position counter
        Node* temp = head;
        Node* prev = nullptr;
        int count = 1;

        // Traverse the list and delete every k-th node
        while (temp != nullptr) {
            if (count % k == 0) {
                // Delete the k-th node
                if (prev != nullptr) {
                    prev->next = temp->next; // Skip the current node
                }
                Node* nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete; // Free memory
            } else {
                // Move to the next node
                prev = temp;
                temp = temp->next;
            }
            count++;
        }

        return head;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function */
int main() {

    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        Node* head = new Node(arr[0]);
        Node* tail = head;

        for (size_t i = 1; i < arr.size(); i++) {
            append(head, tail, arr[i]);
        }

        int K;
        cin >> K;
        cin.ignore(); // Ignore the newline after reading K

        Solution obj;
        Node* res = obj.deleteK(head, K);
        Node* temp = res;

        if (res == NULL) {
            cout << -1 << endl;
        } else {
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends