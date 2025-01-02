//{ Driver Code Starts
#include <iostream>

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

vector<int> take() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    return arr;
}

Node* inputList(int size, vector<int> v) {
    if (size == 0)
        return NULL;

    int val = v[0];

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++) {
        val = v[i + 1];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
public:
    // Function to find intersection point in Y shaped Linked Lists.
    Node* intersectPoint(Node* head1, Node* head2) {
        // Calculate the lengths of both linked lists
        int len1 = 0, len2 = 0;
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while (temp1) {
            len1++;
            temp1 = temp1->next;
        }
        
        while (temp2) {
            len2++;
            temp2 = temp2->next;
        }
        
        // Calculate the difference in lengths
        int diff = abs(len1 - len2);
        
        // Align the starting points of both lists
        temp1 = head1;
        temp2 = head2;
        
        if (len1 > len2) {
            for (int i = 0; i < diff; i++) {
                temp1 = temp1->next;
            }
        } else {
            for (int i = 0; i < diff; i++) {
                temp2 = temp2->next;
            }
        }
        
        // Traverse both lists to find the intersection point
        while (temp1 && temp2) {
            if (temp1 == temp2) {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        // No intersection point found
        return NULL;
    }
};



//{ Driver Code Starts.

/* Driver program to test above function*/
int main() {
    int T, n1, n2, n3;

    cin >> T;
    cin.ignore();
    while (T--) {

        vector<int> v1 = take();
        vector<int> v2 = take();
        vector<int> v3 = take();
        int n1 = v1.size(), n2 = v2.size(), n3 = v3.size();

        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* common = NULL;

        head1 = inputList(n1, v1);
        head2 = inputList(n2, v2);
        common = inputList(n3, v3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;
        Solution ob;
        Node* intersectNode = ob.intersectPoint(head1, head2);
        cout << intersectNode->data << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends