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
class BST {
    // Define the data members
    BinaryTreeNode<int>*root;
    
	bool searchInBST(BinaryTreeNode<int> *node , int k) {
	if(node==NULL)return false;
	else if(k==node->data)return true;
	else if(k<node->data)return searchInBST(node->left,  k);
	else return searchInBST(node->right,  k);
    }

	BinaryTreeNode<int>* insert(BinaryTreeNode<int>*node, int data)
	{
		if(node==NULL)
		{
			BinaryTreeNode<int>* newNode=new BinaryTreeNode<int>(data);
			return newNode;
		}
		else if(node->data<data)
		{
			node->right=insert(node->right,data);
		}
		else{
			node->left=insert(node->left,data);
		}
	}

	BinaryTreeNode<int>* remove(BinaryTreeNode<int>*node, int data)
	{
		if(node==NULL)return NULL;
		else if(data<node->data)
			node->left=remove(node->left,data);
		else if(data>node->data)
			node->right=remove(node->right,data);
		else{
			if(node->left==NULL && node->right==NULL)
			{
				delete node;
				return NULL;
			}
			else if(node->left==NULL)
			{
				BinaryTreeNode<int>* temp=node->right;
				node->right=NULL;
				delete node;
				return temp;
			}
			else if(node->right==NULL)
			{
				BinaryTreeNode<int>* temp=node->left;
				node->left=NULL;
				delete node;
				return temp;
			}
			else{
				BinaryTreeNode<int>*leftmin=node->right;
				while(leftmin->left!=NULL)
				leftmin=leftmin->left;
				node->data=leftmin->data;
				node->right=remove(node->right,leftmin->data);
				return node;
			}
		}

	}

	void print(BinaryTreeNode<int>* node)
	{
		if(node==NULL)return;
		cout<<node->data<<':';
	if(node->left!=NULL)cout<<"L:"<<node->left->data<<',';
	if(node->right!=NULL)cout<<"R:"<<node->right->data;
	cout<<endl;
	print(node->left);
	print(node->right);
	}
   public:
    BST() { 
        // Implement the Constructor
        root=NULL;
    }

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        // Implement the remove() function 
		root=remove(root,data);
    }

    void print() { 
        // Implement the print() function
		print(root);
 }

    void insert(int data) { 
        // Implement the insert() function 
		root=insert(root,data);
    }

    bool search(int data) {
		// Implement the search() function 
        return searchInBST(root, data);
    }
};