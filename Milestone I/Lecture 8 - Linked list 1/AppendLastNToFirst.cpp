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

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
	if(head==NULL)return NULL;
	Node * temp=head;
	int i=1;
	int len=1;
	while(head->next!=NULL)
	{
		head=head->next;
		len++;
	}
	head->next=temp;
	len-=n;
	while(i!=len)
	{
		temp=temp->next;
		i++;
	}
	Node * ans=temp->next;
	temp->next=NULL;
	return ans;

}