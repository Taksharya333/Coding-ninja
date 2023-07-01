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
int sume(TreeNode<int>* root)
{
    if(root==NULL)return 0;
    int size=root->children.size();
    int ans=root->data;
    for(int i=0;i<size;i++)
    ans+=root->children[i]->data;
    return ans;
}
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL)return nullptr;
    int ians=sume(root);
    TreeNode<int>* ans=root;
    int size=root->children.size();
    TreeNode<int>*z;
    for (int i = 0; i < size; i++) {
      z = maxSumNode(root->children[i]);
      if(sume(z)>sume(ans))
      ans=z;
    }
    return ans;
}