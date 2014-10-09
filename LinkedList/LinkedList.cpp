#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

//链表逆转
void reverse(Node* &head)
{
	Node*one=head;
	if(one==NULL)return;
	Node*two=head->next;
	if(two==NULL)return;
	Node*three=two->next;

	while(1)
	{
		two->next=one;
		one=two;
		two=three;
		if(two==NULL)break;
		three=two->next;
	}
	head->next=NULL;
	head=one;
}

//创建链表
Node* creList()
{
	Node*h=NULL;
	Node*t=NULL;
	int num;

	cout<<"enter the num(end with -1)\n";
	cin>>num;
	while(num!=-1)
	{
		if(h==NULL)
		{
			t=h= new Node;
			t->data=num;
			t->next=NULL;
		}
		else
		{
			t->next=new Node;
			t=t->next;
			t->data=num;
			t->next=NULL;

		}
		cin>>num;
	}
	return h;
}

//链表输出
void printList(Node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

//合并有序链表
Node* merge(Node*h1,Node*h2)
{
	Node* h=NULL;
	Node* t=NULL;
	while(h1!=NULL&&h2!=NULL)
	{
		if(h==NULL)
		{
			t=h= new Node;
			t->next=NULL;
		}
		else
		{
			t->next=new Node;
			t=t->next;
			t->next=NULL;
		}
		
		if(h1->data<h2->data)
		{
			t->data=h1->data;
			h1=h1->next;
		}
		else
		{
			t->data=h2->data;
			h2=h2->next;
		}
	}

	Node* rest=h1;
	if(rest==NULL)rest=h2;
	while(rest!=NULL)
	{
		if(h==NULL)
		{
			t=h= new Node;
		}
		else
		{
			t->next=new Node;
			t=t->next;
		}
		t->data=rest->data;
		t->next=NULL;
		rest=rest->next;
	}
	return h;
}


//合并有序链表,递归版
Node* reMerge(Node*h1,Node*h2)
{
	if(h1==NULL&&h2==NULL)return NULL;
	Node *h= new Node;
	if(h1==NULL)
	{	
		h->data=h2->data;
		h2=h2->next;
	}
	else if(h2==NULL)
	{
		h->data=h1->data;
		h1=h1->next;
	}
	else
	{
		if(h1->data<h2->data)
		{
			h->data=h1->data;
			h1=h1->next;
		}
		else	
		{
			h->data=h2->data;
			h2=h2->next;
		}
	}
	h->next=reMerge(h1,h2);
	return h;
}

int main()
{
	Node *h1=creList();
	//printList(h1);
	Node *h2=creList();
	reverse(h1);
	printList(h1);

	Node *h3=merge(h1,h2);
	printList(h3);
	
	Node* h4=reMerge(h3,h2);
	printList(h4);

	Node* h5=reMerge(h1,h2);
	printList(h5);
	return 0;
}