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
int h(TreeNode* root)
{
    if(root==nullptr) return 0;
    int lh=h(root->left);
    int rh=h(root->right);
    if(lh==-1||rh==-1)
    {
        return -1;
    }
    if(abs(rh-lh)>1)
    {
        return -1;
    }
    return max(lh,rh)+1;
}
    bool isBalanced(TreeNode* root) {
        
        if(h(root)==-1)
        {
            return false;
        }
        return true;
    }
};