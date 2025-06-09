/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    void dfs(Node*ptr,int s,int e,int &ans)
    {
        if(!ptr||ans==1)
        return ;
        if(ptr->left==NULL&&ptr->right==NULL)
        {
            if(ptr->data-1<=s&&ptr->data+1>=e)
            {
                ans=1;
                return;
            }
        }
        dfs(ptr->left,s,min(e,ptr->data),ans);
        dfs(ptr->right,max(s,ptr->data),e,ans);
    }
    bool isDeadEnd(Node *root) {
        int ans=0;
        dfs(root,0,INT_MAX,ans);
        return ans;
    }
};