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

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
#include<bits/stdc++.h>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
	pair<int,int> p;
	p.first=INT_MAX;
	p.second=INT_MIN;
	if(root==NULL)return p;
	pair<int,int>left=getMinAndMax(root->left);
	pair<int,int>right=getMinAndMax(root->right);
	p.first=min(root->data,min(left.first,right.first));
	p.second=max(root->data,max(left.second,right.second));
	return p;
}