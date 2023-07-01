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
void help(Node *head, int pos, int data)
{
	if(head==NULL)return;
if(pos==1){
		Node *n= new Node(data);
		n->next=head->next;
		head->next=n;
		return;
}
help(head->next,pos-1,data);
}
Node* insertNode(Node *head, int i, int data) {
	// Write your code here
	if(i==0){
		Node *n= new Node(data);
		n->next=head;
		return n;
	}
	else help(head,i,data);
	return head;
}