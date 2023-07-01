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
using namespace std;

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	stack<BinaryTreeNode<int> *> s;
	queue<BinaryTreeNode<int> *> q;
	q.push(root);
	int i=0;
	while(!q.empty())
	{
		int size=q.size();
		if(i%2==0)
		{
			while(size--)
			{
				BinaryTreeNode<int> *temp=q.front();
				cout<<temp->data<<' ';
                                if (temp->left != NULL) {
                                  q.push(temp->left);
                                  s.push(temp->left);
                                }
                                if (temp->right != NULL) {
                                  q.push(temp->right);
                                  s.push(temp->right);
                                }
                                q.pop();
			}
			cout<<endl;
		}
		else{
                  while (!s.empty()) {
                    cout << s.top()->data <<' ';
                    s.pop();
					BinaryTreeNode<int> *temp=q.front();
                                if (temp->left != NULL) 
                                  q.push(temp->left);
                                if (temp->right != NULL)
                                  q.push(temp->right);
                                q.pop();
                  }
                  cout << endl;
                }
                i++;
        }
}
