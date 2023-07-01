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

void printIthNode(Node *head, int i)
{
    //Write your code here
	while(i!=0)
	{
		i--;
		head=head->next;
		if(head==NULL)return;
	}
	if(head==NULL)return;
	cout<<head->data;
}