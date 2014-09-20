#include<iostream>
using namespace std;

struct Node{
	int data;
	Node*next;
};

Node*front=NULL,*rear=NULL;	

int DeQueue(){
	if(front==NULL){
		cout<<"empty queue\n";
		exit(-1);
	}
	if(rear==front)rear=NULL;
	Node* p=front;
	front=front->next;
	int data=p->data;
	delete p;
	return data;
}

void EnQueue(int x){
	if(front==NULL){
		front=rear=new Node;
		front->data=x;
		front->next=NULL;
	}
	else{
		rear->next=new Node;
		rear=rear->next;
		rear->data=x;
		rear->next=NULL;
	}
}

void Yanghui(int n){
	EnQueue(1);
	EnQueue(1);
	int one=0;
	int two=0;
	for(int i=0;i<n;i++){
		EnQueue(0);
		for(int k=n-1-i;k>0;k--)
			cout<<"  ";
		for(int j=0;j<i+3;j++){
			two=DeQueue();
			EnQueue(two+one);
			if(one!=0)cout<<one<<"   ";
			one=two;
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cout<<"enter the number of Yanghui Triangle's rows\n";
	cin>>n;
	Yanghui(n);
	return 0;
}

