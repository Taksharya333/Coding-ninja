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

*********************************************if********************/

Node *evenAfterOdd(Node *head)
{
	//write your code here
	if(head==NULL || head->next==NULL)return head;
	Node temp1(0),temp2(0);
	Node * odd;
	Node * even;
	Node * start;
	Node * end;
	odd=&temp1;
	even= & temp2;
	start=odd;
	end=even;
	while(head!=NULL)
	{
		if(head->data%2==1){
			odd->next=head;
			odd=odd->next;
		}
		else{
			even->next=head;
			even=even->next;
		}
		head=head->next;
	}
	even->next=NULL;
	odd->next=end->next;
	if(start->next!=NULL)return start->next;
	else return end->next;
}