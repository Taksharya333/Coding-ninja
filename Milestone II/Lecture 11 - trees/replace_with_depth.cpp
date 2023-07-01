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
void help(TreeNode<int>* root,int count)
{
if(root==NULL)return;
root->data=count;
int size=root->children.size();
for(int i=0;i<size;i++)
help(root->children[i],count+1);
}
void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here
    help(root,0);
}