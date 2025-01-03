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
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n' << "~" << endl;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
#include<bits/stdc++.h>
class Solution {
  public:

    struct Node *mergeResult(Node *node1, Node *node2) {
        // your code goes here
        Node* t=node1;
        vector<int>a;
        while(t)
        {
            a.push_back(t->data);
            t=t->next;
        }
        t=node2;
        Node *prev=t;
         while(t)
        {
            a.push_back(t->data);
            prev=t;
            t=t->next;
        }
        prev->next=node1;
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        t=node2;
        for(int i=0;i<a.size();i++)
        {
            t->data=a[i];
            t=t->next;
        }
        return node2;
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

        getline(cin, input1); // Read the entire line for LL1 elements
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

        getline(cin, input2); // Read the entire line for LL2 elements
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
        Node *result = obj.mergeResult(head1, head2);

        printList(result);
        // cout << endl;
    }
    return 0;
}

// } Driver Code Ends