#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <math.h>

void cpu50_1(void)
{
	int i=0;
	while(1)
	{
		//更具cpu 频率计算
		for(i=0;i<460000;i++);
		//睡眠1 us
		usleep(1000);
	}
}

unsigned int GetTickCount()
{
	struct timeval tv;
	if(gettimeofday(&tv, NULL) != 0)
		return 0;
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void cpu50_2()
{
	int interval=10;
	int start;
	while(1)
	{
		start=GetTickCount();
		while(1)
		{
			if(GetTickCount()-start>=interval)break;
		}
		usleep(10000);
	}
}

void cpu_sin()
{
	const double SPLIT=0.01;  
	const int COUNT=200;  
	const double PI=3.14159265;  
	const int INTERVAL=500;  
	int  busySpan[COUNT]; //array of busy time  
	int  idleSpan[COUNT]; //array of idle time  
	int half=INTERVAL/2;  
	double radian=0.0;  
	for(int i=0;i<COUNT;i++)  
	{

		busySpan[i]=(int)(half+(sin(PI*radian)*half));  
		idleSpan[i]=INTERVAL-busySpan[i];  
		radian+=SPLIT;  

	}  
	int startTime=0;  
	int j=0;  
	while(1)  
	{
		j=j%COUNT;  
		startTime=GetTickCount();  
		while((GetTickCount()-startTime)<=busySpan[j]); 
		usleep(idleSpan[j]*1000);  
		j++;  

	}  
}

int main(void)
{
	cpu_sin();
}
