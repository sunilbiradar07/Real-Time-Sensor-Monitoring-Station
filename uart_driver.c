#include"header.h"
#define RDR (U0LSR&1)
void uart0_init(unsigned int baud)
{
	unsigned int pclk,result=0;
	if(VPBDIV==0)											
		pclk=15000000;
	else if(VPBDIV==1)
		pclk=60000000;
	else if(VPBDIV==2)
		pclk=30000000;
	result=pclk/(16*baud);
	PINSEL0|=0X5;
	U0LCR=0X83;
	U0DLL=result&0xff;
	U0DLM=(result>>8)&0xff;
	U0LCR=0X03;
}

void uart0_tx(unsigned char data)
{
	U0THR=data;
	while(((U0LSR>>5)&1)==0);
}


unsigned char uart0_rx()
{
	while(RDR==0);
	return U0RBR;
}

void uart0_tx_string(char *p)
{
	while(*p)
	{
		uart0_tx(*p);
		p++;
	}
}

void uart0_integer(int num)
{
	int a[10],i=0;
	if(num==0)
	{
		uart0_tx('0');
		return;
	}
	if(num<0)
	{
		num=-num;
		uart0_tx('-');
	}
	while(num>0)
	{
		a[i]=num%10+48;
		num=num/10;
		i++;
	}
	for(i=i-1;i>=0;i--)
		uart0_tx(a[i]);
}

void uart0_float(float num)
{
	int a;
	if(num==0)
	{
		uart0_tx('0');
		return;
	}
	if(num<0)
	{
		num=-num;
		uart0_tx('-');
	}
	a=num;
	uart0_integer(a);
	uart0_tx('.');
	a=(num-a)*1000000;
	uart0_integer(a);
}



