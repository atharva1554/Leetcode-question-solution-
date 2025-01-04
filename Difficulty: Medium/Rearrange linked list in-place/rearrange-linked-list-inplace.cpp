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
    cout << "\n";
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node *inPlace(Node *root) {
        // Code here
        vector<int>a;
        vector<int>b;
        Node*temp=root;
        while(temp)
        {
            a.push_back(temp->data);
            temp=temp->next;
        }
        temp=root;
        for(int i=a.size()/2;i<a.size();i++)
        {
            b.push_back(a[i]);
        }
        reverse(b.begin(),b.end());
        int x=0;
        int y=0;
        for(int i=0;i<a.size();i++)
        {
            if(i%2==0)
            {
                temp->data=a[x];
                x++;
            }
            else
            {
                temp->data=b[y];
                y++;
            }
            temp=temp->next;
        }
        return root;
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        Node *ans = ob.inPlace(head);
        printList(ans);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends