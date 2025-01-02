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

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
    struct Node* partition(struct Node* head, int x) {
        // code here
        vector<int>a;
        vector<int>b,c;
        Node *temp=head;
        while(temp)
        {
            if(temp->data<x)
            {
                a.push_back(temp->data);
            }
            else if(temp->data==x)
            {
                c.push_back(temp->data);
            }
            else
            {
                b.push_back(temp->data);
            }
            temp=temp->next;
        }
        
        temp=head;
        for(int i=0;i<a.size();i++)
        {
            temp->data=a[i];
            temp=temp->next;
        }
         for(int i=0;i<c.size();i++)
        {
            temp->data=c[i];
            temp=temp->next;
        }
        for(int i=0;i<b.size();i++)
        {
            temp->data=b[i];
            temp=temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        // Solution ob;
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
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        head = ob.partition(head, x);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends