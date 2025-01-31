//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node *next;

    Node(string x) {
        data = x;
        next = NULL;
    }
};

Node *newNode(string str) {
    Node *new_node = new Node(str);
    new_node->next = NULL;
    return new_node;
}

void print(Node *root) {
    Node *temp = root;

    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}


// } Driver Code Ends
/*
The structure of linked list is the following
struct Node {
    string data;
    Node *next;

    Node(string x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
      int a(string ans)
      {
          int n=ans.size();
          for(int i=0;i<n;i++)
          {
              if(ans[i]!=ans[n-i-1])
              {
                  return 0;
              }
          }
          return 1;
      }
    bool compute(Node* head) {
        // Your code goes here
        string ans="";
        Node*temp=head;
        while(temp!=NULL)
        {
            ans=ans+temp->data;
            temp=temp->next;
        }
        return a(ans);
    }
};


//{ Driver Code Starts.

int main() {
    // your code goes here
    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++) {
            string str = "";
            cin >> str;
            if (head == NULL)
                head = temp = new Node(str);
            else {
                temp->next = new Node(str);
                temp = temp->next;
            }
        }
        Solution ob;
        bool ans = ob.compute(head);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends