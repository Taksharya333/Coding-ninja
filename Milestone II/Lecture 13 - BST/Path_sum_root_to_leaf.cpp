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
#include<bits/stdc++.h>
void help(BinaryTreeNode<int>* root, int k, string g)
{
	if(root==NULL)	return;
	if(k==root->data)
	if(root->left==NULL && root->right==NULL)
	{
		string temp=  g+to_string(root->data);
		cout<<temp<<endl;
	}
	help(root->left, k-root->data, g+to_string(root->data)+' ');
	help(root->right, k-root->data, g+to_string(root->data)+' ');
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
	help(root,k,"");
}