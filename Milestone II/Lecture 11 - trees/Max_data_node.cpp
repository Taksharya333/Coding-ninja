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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
     int ans=-1;
     TreeNode<int> * temp;
     queue<TreeNode<int> *> q;
   q.push(root);
   while (!q.empty()) {
     root = q.front();
     q.pop();
     if(ans <root->data)
     {
         ans=root->data;
         temp=root;
     }
     int size = root->children.size();
     for (int i = 0; i < size; i++)
       q.push(root->children[i]);
   }
   return temp;
}