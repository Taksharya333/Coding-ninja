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

bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// Write your code here
	if(root==NULL)return false;
	else if(k==root->data)return true;
	else if(k<root->data)return searchInBST(root->left,  k);
	else return searchInBST(root->right,  k);
}