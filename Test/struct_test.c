#include<stdlib.h>
#include<stdio.h>

typedef struct Node Node;

struct Node
{
	int data;
	Node* next;
};

int main()
{
	Node* head=NULL;
	int i=0;

	Node*p;
	for(i=0;i<5;i++)
	{
		p=malloc(sizeof(Node));
		p->data=i;
		p->next=head;
		head=p;
	}

	p=head;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	free(head);
	head=NULL;
	free(head);
	return 0;
}
