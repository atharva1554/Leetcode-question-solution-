/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
    void solve(Node* root,int &ans,int &key){
        if(!root)return;
        solve(root->left,ans,key);
        solve(root->right,ans,key);
        if(root->data > ans && root->data <=key)ans = root->data;
    }
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
        solve(root,ans,k);
        return ans;
    }
};