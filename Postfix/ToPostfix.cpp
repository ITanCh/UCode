#include"ToPostfix.h"
/*
 * 转换成后缀表达式
 * 利用该函数和后缀表达式求解可以实现
 * 字符串表达式求解
 */
struct Node_{
	char data;
	Node_* next;
};


bool isDigit(char c);
int isp(char c);
int icp(char c);
char getTop(Node_* head);
void Push(Node_* &head,char c);
char Pop(Node_* &head);

/*
int main(){
	string nifix;
	cout<<"enter the nifix expression\n";
	getline(cin,nifix);
	string postfix=getPostfix(nifix);
	cout<<postfix<<endl;
}
*/

string getPostfix(string &s){
	string postfix;
	Node_* stack=new Node_;
	stack->data='#';
	stack->next=NULL;
	bool isEnd=true;
	s.push_back('#');
	int size=s.size();
	cout<<"size:"<<size<<endl;
	for(int i=0;i<size;i++){
		char symbol=s[i];
		if(symbol==' ')continue;
		if(isDigit(symbol)){
			isEnd=true;
			postfix.push_back(symbol);
		}
		else {
			if(isEnd){
				isEnd=false;
				postfix.push_back(' ');
			}
			while(icp(symbol)<isp(getTop(stack))){
				postfix.push_back(Pop(stack));
				postfix.push_back(' ');
			}
			if(icp(symbol)==isp(getTop(stack))){
				Pop(stack);
			}
			else{
				Push(stack,symbol);
			}
		}
	}
	return postfix;
}

bool isDigit(char c){
	switch(c){
		case '#':
		case '(':
		case ')':
		case '*':
		case '/':
		case '+':
		case '-':
		case '%':return false;
		default:return true;
	}
}

int icp(char c){
	switch(c){
		case '#':return 0;
		case '(':return 6;
		case '*':
		case '/':
		case '%':return 4;
		case '+':
		case '-':return 2;
		case ')':return 1;
		default:cout<<"error char :"<<c<<endl;
				exit(-1);
	}
}

int isp(char c){
	switch(c){
		case '#':return 0;
		case '(':return 1;
		case '*':
		case '/':
		case '%':return 5;
		case '+':
		case '-':return 3;
		case ')':return 6;
		default:cout<<"error char :"<<c<<endl;
				exit(-1);
	}
}

char getTop(Node_* head){
	if(head==NULL){
		cout<<"stack empty\n";
		exit(-1);
	}
	return head->data;
}

void Push(Node_* &head,char c){
	Node_*p= new Node_;
	p->data=c;
	p->next=head;
	head=p;
}

char Pop(Node_* &head){
	if(head==NULL){
		cout<<"stack empty\n";
		exit(-1);
	}
	Node_ *p=head;
	head=head->next;
	char c=p->data;
	delete p;
	return c;
}


