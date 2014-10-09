#include<iostream>
#include<string>
using namespace std;

//¹ıÂËµôÖØ¸´µÄ×ÖÄ¸
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	if(pInputStr==NULL||pOutputStr==NULL)
	{
		cout<<"empty string error\n";
		exit(-1);
	}

	string result="";
	for(int i=0;i<lInputLen;i++)
	{
		int len=result.length();
		int j=0;
		for(;j<len;j++)
		{
			if(result[j]==pInputStr[i])break;
		}
		if(j>=len)result.push_back(pInputStr[i]);
	}
	//cout<<result<<endl;
	int l=result.length();
	for(int i=0;i<l;i++)
		pOutputStr[i]=result[i];
	pOutputStr[l]='\0';
}

int main()
{
	char *p1="helloeniadfadsaf";
	cout<<sizeof(p1)<<endl;;
	char *p2=new char[32];
	stringFilter(p1,16 , p2);
	cout<<p2<<endl;
	return 0;
}