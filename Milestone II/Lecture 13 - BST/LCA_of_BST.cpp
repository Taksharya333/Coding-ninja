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

BinaryTreeNode<int>* help(BinaryTreeNode <int>* root , int a, int b)
{
	if(root==NULL)return NULL;
	if(a==root->data||b==root->data)return root;
	if(a<root->data && b<root->data)return help(root->left,a,b);
	else if(a>root->data && b>root->data)return help(root->right,a,b);
	BinaryTreeNode<int>* left=help(root->left,a,b);
	BinaryTreeNode<int>*right=help(root->right,a,b);
	if(left!=NULL && right!=NULL)return root;
	else {
		if(left)return left;
		else return right;
	}
}
int getLCA(BinaryTreeNode<int> *root, int val1, int val2) {
  // Write your code here
  if (val1 == val2)
    return val1;
  if (root == NULL)
    return -1;
  BinaryTreeNode<int> *ans = help(root, val1, val2);
 return (ans == NULL)?-1:ans->data;
}