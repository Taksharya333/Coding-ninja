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
#include <bits/stdc++.h>
vector<int>* help(BinaryTreeNode<int>* root,int s)
{
	vector<int>* ans=new vector<int>();
	if(root==NULL)return ans;
	if(root->data>s) return help(root->left,s);
	ans=help(root->left,s);
	vector<int>*temp=help(root->right,s);
	int size=temp->size();
	ans->push_back(root->data);
	for(int i=0;i<size;i++)
	ans->push_back((*temp)[i]);
	return ans;
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
	
	vector<int>* ans= help(root,s);
	if(ans->size()==0)return;
	vector<int>nans=*ans;
	delete ans;
	int size=nans.size()-1;
	sort(nans.begin(),nans.end());
	while(nans[size--]>s);
	size++;
	int i=0;
	while(i<size)
	{
          if (nans[i] + nans[size] == s) {
            cout << nans[i] << ' ' << nans[size] << endl;
			i++;
			size--;
          } else if (nans[i] + nans[size] < s)
            i++;
          else
            size--;
	}
}