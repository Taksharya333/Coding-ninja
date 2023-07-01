/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
	if(root==NULL)return NULL;
	if(data==root->data)
	{
	vector<int>* ans=new vector<int>();
		ans->push_back(root->data);
		return ans;
	}
	if(data>root->data)
	{
		vector<int>* temp1=getPath(root->right, data);
		if(temp1!=NULL)
		{
			temp1->push_back(root->data);
			return temp1;
		}
	}
	if(data<root->data)
	{
		vector<int>* temp2=getPath(root->left, data);
		if(temp2!=NULL)
		{
			temp2->push_back(root->data);
			return temp2;
		}
	}
	else return NULL;
}