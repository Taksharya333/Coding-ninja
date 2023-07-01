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

Node *reverseLinkedList(Node *head) {
    // Write your code here
	if(head==NULL || head->next==NULL)return head;
Node * temp1=head->next;
	Node * temp2=temp1->next;
	head->next=NULL;
	while(temp2!=NULL)
	{
		temp1->next=head;
		head=temp1;
		temp1=temp2;
		temp2=temp2->next;
	}
	temp1->next=head;
	return temp1;
}