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

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    vector<int>* ans= new vector<int>();
    if(root==NULL)return ans;
    vector<int>* left= longestPath(root->left);
    vector<int>* right= longestPath(root->right);
    if(right->size()>left->size())
    {
        right->push_back(root->data);
        return right;
    }
    else {
          left->push_back(root->data);
        return left;
    }
}