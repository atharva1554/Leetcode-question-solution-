//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};


void displayList(Node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}



// } Driver Code Ends

//User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};
*/


bool isSorted(Node *head) {
    if (head == NULL || head->next == NULL) return true;  

    bool nonDecreasing = true, nonIncreasing = true;
    Node* temp = head;

    while (temp->next) {
        if (temp->data > temp->next->data) nonDecreasing = false; 
        if (temp->data < temp->next->data) nonIncreasing = false;  
        temp = temp->next;
    }

    return nonDecreasing || nonIncreasing; 
}
    
    


//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        cout<<isSorted(head) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends