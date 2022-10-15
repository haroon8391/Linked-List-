#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

class List {
	private:
		int size;
	    Node *head;
		Node *current;
		Node *lastcurrent;
	public:
		List(){
			size = 0;
			head=new Node();
			current=NULL;
			lastcurrent=NULL;
		}
		
	void add(int data){
		Node *newNode = new Node();
		newNode -> data = data;
		if(current != NULL){
				newNode -> next = current -> next;
				current -> next = newNode;
				lastcurrent = current;
				current = current -> next; 
			}
		else{
				newNode -> next = NULL;
				head -> next = newNode;
				lastcurrent = head;
				current = newNode;
			}
			size++;
		}
		
	void start(){
			current = head;
			lastcurrent = head;
		}
		
	bool next(){
			if(current == NULL){
				return false;
			}
			
			lastcurrent = current;
			current = current -> next;
			if (current == NULL)
				return false;
			else 
				return true;
		}
		
	int length(){
			return size;
		}
		
	int get(){
			return current -> data;
		}
		
	void find(int data){
		Node *iter = head -> next;
		while(iter != NULL){
			if(iter -> data == data){
				cout<<" The "<<data<<" is present in list";
				cout<<endl;
				break;
			}
			else{
				iter = iter -> next;
			}
		}
	}
	
	void remove(){
		if (current != NULL && current!=head){
				lastcurrent -> next = current -> next;
				delete current;
				current = lastcurrent -> next;
				size--;
			}
		}
		
		
	void update(int data){
		Node *ptr = head -> next;
		ptr -> data = data;
		
	}
	
	void end(){
		current = head;
		while(current -> next -> next != NULL){
			current = current -> next;
		}
		lastcurrent = current;
		current = current -> next;
	}
	
	void display(){
		Node *ptr = head;
		while(ptr != NULL){
			cout<<" "<<ptr -> data<< " ";
			ptr = ptr -> next;
		}
		cout<<endl;
	}
	
	
	~List(){
		current = head -> next;
		Node *delNode;
		for(int i=1; i<=size; i++){
			delNode = current;
			cout<<" Deleted Node is "<<delNode -> data<<endl;
			current = current -> next;
			delete delNode;
		}
		delete head;
	}
		
};



int main(){
	List L1;
	List L2;
	
	L1.add(6);
	L1.add(7);
	L1.add(3);
	L1.add(6);
	L1.add(20);
	
	L1.display();
	
	L1.start();

	while(L1.next()){
 	cout<<" LIST ELEMENT IS \t"<<L1.get()<<endl<<" SIZE of LIST IS "<<L1.length()<<endl;
	}
	cout<<endl;
	
	L1.start();
	L1.find(7);
	L1.remove();
	
	L1.start();
	L1.find(6);
	L1.update(60);
	
	L1.start();
	
	L1.add(100);
	L1.end();
	L1.add(200);
	L1.add(200);
    L1.start();
    
    cout<<endl;
    while(L1.next()){
    cout<<" LIST ELEMENT IS \t"<<L1.get()<<endl<<" SIZE of LIST IS "<<L1.length()<<endl;
	}
	cout<<endl;
	
	return 0;
}
