#include"header.h"
void timer0_intr_init()
{
	unsigned int pclk;
	if(VPBDIV==0)
		pclk=15000000;
	else if(VPBDIV==1)
		pclk=60000000;
	else if(VPBDIV==2)
		pclk=30000000;
	T0TCR=0X02;
	T0PC=T0TC=0;
	T0PR=pclk-1;
	T0MR0=1;
	T0MCR=0X3;
	T0IR=0xff;
	T0TCR=0X01;
}
unsigned int flag=0;
unsigned int seconds=0;
void TIMER0_HANDLER()__irq
{
	flag=1;
	seconds++;
	if(seconds>3)
		seconds=0;
	T0IR=0X1;
	VICVectAddr=0;
}
void config_vic_for_TIMER0()
{
	VICIntSelect=0;
	VICVectCntl0=(1<<5)|4;			 	
	VICVectAddr0=(unsigned int)TIMER0_HANDLER;
	VICIntEnable=1<<4;

}

