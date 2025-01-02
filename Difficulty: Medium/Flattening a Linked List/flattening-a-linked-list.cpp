//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class Solution {
public:
    Node *flatten(Node *root)
    {
        // If the root is NULL, return NULL
        if (!root) return NULL;

        // Step 1: Flatten the list and store all values in a vector
        Node *temp = root;
        vector<int> a;
        
        // Traverse the list to collect all values
        while (temp != NULL)
        {
            Node *t = temp;
            while (t != NULL)
            {
                a.push_back(t->data);  // Store data from bottom nodes
                t = t->bottom;
            }
            temp = temp->next;  // Move to the next horizontal node
        }
        
        // Step 2: Sort the vector
        sort(a.begin(), a.end());

        // Step 3: Create a new linked list using the sorted values
        Node *head = new Node(a[0]);
        Node *t = head;

        // Iterate through the sorted array to build the flattened list
        for (int i = 1; i < a.size(); i++)
        {
            Node *newNode = new Node(a[i]);
            t->bottom = newNode;  // Connect the current node's bottom pointer to the new node
            t = newNode;  // Move the pointer to the newly created node
        }

        return head;  // Return the head of the new flattened list
    }
};



//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node * temp = NULL;
        struct Node * head = NULL;
        struct Node * pre = NULL;
        struct Node * tempB = NULL;
        struct Node * preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Solution ob;
        Node* root = ob.flatten(head);
        printList(root);
        cout << endl;

    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends