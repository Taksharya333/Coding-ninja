/**********************************************************

        Following is the Binary Tree Node class structure

        template <typename T>
        class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
        };

***********************************************************/
vector<BinaryTreeNode<int>*>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
	if(root==NULL)return NULL;
	if(data==root->data)
	{
	vector<BinaryTreeNode<int>*>* ans=new vector<BinaryTreeNode<int>*>();
		ans->push_back(root);
		return ans;
	}
        vector<BinaryTreeNode<int>*>* temp2=getPath(root->left, data);
        vector<BinaryTreeNode<int>*>* temp1=getPath(root->right, data);
        if(temp1!=NULL)
	{
	temp1->push_back(root);
	return temp1;
	}
        if(temp2!=NULL)
	{
	temp2->push_back(root);
	return temp2;
	}
	return NULL;
}
void print(BinaryTreeNode<int>* root, int k,BinaryTreeNode<int>* non)
{
        if(root==NULL||k<0||root==non)return;
        if (k == 0) {
          cout << root->data<<endl;
          return;
        } 
        print(root->left, k-1,non);
        print(root->right, k-1,non);
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    if(k==0){
            cout<<node<<endl;
            return;
    }
    if(root==NULL)return;
    vector<BinaryTreeNode<int>*>*ans=getPath(root, node);
    vector<BinaryTreeNode<int>*>vec=*ans;
    delete ans;
     if(ans==NULL)return;
     print(vec[0],k,NULL);
     int size=vec.size();
     for(int i=1;i<size;i++)
     {
     print(vec[i],k-i,vec[i-1]);
     }
}