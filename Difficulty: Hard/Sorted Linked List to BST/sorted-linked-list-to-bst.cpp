//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct LNode {
    int data;
    struct LNode* next;

    LNode(int x) {
        data = x;
        next = NULL;
    }
};

struct TNode {
    int data;
    struct TNode* left;
    struct TNode* right;

    TNode(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(TNode* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}


// } Driver Code Ends
/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; */

class Solution {
public:
    // Function to find the middle element of the linked list
    LNode* findMiddle(LNode* head) {
        if (head == NULL) return NULL;
        
        LNode* slow = head;
        LNode* fast = head;
        
        // Move 'slow' one step and 'fast' two steps, when 'fast' reaches the end, 'slow' will be at the middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    // Recursive function to construct the balanced BST
    TNode* sortedListToBST(LNode* head) {
        if (head == NULL) return NULL;
        
        // Find the middle element
        LNode* mid = findMiddle(head);
        
        // The middle element becomes the root node
        TNode* root = new TNode(mid->data);
        
        // Base case: If there's only one element in the list
        if (head == mid) return root;
        
        // Recursively build the left and right subtrees
        LNode* leftHead = head;
        LNode* rightHead = mid->next;
        
        // Disconnect the left half from the middle element to form the left subtree
        LNode* temp = leftHead;
        while (temp != NULL && temp->next != mid) {
            temp = temp->next;
        }
        if (temp != NULL) temp->next = NULL;
        
        // Build left subtree
        root->left = sortedListToBST(leftHead);
        
        // Build right subtree
        root->right = sortedListToBST(rightHead);
        
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
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        LNode* head = new LNode(data);
        LNode* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new LNode(data);
            tail = tail->next;
        }

        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends