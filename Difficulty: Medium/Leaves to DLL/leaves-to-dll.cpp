//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inOrder(Node *root) {
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
public:
    Node* prev = nullptr; // To maintain the previous node in the DLL
    Node* head = nullptr; // Head of the DLL

    // Helper function to extract leaf nodes and build DLL
    Node* extractLeaves(Node* root) {
        if (!root) return nullptr;

        // If the node is a leaf
        if (!root->left && !root->right) {
            if (!head) {
                // Initialize the DLL with the first leaf node
                head = root;
            } else {
                // Add the leaf to the DLL
                prev->right = root;
                root->left = prev;
            }
            prev = root; // Update the previous pointer
            return nullptr; // Remove the leaf node from the tree
        }

        // Recursively process left and right subtrees
        root->left = extractLeaves(root->left);
        root->right = extractLeaves(root->right);

        return root; // Return the modified subtree
    }

    // Function to convert the binary tree to doubly linked list
    Node* convertToDLL(Node* root) {
        if (!root) return nullptr;

        // Extract leaves and build DLL
        root = extractLeaves(root);

        return head; // Return the head of the DLL
    }

    // Helper function for in-order traversal of the tree
    void inorderTraversal(Node* root, vector<int>& result) {
        if (!root) return;
        inorderTraversal(root->left, result);
        result.push_back(root->data);
        inorderTraversal(root->right, result);
    }

    // Helper function to traverse DLL from left to right
    vector<int> traverseDLL(Node* head) {
        vector<int> result;
        Node* curr = head;
        while (curr) {
            result.push_back(curr->data);
            curr = curr->right;
        }
        return result;
    }

    // Helper function to traverse DLL from right to left
    vector<int> traverseDLLReverse(Node* head) {
        vector<int> result;
        if (!head) return result;

        // Go to the last node of the DLL
        Node* tail = head;
        while (tail->right) {
            tail = tail->right;
        }

        // Traverse backward
        while (tail) {
            result.push_back(tail->data);
            tail = tail->left;
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution sol;
        Node *head = sol.convertToDLL(root);
        inOrder(root);
        cout << "\n";
        Node *curr = head, *last = head;
        while (curr) {
            cout << curr->data << " ";
            last = curr;
            curr = curr->right;
        }
        cout << "\n";
        curr = last;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->left;
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends