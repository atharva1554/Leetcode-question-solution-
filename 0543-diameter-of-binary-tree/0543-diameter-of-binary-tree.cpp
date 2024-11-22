/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int h(TreeNode*root,int&d)
{
    if(!root) return 0;
    int l=h(root->left,d);
    int r=h(root->right,d);
    d=max(d,l+r);
    return 1+max(r,l);
}
    int diameterOfBinaryTree(TreeNode* root) {
        
        int d=0;
        h(root,d);
        return d;
    }
};