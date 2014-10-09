#include<iostream>
using namespace std;

#define MAX 64

void sort(int*h,int start,int end);
void merge(int *h,int start,int mid,int end);

int main()
{
	int num;
	int *array=new int[MAX];
	int count=0;
	cout<<"enter the num(end with -1)\n";
	cin>>num;
	while(num!=-1)
	{
		if(count>=MAX)
		{	
			cout<<"out of size\n";
			exit(-1);
		}
		array[count++]=num;
		cin>>num;
	}		
	sort(array,0,count-1);	
	for(int i=0;i<count;i++)
	cout<<array[i]<<" ";
	cout<<endl;
}

void merge(int *h,int start,int mid,int end)
{
	int len=end-start+1;
	int *temp=new int[len];
	for(int i=0;i<=mid-start;i++)
		temp[i]=h[start+i];
	for(int i=0;i<end-mid;i++)
		temp[mid-start+i+1]=h[end-i];

	int p1=0;
	int p2=len-1;

	for(int i=start;i<=end;i++)
	{
		if(temp[p1]<temp[p2])
			h[i]=temp[p1++];
		else
			h[i]=temp[p2--];
	}	
}


void sort(int*h,int start,int end)
{
	if(start>=end)return;
	int mid=(end-start)/2+start;
	sort(h,start,mid);
	sort(h,mid+1,end);
	merge(h,start,mid,end);
}