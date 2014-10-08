#include<iostream>
using namespace std;

/*最大堆排序*/
#define MAX 64

void heapSort(int* h,int count);
void fixHeap(int *h,int num,int count);

int main()
{
	int *heap=new int[MAX];
	int num;
	cout<<"enter the number(end with -1)"<<endl;
	cin>>num;
	int count=0;
	while(num!=-1)
	{
		if(count>=MAX)
		{
			cout<<"out of size\n";
			exit(-1);
		}
		heap[count++]=num;
		cin>>num;
	}
	heapSort(heap,count);	
	for(int i=0;i<count;i++)
		cout<<heap[i]<<" ";
	cout<<endl;
}

void heapSort(int* h,int count)
{
	for(int i=count/2-1;i>=0;i--)       //建堆
		fixHeap(h,i,count);

	for(int i=count-1;i>=1;i--)
	{
		int temp=h[0];
		h[0]=h[i];
		h[i]=temp;
		fixHeap(h,0,i);
	}
}

//将根节点下沉
void fixHeap(int *h,int num,int count)
{
	int rva=h[num];
	int left=num*2+1;

	if(left>=count)return;     //没有左孩子
	int va=h[left];
	if(left+1<count&&h[left+1]>va)va=h[++left];
	if(va>rva)
	{
		h[num]=va;
		h[left]=rva;
		fixHeap(h,left,count);
	}
}