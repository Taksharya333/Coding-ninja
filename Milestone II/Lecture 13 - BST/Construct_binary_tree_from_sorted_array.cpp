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
BinaryTreeNode<int>* help(int*input,int s,int e)
{
		BinaryTreeNode<int>* root=NULL;
  if (s > e) 
    return root;
   int mid =(e+s)/2;
	root=new BinaryTreeNode<int>(input[mid]);
	root->left=help(input,  s,mid-1);
	root->right=help(input,mid+1,e);
	return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
	return help(input,0,n-1);
}