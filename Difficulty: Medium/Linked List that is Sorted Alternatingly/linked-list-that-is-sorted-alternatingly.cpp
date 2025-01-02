//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sort(Node* head) {
        // Code here
        map<int,int>mpp;
        Node *temp=head;
        while(temp)
        {
            mpp[temp->data]++;
            temp=temp->next;
        }
        temp=head;
        for(auto it:mpp)
        {
            if(it.second>0)
            {
                int x=it.second;
                while(x--)
                {
                    temp->data=it.first;
                    temp=temp->next;
                }
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }
        }

        Solution ob;
        Node* newHead = ob.sort(head);
        printList(newHead);
        freeList(newHead);

        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends