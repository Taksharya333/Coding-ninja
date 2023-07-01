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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
	Node * head;
	if(head1==NULL && head2==NULL)return NULL;
	else if(head1==NULL)return head2;
	else if(head2==NULL)return head1;
	if(head1->data<head2->data){
		head= head1;
		head1=head1->next;
	}
	else{
	    head= head2;
		head2=head2->next;
	}
	Node * temp=head;
	while(head1!=NULL && head2!=NULL)
	{
	if(head1->data<head2->data)
	{
		temp->next=head1;
		head1=head1->next;
		temp=temp->next;
	}	
		else{
			temp->next=head2;
		head2=head2->next;
		temp=temp->next;
		}
	}
	if(head1==NULL)temp->next=head2;
	if(head2==NULL)temp->next=head1;
	return head;
}