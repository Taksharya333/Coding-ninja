// Following is the Binary Tree node structure
/**************
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
***************/
#include<queue>

bool checkIfSibling(BinaryTreeNode<int> *root, int p1, int p2)
{
	if(!root) return 0;
	if(root->left && root->right){
		if((root->left->data == p1 && root->right->data == p2) || (root->left->data == p2 && root->right->data == p1))
            return 1;
	}
	return (checkIfSibling(root->left,p1,p2) || checkIfSibling(root->right,p1,p2));
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
  int a = -1, b = -1;
    
	queue<BinaryTreeNode<int>*> qe;
	if(!root)
        return 0;
    
	qe.push(root);
    
	while(!qe.empty())
    {
		int size = qe.size();
		a = -1, b = -1;
                while (size--) {
                  BinaryTreeNode<int> *temp = qe.front();
                  qe.pop();
                  if (temp->data == p)
                    a = 1;
                  else if (temp->data == q)
                    b = 1;
                  if (temp->left)
                    qe.push(temp->left);
                  if (temp->right)
                    qe.push(temp->right);
                }
                if (a == 1 && b == 1 && !checkIfSibling(root, p, q))
                  return 1;
        }
        return 0;
}
