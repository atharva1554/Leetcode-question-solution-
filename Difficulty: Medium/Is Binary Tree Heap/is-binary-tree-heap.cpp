//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
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


// } Driver Code Ends

// User Function template for C++

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool isHeap(Node* tree) {
        queue<Node*> pq;
        pq.push(tree);
        vector<Node*> temp;
        temp.push_back(NULL);
        while(!pq.empty()){
            int size = pq.size();
            for(int i=0 ; i < size ; i++){
                Node* node =pq.front();
                pq.pop();
                temp.push_back(node);
                if(node->left) pq.push(node->left);
                if(node->right) pq.push(node -> right);
            }
        }
        
        for(int i=1 ; i < temp.size() ; i++){
            Node* actualLeft = temp[i] -> left;
            Node* actualRight = temp[i] -> right;
            
            Node* leftChild = NULL;
            Node* rightChild = NULL;
            
            if(2*i < temp.size()){
                leftChild = temp[2*i];
            }
            
            if(2*i + 1 < temp.size()){
                rightChild = temp[2*i+1];
            }
            
            if(leftChild != actualLeft || rightChild != actualRight) return false;
            if(leftChild && leftChild -> data >= temp[i] -> data) return false;
            if(rightChild && rightChild -> data >= temp[i] -> data) return false;
            
            
        }
        
        return true;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends