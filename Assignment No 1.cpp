#include<iostream>
#include<conio.h>
using namespace std;

struct node{
	int data;
	struct node *link;
};

class List{
	private:
		int size;
		node *head;
		node *curr;
		node *prevCurr;
	public:
		List(){
			size = 0;
			head = new node();
			curr = NULL;
			prevCurr = NULL;
		}
		void add(int data){
			node *newNode = new node();
			newNode->data = data;
			
			if(curr != NULL){
				newNode->link = curr->link;
				curr->link = newNode;
				prevCurr = curr;
				curr = curr->link;
			}else{
				newNode->link = NULL;
				head->link = newNode;
				prevCurr = head;
				curr = newNode;
			}
			size++;
		}
		void display(){
			node *ptr = head->link;
			while(ptr != NULL){
				cout<<ptr->data<<" ";
				ptr = ptr->link;
			}
			cout<<endl;
		}
		void start(){
			curr = head;
			prevCurr = head;
		}
		void end(){
			curr = head;
			while(curr->link->link != NULL){
				curr = curr->link;
			}
			prevCurr = curr;
			curr = curr->link;
		}
		void find(int data){
			node *iter = head->link;
			while(iter != NULL){
				if(iter->data == data){
					cout<<"The "<<data<<" is present";
					cout<<endl;
					break; 
				}else{
					iter = iter->link;
				}
			}
		}
		void remove(){
			if(curr != NULL && curr != head){
				prevCurr->link = curr->link;
				delete curr;
				curr = prevCurr->link;
				size--;
			}
			
		}
		void update(int data){
			node *ptr = head->link;
			ptr->data = data;
		}
		int length(){
			return size;
		}
		int get(){
			return curr->data;
		}
		bool next(){
			if(curr == NULL){
				return false;
			}
			prevCurr = curr;
			curr = curr->link;
			if (curr == NULL){
				return false;
			}else {
				return true;
			}	
		}
		~List(){
			curr = head->link;
			node *delNode;
			for(int i = 1; i <= size; i++){
				delNode = curr;
				cout<<"\nDeleted Node is : "<<delNode->data;
				curr = curr->link;
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
	while(L1.next())
	{
	cout<<" LIST ELEMENT IS \t"<<L1.get()<<" SIZE of LIST IS "<<L1.length()<<endl;
	}

	
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
	while(L1.next())
	{
	cout<<" LIST ELEMENT IS \t"<<L1.get()<<" SIZE of LIST IS "<<L1.length()<<endl;
	}
	
	getch();
	
	return 0;
}
