//{ Driver Code Starts
// Initial Template for C++

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

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
// User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/
#include<bits/stdc++.h>
class Solution {
  public:
    Node *reverse(Node *head, int k) {
        // code here
        Node *temp=head;
        vector<int>a;
        vector<int>b;
        int i=0;
        while(temp)
        {
            if(i<k)
            {
                a.push_back(temp->data);
            }
            else
            {
                b.push_back(temp->data);
            }
            i++;
            temp=temp->next;
        }
        std::reverse(a.begin(),a.end());
        std::reverse(b.begin(),b.end());
        temp=head;
        for(int i=0;i<a.size();i++)
        {
            temp->data=a[i];
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

int main() {
    int t;
    cin >> t;
    cin.ignore();
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
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
        cout << "~" << endl;
    }
}
// } Driver Code Ends