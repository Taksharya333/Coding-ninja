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

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL )return true;
	BinaryTreeNode<int> *left=root->left;
	BinaryTreeNode<int> *right=root->right;
	while(left!=NULL &&left->right!=NULL)
	{
		if(left->data>left->right->data)return false;
		left=left->right;
	}
	while(right!=NULL && right->left!=NULL)
	{
		if(right->data<right->left->data)return false;
		right=right->left;
	}
	if(left!=NULL &&left->data>root->data)return false;
	if(right!=NULL &&right->data<root->data)return false;
	return isBST(root->left) && isBST(root->right);	
}