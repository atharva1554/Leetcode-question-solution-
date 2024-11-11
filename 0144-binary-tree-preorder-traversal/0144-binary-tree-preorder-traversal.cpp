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
void preoder(TreeNode* node,vector<int>&ans)
{
    if(node==nullptr)
    {
        return;
    }
    ans.push_back(node->val);
    preoder(node->left,ans);
    preoder(node->right,ans);
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preoder(root,ans);
        return ans;
    }
};