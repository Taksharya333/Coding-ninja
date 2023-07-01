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

bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here
    bool ans=false;
    if(root->data==x)return true;
    if(root==NULL)return false;
    else{
        for(int i=0;i<root->children.size();i++)
        {
            if(x==root->children[i]->data)return true;
            ans=ans||isPresent(root->children[i],x);
        }
        return ans;
    }
}