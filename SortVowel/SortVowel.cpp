#include<iostream>
#include<string>
using namespace std;

void sortVowel (char* input, char* &output); 

int main()
{
    char input[] = "Abort!May Be Some Errors In Out System.";  
    char *output = NULL;  
    sortVowel(input,output); 
	 
    cout << output;  
	delete [] output;
	return 0;
}

void sortVowel (char* input, char* &output)
{
	char voArr[10]={'a','e','i','o','u','A','E','I','O','U'};
	int count[10];
	string outStr="";
	for(int i=0;i<10;i++)
		count[i]=0;

	while(*input !='\0')
	{
		for(int i=0;i<10;i++)
			if(voArr[i]==*input)count[i]++;
		input++;
	}

	for(int i=0;i<10;i++)
	{
		for(int j=0;j<count[i];j++)
			outStr.push_back(voArr[i]);
	}
	outStr.push_back('\0');
	//cout<<outStr<<endl;
	int len=outStr.length();
	//cout<<len<<endl;
	output=new char[len];
	for(int i=0;i<len;i++)
	{
		output[i]=outStr[i];
	}
}
