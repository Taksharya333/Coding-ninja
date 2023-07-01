
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
int length(Node* head){
    Node* temp = head ;
    int len = 0 ;
     while(temp!=NULL)
     {
         len++;
         temp=temp->next ;
     }
    
    return  len;
}
Node *bubbleSort(Node *head)
{
	// Write your code here
 Node * i=head;
    int len=length(head);
    int itr=0;
   
    while(itr<len)
    {
        Node *j=head;
        Node *prev=head;
        while(j->next)
        {
            
            Node* temp=j->next;
            if(j->data>temp->data)
            {
                if(j==head)
                {
                    
                    j->next=temp->next;
                    temp->next=j;
                    prev=temp;
                    head=prev;
                }
                else
                {
                   
                    j->next=temp->next;
                    temp->next=j;
                    prev->next=temp;
                    prev=temp;
                }
                continue;
            }
            prev=j;
            j=j->next;
            
        }
        ++itr;
    }
    
    
    return head;

}