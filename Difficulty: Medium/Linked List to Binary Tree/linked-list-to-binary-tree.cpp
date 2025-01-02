//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void lvl(TreeNode *r) {
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}


// } Driver Code Ends
/*
// Link list Node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to convert the linked list to a binary tree
    TreeNode* linkedListToBinaryTree(Node* head) {
        if (!head) {
            return nullptr; // If the list is empty, return NULL
        }
        
        // Create the root node of the tree using the first node in the linked list
        TreeNode* root = new TreeNode(head->data);
        head = head->next; // Move to the next node in the linked list
        
        // Use a queue for level-order insertion (breadth-first)
        queue<TreeNode*> q;
        q.push(root); // Push the root node into the queue
        
        // Iterate through the linked list and fill the tree
        while (head) {
            // Pop the front node from the queue
            TreeNode* parent = q.front();
            q.pop();
            
            // Create left child from the linked list node
            TreeNode* leftChild = new TreeNode(head->data);
            parent->left = leftChild;
            q.push(leftChild); // Push the left child to the queue
            head = head->next; // Move to the next node in the list
            
            // If there's still a node left in the list, create the right child
            if (head) {
                TreeNode* rightChild = new TreeNode(head->data);
                parent->right = rightChild;
                q.push(rightChild); // Push the right child to the queue
                head = head->next; // Move to the next node in the list
            }
        }
        
        // Return the root of the binary tree
        return root;
    }
};



//{ Driver Code Starts.

int main() {
    int T;

    cin >> T;
    cin.ignore();
    while (T--) {
        struct Node *head = NULL;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            a.push_back(num); // Read the array elements from input string
            push(&head, num); // Add to linked list
        }

        reverses(&head);
        Node *prevhead = head;
        Solution obj;

        TreeNode *root = obj.linkedListToBinaryTree(head);
        if (root == NULL) {
            cout << "[]\n";
        } else {
            lvl(root);
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends