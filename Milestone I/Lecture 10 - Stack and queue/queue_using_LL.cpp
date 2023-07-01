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

class Queue {
	// Define the data members
	Node * head;
	Node * tail;
	int size;
   public:
    Queue() {
		// Implement the Constructor
		head=NULL;
		tail=NULL;
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

    void enqueue(int data) {
		// Implement the enqueue() function
		 Node *temp= new Node(data);
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

    int dequeue() {
        // Implement the dequeue() function
		 if(size==0)return -1;
        int temper;
        
        if (size==1) {
            
            temper=head->data;
            head=NULL;
            size--;
        }
        else{
            size--;
            temper=head->data;
            head=head->next; 
        }
         return temper;
    }

    int front() {
        // Implement the front() function
		if(head==NULL)return -1;
		else return head->data;
    }
};