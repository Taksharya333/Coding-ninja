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
#include <bits/stdc++.h>
vector<int>* help(BinaryTreeNode<int>* root)
{
	vector<int>* ans=new vector<int>();
	if(root==NULL)return ans;
	ans=help(root->left);
	vector<int>*temp=help(root->right);
	int size=temp->size();
	ans->push_back(root->data);
	for(int i=0;i<size;i++)
	ans->push_back((*temp)[i]);
	return ans;
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	vector<int>* ans=help(root);
	vector<int>nans=*ans;
	delete ans;
	int size=nans.size()-1;
	sort(nans.begin(),nans.end());
	while(nans[size--]>sum);
	size++;
	int i=0;
	while(i<size)
	{
          if (nans[i] + nans[size] == sum) {
            cout << nans[i] << ' ' << nans[size] << endl;
			i++;
			size--;
          } else if (nans[i] + nans[size] < sum)
            i++;
          else
            size--;
	}
}