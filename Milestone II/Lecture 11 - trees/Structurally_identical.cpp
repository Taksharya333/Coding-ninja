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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    if(root1==NULL && root2==NULL)return true;
    else if (root1==NULL || root2==NULL)return false;
    else if(root1->data!=root2->data)return false;
    bool ans=true;
    int size=root1->children.size();
    int size1=root2->children.size();
    if(size!=size1)return false;
    for(int i=0;i<size;i++)
        ans=ans&&areIdentical(root1->children[i], root2->children[i]);
    return ans;
}