/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/


class Stack {
	// Define the data members
    Node * head;
    Node * tail;
    int size;
   public:
    Stack() {
        // Implement the Constructor
        head=NULL;
        tail= NULL;
        size=0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
       
        if(head==NULL)return true;
        else return false;
    }

    void push(int element) {
        // Implement the push() function
        Node *temp= new Node(element);
        if(head==NULL)
        {
            head=temp;
            tail=head; 
        }
        else{
            tail->next=temp;
            tail=tail->next;
        }
        size++;
        
    }

    int pop() {
        // Implement the pop() function
      if(size==0)return -1;
        int temper;
        
        if (size==1) {
            
            temper=head->data;
            head=NULL;
            size--;
        }
        else{
            size--;
            tail=head;
            while(tail->next->next!=NULL)
                tail=tail->next;
            temper=tail->next->data;
            tail->next=NULL;    
        }
         return temper;
    }

    int top() {
        // Implement the top() function
        if(head==NULL)return -1;
        return tail->data;

    }
};