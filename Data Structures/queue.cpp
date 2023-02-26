#include<iostream>
using namespace std;

class queue{
	int que[10];
	int front=0;
	int rear=-1;
	int val;
	public:
		void add(int data){
			if(rear >= 9){
				cout<<"Queue Overflow";
			}
			else{
				rear++;
				que[rear] = data;
			}
		}
		int q_delete(){
			if(rear==-1){
				cout<<"queue Underflow";
			}
			else if(front == rear){
			val = que[front];
			front = 0;
			rear = -1;
			}
			else{
			val = que[front];
			front++;
			}
			return val;
		}
		void display(){
				if(rear==-1){
				cout<<"queue Underflow";
			}else{
			cout<<"Data : \n";
			for(int i = front;i<=rear;i++){
				cout<<"Queue["<<i<<"] = "<<que[i]<<endl;
			}
		}
	}
};

int main(){
	queue q;
	q.add(10);
	q.add(20);
	q.add(30);
	q.q_delete();
    q.q_delete();
    q.add(40);
	q.display();
	return 0;
}