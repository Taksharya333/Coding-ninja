/***********************************************************
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
BinaryTreeNode<int>* help(int *pre, int *ino, int p_s, int p_e, int i_s, int i_e)
{
  if(p_s>p_e || i_s>i_e)return NULL;
 BinaryTreeNode<int>* root = new BinaryTreeNode<int>(pre[p_s]); 
int li_s=i_s;
while(ino[i_s++]!=pre[p_s]);
i_s--;
int length=i_s-li_s;
root->left=help(pre,ino,p_s+1,p_s+length,li_s,i_s-1);
root->right=help(pre,ino,p_s+length+1,p_e,i_s+1,i_e);
return root;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
	if(preLength==0)return NULL;
	return help(preorder,inorder,0,preLength-1,0,inLength-1);
}