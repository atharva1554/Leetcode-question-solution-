//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to display nodes
void display(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends
// User function Template for C++
/* Linked List Node structure
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
class Solution {
  public:
    void moveZeroes(struct Node*& head) {
        // code here
        if(!head||!head->next)
        {
            return ;
        }
        Node *zhead=NULL;
        Node *ztail=NULL;
        Node *p=NULL;
        Node *c=head;
        while(c)
        {
            if(c->data==0)
            {
                Node*nextnode=c->next;
                if(p)
                {
                    p->next=c->next;
                }
                else
                {
                    head=c->next;
                }
                if(!zhead)
                {
                    zhead=ztail=c;
                }
                else
                {
                    ztail->next=c;
                    ztail=c;
                }
                c->next=NULL;
                c=nextnode;
            }
            else
            {
                p=c;
                c=c->next;
            }
        }
        if(ztail)
        {
            ztail->next=head;
            head=zhead;
        }
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        ob.moveZeroes(head);
        display(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends