#include<iostream>

using namespace std;
#define MAX 64 

void quickSort(int *a,int start,int end);
int partition(int *a,int start,int end);

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
	quickSort(array,0,count-1);	
	for(int i=0;i<count;i++)
		cout<<array[i]<<" ";
	cout<<endl;
}

int partition(int *a,int start,int end)
{
	if(start>=end)return start;
	int pi=a[start];
	int po=start;
	for(int i=start+1;i<=end;i++)
	{
		if(a[i]<=pi)
		{
			po++;
			if(po!=i)
			{
				int temp=a[po];
				a[po]=a[i];
				a[i]=temp;
			}
		}
	}
	a[start]=a[po];
	a[po]=pi;
	return po;
}

void quickSort(int *a,int start,int end)
{
	if(start>=end)return;
	int po=partition(a,start,end);
	quickSort(a,start,po-1);
	quickSort(a,po+1,end);
}