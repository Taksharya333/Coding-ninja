/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

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

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/
class link {
public:
  Node<int> *head;
  Node<int> *tail;
  link(Node<int> *a, Node<int> *b)
{
	head=a;
	tail=b;
}
};
link * help(BinaryTreeNode<int>* root)
{
	link * answer= new link(NULL,NULL);
	if(root==NULL)return answer;
    Node<int>* ans=new Node<int>(root->data);	
	answer->head=ans;
    answer->tail=ans;
	link * left=help(root->left);
	link * right=help(root->right);
	if(left->tail!=NULL)
	{
		answer->head=left->head;
		left->tail->next=ans;
	}
	if(right->head!=NULL)
	{
		ans->next=right->head;
		answer->tail=right->tail;
	}
	return answer;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
	if(root==NULL)return NULL;
	return help(root)->head;
}