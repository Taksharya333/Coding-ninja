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
int help(BinaryTreeNode<int>* root,int sum)
{
	if(root==NULL)return sum;
	int num=help(root->right,sum);
	root->data+=num;
	sum=root->data;
	return help(root->left,sum);

}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
	help(root,0);
}