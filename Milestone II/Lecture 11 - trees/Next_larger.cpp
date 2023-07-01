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

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    if(root==NULL)return NULL;
    if(root->data>x)return root;
    int size=root->children.size();
    TreeNode<int>* ans;
    for(int i=0;i<size;i++)
    {ans=getNextLargerElement(root->children[i], x);
    if(ans!=NULL)return ans;}
    return NULL;
    
}