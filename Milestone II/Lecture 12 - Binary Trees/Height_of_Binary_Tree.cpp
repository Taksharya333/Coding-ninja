/***********************************************************
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
int help(BinaryTreeNode<int>* root,int count)
{
	if(root==NULL)return count;
	int ans=max(help(root->left,count+1),help(root->right,count+1));
	return ans;
}
int height(BinaryTreeNode<int>* root) {
    // Write our code here
	return help(root,0);
}