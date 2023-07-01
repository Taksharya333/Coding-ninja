/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

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
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
		queue <BinaryTreeNode<int> *> q;
	q.push(root);
	vector<Node<int>*> vec;
	if(root==NULL)return vec;
	int i=0;
	Node<int>* temp;
	while(!q.empty())
	{
		int size=q.size()-1;
		temp=new Node<int>(q.front()->data);
		vec.push_back(temp);
		BinaryTreeNode<int> * temp1=q.front();
		if(temp1->left!=NULL)
		q.push(temp1->left);
		if(temp1->right!=NULL)
		q.push(temp1->right);
		q.pop();
		Node<int>* head=vec[i];
		while(size--)
		{
			BinaryTreeNode<int> * temp1=q.front();
		if(temp1->left!=NULL)
		q.push(temp1->left);
		if(temp1->right!=NULL)
		q.push(temp1->right);
		q.pop();
		temp=new Node<int>(temp1->data);
		head->next=temp;
		head=head->next;
		}
		i++;
	}
		return vec;
}