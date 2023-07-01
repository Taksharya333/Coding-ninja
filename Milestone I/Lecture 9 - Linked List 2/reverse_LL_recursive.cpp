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
Node * rev(Node * head, Node * temp1, Node * temp2)
{
if(temp2==NULL)
{
	temp1->next=head;
	return temp1;
}
temp1->next=head;
return rev(temp1,temp2,temp2->next);
}

Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
	if(head==NULL || head->next==NULL)return head;
	Node * temp1=head->next;
	Node * temp2=temp1->next;
	head->next=NULL;
	return rev(head,temp1,temp2);
}