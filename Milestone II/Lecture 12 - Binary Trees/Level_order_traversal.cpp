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
	queue <BinaryTreeNode<int> *> q1;
	q.push(root);
	
	do{
          while (!q1.empty()) {
            root = q1.front();
			q.push(root);
			q1.pop();
          }
          while (!q.empty()) {
            root = q.front();
            if (root->left != NULL)
              q1.push(root->left);
            if (root->right != NULL)
              q1.push(root->right);
            q.pop();
            cout << root->data << ' ';
          }
		  cout<<endl;
        }while(!q1.empty());
}