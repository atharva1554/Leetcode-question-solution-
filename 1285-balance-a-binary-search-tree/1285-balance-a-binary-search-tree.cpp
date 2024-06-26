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
    // for getting the inorder of BST
    void inorderTraversal(TreeNode*root,vector<TreeNode*>&inorder){
        if(root==NULL){
            return ;
        }
        if(root->left){
            inorderTraversal(root->left,inorder);
        }

        inorder.push_back(root);

        if(root->right){
            inorderTraversal(root->right,inorder);
        }
    }

    // to make a balanced tree 
    TreeNode* makeBalancedBST(vector<TreeNode*>&inorder,int start,int end){
        //base case 
        if(start>end){
            return NULL;
        }

        // find mid
        int mid=start + (end-start)/2;
        //now call for left and right 

        //for left keep start as it is and change end 
        inorder[mid]->left=makeBalancedBST(inorder,start,mid-1);

        // for right keeping end same but changing start
        inorder[mid]->right=makeBalancedBST(inorder,mid+1,end);
        
        return inorder[mid];//returning mid as it's root for this subtree which will be linked with above left or right
    }

         

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>inorder;//to store the inorder traversal of BST
        inorderTraversal(root,inorder);

        int start=0;//initially start is 0 index and end is n-1
        int end=inorder.size()-1;

        return makeBalancedBST(inorder,start,end);//this will return the mid of inorder which is our root for balanced BST

    }
};