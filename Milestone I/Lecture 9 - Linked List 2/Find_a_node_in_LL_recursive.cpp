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
int help(Node *head, int n, int i)
{
	if(head==NULL)return -1;
	if(head->data==n)return i;
	return help(head->next,n,i+1);
}
int findNodeRec(Node *head, int n)
{
	//Write your code here
	if(head==NULL)return -1;
	return help(head,n,0);
}