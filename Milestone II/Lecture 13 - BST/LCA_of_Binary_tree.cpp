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
class tree{
	public:
	BinaryTreeNode<int>* root;
	bool a;
	bool b;
	tree()
	{
		root=NULL;
		a=false;
		b=false;
	}
	tree(BinaryTreeNode<int> * given, bool left, bool right)
	{
		root=given;
		a=left;
		b=right;
	}
};
tree* help(BinaryTreeNode <int>* root , int a, int b)
{
	tree* ans= new tree();
	if(root==NULL) return ans;
        if (root->data == a) {
			ans->root=root;
			ans->a=true;
        }
		if(root->data==b){
			ans->root=root;
			ans->b=true;
		}
        tree*left=help(root->left,a,b);
	    tree*right=help(root->right,a,b);
		if(left->a==true && left->b==true)return left;
		else if(right->a==true && right->b==true)return right;
		else 
		{
			ans->root=root;
			ans->a=left->a || right->a||ans->a;
			ans->b=left->b||right->b||ans->b;
			return ans;
		}
}
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
	if(a==b)return a;
	if(root==NULL)return -1;
	tree* ans= help(root,a,b);
	if(ans->a==true && ans->b==true)return ans->root->data;
	else return -1;
}