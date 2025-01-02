//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int coeff;
    int pow;
    Node* next;

    Node(int c, int p)
        : coeff(c)
        , pow(p)
        , next(nullptr) {}
};

void append(Node*& head_ref, Node*& tail_ref, int new_data, int new_data1) {
    Node* new_node = new Node(new_data, new_data1);

    if (head_ref == nullptr)
        head_ref = new_node;
    else
        tail_ref->next = new_node;
    tail_ref = new_node;
}

void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->coeff << "x^" << temp->pow;
        if (temp->next != nullptr)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to add two polynomials represented as linked lists
    Node* addPolynomial(Node* head1, Node* head2) {
        // Initialize result list
        Node* result = NULL;
        Node* tail = NULL;

        // Traverse both linked lists until we reach the end of both
        while (head1 != NULL && head2 != NULL) {
            if (head1->pow == head2->pow) {
                // If exponents (powers) are equal, add the coefficients
                int sum = head1->coeff + head2->coeff;

                // Create a new node with the sum of coefficients
                Node* newNode = new Node(sum, head1->pow);

                // If result list is empty, initialize it
                if (result == NULL) {
                    result = newNode;
                    tail = result;
                } else {
                    // Otherwise, add the new node to the result list
                    tail->next = newNode;
                    tail = tail->next;
                }

                // Move both head pointers to the next node
                head1 = head1->next;
                head2 = head2->next;
            } else if (head1->pow > head2->pow) {
                // If exponent of first polynomial is greater, add that term
                Node* newNode = new Node(head1->coeff, head1->pow);

                // Add the new node to the result list
                if (result == NULL) {
                    result = newNode;
                    tail = result;
                } else {
                    tail->next = newNode;
                    tail = tail->next;
                }

                // Move the pointer of the first list
                head1 = head1->next;
            } else {
                // If exponent of second polynomial is greater, add that term
                Node* newNode = new Node(head2->coeff, head2->pow);

                // Add the new node to the result list
                if (result == NULL) {
                    result = newNode;
                    tail = result;
                } else {
                    tail->next = newNode;
                    tail = tail->next;
                }

                // Move the pointer of the second list
                head2 = head2->next;
            }
        }

        // If there are remaining terms in either list, add them
        while (head1 != NULL) {
            Node* newNode = new Node(head1->coeff, head1->pow);
            if (result == NULL) {
                result = newNode;
                tail = result;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
            head1 = head1->next;
        }

        while (head2 != NULL) {
            Node* newNode = new Node(head2->coeff, head2->pow);
            if (result == NULL) {
                result = newNode;
                tail = result;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
            head2 = head2->next;
        }

        return result;
    }
};



//{ Driver Code Starts.

/* Driver program to test above function */
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr1;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        Node *poly1 = nullptr, *poly2 = nullptr, *tail1 = nullptr, *tail2 = nullptr;
        int n = arr1.size();
        for (int i = 0; i < n; i += 2) {
            int x = arr1[i], y = arr1[i + 1];
            append(poly1, tail1, x, y);
        }

        vector<int> arr2;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss1(input);
        while (ss1 >> number) {
            arr2.push_back(number);
        }

        int m = arr2.size();
        for (int i = 0; i < m; i += 2) {
            int x = arr2[i], y = arr2[i + 1];
            append(poly2, tail2, x, y);
        }

        Solution obj;
        Node* sum = obj.addPolynomial(poly1, poly2);
        printList(sum);
    }

    return 0;
}

// } Driver Code Ends