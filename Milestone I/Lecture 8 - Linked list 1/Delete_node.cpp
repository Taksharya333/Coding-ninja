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

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
	Node *temp=head;
	if(head==NULL)return NULL;
	if(pos==0)return head->next;
	for(int i=0;i<pos-1;i++)
	{
		if(head==NULL)return temp;
		head=head->next;
	}
	if(head==NULL)return temp;
	if(head->next==NULL)return temp;
	else head->next=head->next->next;
	return temp;
}
