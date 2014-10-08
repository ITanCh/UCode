#include<iostream>
#include<string>
#include<stack>

using namespace std;

/*字符串求解*/

string toPostfix(string &mid);
bool isDig(char c);
int inSk(char c);
int outSk(char c);

int solvePost(string s);

int main()
{
	string mid;
	string post;
	cout<<"enter the string"<<endl;
	cin>>mid;
	post=toPostfix(mid);
	int r=solvePost(post);
	cout<<"result:"<<r<<endl;
	return 0;
}


//转化为后缀表达式
string toPostfix(string &mid)
{
	stack<char> sk;
	string result;
	bool digStart=true;
	sk.push('#');
	mid.push_back('#');
	int len=mid.length();
	for(int i=0;i<len;i++)
	{
		char c=mid[i];
		if(c==' ')continue;
		if(isDig(c))
		{   digStart=true;
			result.push_back(c);
		}
		else
		{
			if(digStart){
				result.push_back(' ');
				digStart=false;
			}
			
			while(inSk(sk.top())>outSk(c))   //栈内优先级高，先出来
			{
				result.push_back(sk.top());
				sk.pop();
				result.push_back(' ');
			}

			if(inSk(sk.top())==outSk(c))
			{
				sk.pop();
			}
			else
				sk.push(c);
		}
	}

	cout<<"postfix: "<<result<<endl;
	return result;
}

bool isDig(char c)
{
	if(c<='9'&&c>='0')return true;
	return false;
}

//栈外优先级
int outSk(char c)
{
	switch(c)
	{
	case '#':return 0;
	case '+':
	case '-':return 2;
	case '*':
	case '%':
	case '/':return 4;
	case '(':return 6;
	case ')':return 1;
	default:cout<<"error char"<<endl;
				exit(-1);
	}
}

//栈内优先级
int inSk(char c)
{
	switch(c)
	{
	case '#':return 0;
	case '+':
	case '-':return 3;
	case '*':
	case '%':
	case '/':return 5;
	case '(':return 1;
	case ')':return 6;
	default:cout<<"error char"<<endl;
				exit(-1);
	}
}

//求出后缀表达式的结果
int solvePost(string post)
{
	stack<int> sk;
	int len=post.length();
	string op1="";
	int o1;
	int o2;
	int rt;
	for(int i=0;i<len;i++)
	{
		char c=post[i];
		switch(c)
		{

		case ' ':
			if(op1.length()>0)
			{
				sk.push(atoi(op1.c_str()));
				op1="";
			}
			break;

		case '+':
			o1=sk.top();
			sk.pop();
			o2=sk.top();
			sk.pop();
			rt=o1+o2;
			sk.push(rt);
			break;
		case '-':
			o1=sk.top();
			sk.pop();
			o2=sk.top();
			sk.pop();
			rt=o2-o1;
			sk.push(rt);
			break;
		case '*':
			o1=sk.top();
			sk.pop();
			o2=sk.top();
			sk.pop();
			rt=o2*o1;
			sk.push(rt);
			break;
		case '/':
			o1=sk.top();
			sk.pop();
			o2=sk.top();
			sk.pop();
			if(o1==0)
			{
				cout<<"divide 0 error"<<endl;
				exit(-1);
			}
			rt=o2/o1;
			sk.push(rt);
			break;
		case '%':
			o1=sk.top();
			sk.pop();
			o2=sk.top();
			sk.pop();
			if(o1==0)
			{
				cout<<"divide 0 error"<<endl;
				exit(-1);
			}
			rt=o2%o1;
			sk.push(rt);
			break;
		default:	//变量
			if(isDig(c))
				op1.push_back(c);
			else
			{
				cout<<"error digit"<<c<<endl;
				exit(-1);
			}
		}
	}

	return sk.top();
}