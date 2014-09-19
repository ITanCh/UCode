#include"ToPostfix.h"
/*
 * 后缀表达式求解
 * 
 */
struct Node{
	int data;
	Node* next;
};

int Pop(Node* &stack);
void Push(Node* &stack,int data);

int main(){
	Node* head=NULL;
	string nifix;
	int op1;
	int op2;
	string tempop="";
	bool hasTemp=false;
	int result;
	cout<<"enter the nifix expression\n";
	getline(cin,nifix);
	string postfix=getPostfix(nifix);
	cout<<"postfix:"<<postfix<<endl;
	int size=postfix.size();

	for(int i=0;i<size;i++){
		char in=postfix[i];
		switch(in){
			case '+':op2=Pop(head);
					 op1=Pop(head);
					 result=op1+op2;
					 Push(head,result);
					 break;
			case '-':op2=Pop(head);
					 op1=Pop(head);
					 result=op1-op2;
					 Push(head,result);
					 break;
			case '*':op2=Pop(head);
					 op1=Pop(head);
					 result=op1*op2;
					 Push(head,result);
					 break;
			case '/':op2=Pop(head);
					 op1=Pop(head);
					 if(op2==0)
					 {
						 cout<<"divid 0\n";
						 exit(-1);
					 }
					 result=op1/op2;
					 Push(head,result);
					 break;
			case '%':op2=Pop(head);
					 op1=Pop(head);
					 if(op2==0)
					 {
						 cout<<"divid 0\n";
						 exit(-1);
					 }
					 result=op1%op2;
					 Push(head,result);
					 break;
			case ' ':
					 if(hasTemp){
						 hasTemp=false;
						 op1=stoi(tempop);
						 cout<<"digit:"<<op1<<endl;
						 tempop="";
						 Push(head,op1);
					 }
					 break;
			default:
					 hasTemp=true;
					 tempop.push_back(in);
					 break;
		}
	}
	cout<<"result: "<<head->data<<endl;;
	return 0;
}

int Pop(Node* &stack){
	if(stack==NULL){
		cout<<"error:miss operand\n";
		exit(-1);
	}
	int data=stack->data;
	Node* p=stack;
	stack=stack->next;
	delete p;
	return data;
}

void Push(Node* &stack,int data){
	Node*p=new Node;
	p->data=data;
	p->next=stack;
	stack=p;
}
