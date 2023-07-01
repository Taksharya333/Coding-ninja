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
#include<bits/stdc++.h>
class tree{
	public:
	int min;
	int max;
	int height;
	bool isBst;
	tree()
	{
		min=INT_MAX;
		max=INT_MIN;
		height=0;
		isBst=true;
	}
};
tree* help(BinaryTreeNode<int> *root) {
	// Write your code here
	tree * ans= new tree();
	if(root==NULL)return ans;
	ans->min=root->data;
	ans->max=root->data;
	tree * left = help(root->left);
	tree * right = help(root->right);
	if(left->isBst==true && right->isBst==true)
	{
		if(left->height==0 && right->height==0)
		{
			ans->height=1;
			return ans;
		}
		else if(left->height==0)
		{
			left->min=root->data;
			left->max=root->data;
		}
		else if(right->height==0)
		{
			right->min=root->data;
			right->max=root->data;
		}
		ans->min=min(ans->min,left->min);
		if(right->min>root->data)ans->max=right->max;
		if(left->max>root->data ||right->min<root->data)
		{
			ans->height=max(left->height, right->height);
			ans->isBst=false;
			return ans;
		}
		ans->height= 1+ max(left->height, right->height);
		return ans;
	}
	else 
	{
			ans->height=max(left->height, right->height);
			ans->isBst=false;
			return ans;
	}

}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL)return -1;
	tree * ans=help(root);
	return(ans->height==0)?-1:ans->height;
}