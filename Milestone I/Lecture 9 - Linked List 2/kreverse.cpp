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
Node* kReverse(Node* head, int k) {   
	 //base cal
	 if(k==0)return head;
	     if(head == NULL) return NULL;   
		   Node* next = NULL;  
		 Node* curr = head;  
		   Node* prev = NULL;
	      int count= 0;      
	  while( curr != NULL && count < k )
	   {      
		     next = curr -> next;   
	        curr -> next = prev;      
			 prev = curr;      
		 curr = next;     
		   count++;   
			  }       			 
		   if(next != NULL) {     
		 head -> next = kReverse(next,k); 
					  }     			
			   return prev;
				    }