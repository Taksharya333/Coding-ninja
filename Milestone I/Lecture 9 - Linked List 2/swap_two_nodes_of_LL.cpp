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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
	Node tempe(0);
	Node * nhead=&tempe;
	nhead->next=head;
	Node *ans=nhead;
	Node * temp;
	Node * temp1;
	if(i==j)return head;
	else if(i>j)
	{
		int temp= i;
		i=j;
		j=temp;
	}
	if(j-i==1)
	{
		while(i!=0)
		{
			i--;
			nhead=nhead->next;
		}
		
		temp=nhead->next;
		nhead->next=nhead->next->next;
		temp->next=nhead->next->next;
		nhead->next->next=temp;
		return ans->next;
	}
	while(nhead->next!=NULL)
	{
		if(i==0)head=nhead;
		if(j==0)temp=nhead;
		i--;
		j--;
		nhead=nhead->next;
	
	}
	// if(nhead->next==NULL|| nhead==NULL)return ans;
	nhead=head->next;
	temp1=temp->next;
	temp->next=temp->next->next;
	head->next=head->next->next;
	nhead->next=temp->next;
	temp->next=nhead;
	temp1->next=head->next;
	head->next=temp1;
	return ans->next;
}