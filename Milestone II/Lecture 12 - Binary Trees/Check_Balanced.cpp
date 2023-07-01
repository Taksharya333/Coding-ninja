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
template <class T,class U>
class Pair{
	public:
	T height;
	U isBalanced;
	
};
Pair<int,bool> help(BinaryTreeNode <int>* root)
{
Pair<int,bool> ans;
Pair<int,bool> z;
	if(root==NULL)
	{
		ans.height=0;
		ans.isBalanced=true;
		return ans;
	}
	ans=help(root->left);
	z=help(root->right);
	if(!ans.isBalanced || !z.isBalanced )
	{
		ans.isBalanced=false;
		return ans;
	}
	if(abs(ans.height-z.height)<=1)
	{
		ans.isBalanced=true;
	}
	else ans.isBalanced=false;
	ans.height=1+max(ans.height,z.height);
	return ans;
}
bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL)return true;
	return help(root).isBalanced;
}