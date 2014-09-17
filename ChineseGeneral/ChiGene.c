#include<stdlib.h>
#include<stdio.h>
/*
 * 一个字节实现
 */

struct {

	unsigned char a:4;
	unsigned char b:4;
}p;

int A()
{
	printf("struct size: %lu \n",sizeof(p));

	for(p.a=1;p.a<=9;p.a++)
	{
		for(p.b=1;p.b<=9;p.b++)
		{
			if(p.a%3!=p.b%3)
			{
				printf("A: %d	B: %d\n",p.a,p.b);
			}
		}
	}
	return 0;
}

/*
 *数学功底极好的才能想出来这种办法
 *一共有81种组合，这些组合的序号和组合内容的关系
 * 0：0，0
 * 1：0，1
 * 2：0，2
 * 。。。
 * 79：8，7
 * 80：8，8*/

int B()
{
	printf("B:	=========================\n");
	unsigned char i=81;
	while(i--)
	{
		if(i/9%3==i%9%3)
			continue;
		printf("A: %d	B: %d\n",i/9+1,i%9+1);
	}
	return 0;
}
int main()
{
	A();
	B();
	return 0;
}
