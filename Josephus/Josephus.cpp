#include<iostream>
using namespace std;
/*
 * 约瑟夫问题
 */
struct Node{
	int data;
	Node* next;
	Node(int d=0){
		data=d;
	}
};

int main()
{
	int count;
	int m;
	Node* head=NULL;
	Node* tail=NULL;
	cout<<"enter the number of nodes and the number of M\n";
	cin>>count>>m;
	if(m<=0||count<=0)
		exit(-1);
	for(int i=0;i<count;i++)
	{
		Node* p=new Node(i+1);
		p->next=NULL;
		if(i==0)
		{
			head=p;
			tail=p;
		}
		else{
			tail->next=p;
			tail=p;
		}
	}
	tail->next=head;

	int co=count-1;
	int mo=m-1;
	Node *pre=tail;
	for(int i=0;i<co;i++)
	{
		for(int j=0;j<mo;j++)
		{
			pre=head;
			head=head->next;
		}
		cout<<head->data<<" out\n";
		pre->next=head->next;
		delete head;
		head=pre->next;
	}

	cout<<head->data<<" win\n";

	return 0;
}
