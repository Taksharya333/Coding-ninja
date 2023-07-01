
/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
class helper{
    public:
    TreeNode<int>*prev=NULL;
    TreeNode<int>*next=NULL;
};
helper *help(TreeNode<int> *root,helper * ans) {
  if (root == NULL) {
      helper *temp=new helper();
    return temp;
  }
if(ans->next==NULL)
ans->next=root;
if(ans->prev==NULL && ans->next!=NULL)
if(root->data<ans->next->data)
ans->prev=root;
if(root->data>ans->next->data)
{
    ans->prev=ans->next;
    ans->next=root;
}
int size=root->children.size();
helper * z;
for(int i=0;i<size;i++)
{
    z=help(root->children[i],ans);
    if(z->next!=NULL)
    {
        if(z->next->data>ans->next->data)
        {
            ans->prev=ans->next;
            ans->next=z->next;
        }
    }
}
    return ans;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    helper * temp=new helper();
    return help(root,temp)->prev;
}