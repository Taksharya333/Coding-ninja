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
void help(Node* head, int &i)
{
	if(head==NULL)return;
	else help(head->next,++i);
}
int length(Node *head) {
    // Write your code here
int i=0;
help(head,i);
return i;
}