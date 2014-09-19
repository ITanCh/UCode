#include<iostream>
using namespace std;

/*
 * 将数组逆序
 */
const int MAXSIZE=50;
int main(){
	int num;
	int array[MAXSIZE];
	int count=0;
	cout<<"enter the numbers of the array(end with -1)\n";
	cin>>num;
	while(num!=-1){
		array[count++]=num;
		if(count>=MAXSIZE)break;
		cin>>num;
	}

	int st=0,ed=count-1;
	while(st<ed){
		int temp=array[st];
		array[st]=array[ed];
		array[ed]=temp;
		st++;
		ed--;
	}

	for(int i=0;i<count;i++){
		cout<<array[i]<<" ";
	}
	return 0;
}
