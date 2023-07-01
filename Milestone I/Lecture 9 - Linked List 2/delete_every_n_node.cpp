/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

void help(Node * root, int m, int n , int s1, int s2)
{
	if(root==NULL)return;
	if(m==0){
		Node * temp=root;
                while (n--) {
                  if (root == NULL) {
					  temp->next=NULL;
                    return;
                  }
                  root = root->next;
                }
                temp->next=root->next;
		root=temp;
		m=s1;
		n=s2;
	}
	help(root->next,m-1,n,s1,s2);
}
Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
	if(M==0)return NULL;
	help(head,M-1,N,M,N);
	return head;
}