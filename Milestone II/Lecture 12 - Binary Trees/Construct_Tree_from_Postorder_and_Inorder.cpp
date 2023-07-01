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
BinaryTreeNode<int>* help(int *pos, int *ino, int p_s, int p_e, int i_s, int i_e)
{
  if(p_s>p_e || i_s>i_e)return NULL;
 BinaryTreeNode<int>* root = new BinaryTreeNode<int>(pos[p_e]); 
int li_s=i_s;
while(ino[i_s++]!=pos[p_e]);
i_s--;
int length=i_s-li_s;
root->left=help(pos,ino,p_s,p_s+length-1,li_s,i_s-1);
root->right=help(pos,ino,p_s+length,p_e-1,i_s+1,i_e);
return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
	if(postLength==0)return NULL;
	return help(postorder,inorder,0,postLength-1,0,inLength-1);
}