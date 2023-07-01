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
void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
	queue <BinaryTreeNode<int> *> q;
	q.push(root);
while(!q.empty())
{
	BinaryTreeNode<int> * temp=q.front();
	if(temp->left!=NULL)
	q.push(temp->left);
	if(temp->right!=NULL)
	q.push(temp->right);
	q.pop();
int a=-1;
	int b=-1;
	if(temp->left!=NULL)a=temp->left->data;
	if(temp->right!=NULL)b=temp->right->data;
	cout<<temp->data<<":L:"<<a<<",R:"<<b<<endl;
}	
}