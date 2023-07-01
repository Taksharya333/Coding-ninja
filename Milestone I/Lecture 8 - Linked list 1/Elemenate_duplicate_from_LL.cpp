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

Node *removeDuplicates(Node *head)
{
    //Write your code here
	Node *test=head;
	Node* h=head;
	while(head!=NULL)
	{
		while(head!=NULL&&test->data==head->data)head=head->next;
		test->next=head;
		test=head;
		if(head==NULL)return h;
		head=head->next;
	}
	return h;
}