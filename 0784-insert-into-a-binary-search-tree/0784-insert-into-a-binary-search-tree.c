/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
  struct TreeNode* t=root;
  struct TreeNode*p,*r;
  if(root==NULL)
  {
    t=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    t->val=val;
    t->left=t->right=NULL;
    root=t;
    return root;
  }
  while(t!=NULL)
  {
    r=t;
    if(t->val>val)
    {
        t=t->left;
    }
    else if(t->val<val)
    {
        t=t->right;
    }
    else
    {
        return root ;
    }
  }
  p=(struct TreeNode*)malloc(sizeof(struct TreeNode));
  p->val=val;
  p->left=p->right=NULL;
  if(r->val>val)
  {
    r->left=p;
  }
  else if(r->val<val)
  {
    r->right=p;
  }
  return root;
}