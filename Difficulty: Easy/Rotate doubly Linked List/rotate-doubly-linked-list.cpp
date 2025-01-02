//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};


// } Driver Code Ends
// User function Template for C++

/*
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *rotateDLL(Node *head, int p) {

        // code here..
        if(head->next==nullptr)
          return head;
        Node* temp=head;
        while(temp->next!=nullptr)
          temp=temp->next;
        
        while(p)
        {
            Node* t=head;
            head=head->next;
            head->prev=nullptr;
            t->next=nullptr;
            temp->next=t;
            t->prev=temp;
            temp=t;
            p--;
            
        }
        return head;
    }
};

//{ Driver Code Starts.

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int d;
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        // string dummy;
        // cin>>dummy;
        cin.ignore();
        Node *start = NULL, *cur = NULL;

        // Build doubly linked list
        for (int i = 0; i < arr.size(); i++) {
            Node* ptr = new Node(arr[i]);
            if (start == NULL) {
                start = ptr;
                cur = ptr;
            } else {
                cur->next = ptr;
                ptr->prev = cur;
                cur = ptr;
            }
        }

        Solution obj;
        Node* rotatedList = obj.rotateDLL(start, d);
        printList(rotatedList);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends