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
void help(Node *head, int pos)
{
	if(head==NULL)return;
if(pos==1){
	if(head->next==NULL)return; 
		head->next=head->next->next;
		return;
}
help(head->next,pos-1);
}
Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
	if(pos==0)return head->next;
	help(head,pos);
	return head;
}