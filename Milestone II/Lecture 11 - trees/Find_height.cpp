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

void help(TreeNode<int>*root, int count, int &ans)
{
    int size=root->children.size();
if(size==0)
{
    ans=max(ans,count+1);
    return;
}
for(int i=0;i<size;i++)
help(root->children[i],count+1,ans);
}
int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL)return 0;
    int ans=0;
    help(root,0,ans);
    return ans;
}