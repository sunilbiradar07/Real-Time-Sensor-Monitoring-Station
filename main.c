#include"header.h"
#define flame ((IOPIN0>>5)&1)
#define vibration ((IOPIN0>>6)&1)
extern unsigned int flag;
extern unsigned int seconds;

int main()
{
	unsigned int adc_val;
	float temp,ldr,vout;
	IODIR0=1<<18;
	uart0_init(9600);
	adc_init();
	timer0_intr_init();
	config_vic_for_TIMER0();
	while(1)
	{
		if(flag)
		{
			flag=0;          
			if(seconds==1)
			{
				uart0_string("\r\nseconds=");
				uart0_integer(seconds);
				adc_val=adc_read(1);
				temp=(adc_val*3.3*100)/1023;
				uart0_string("\r\nTEMPERATURE=");
				if(temp>30)
					IOCLR0=1<<18;
				else
					IOSET0=1<<18;
				uart0_float(temp);
				uart0_string("C");
			}
			if(seconds==2)
			{
				uart0_string("\r\nseconds=");
				uart0_integer(seconds);

				uart0_string("\r\nLIGHT=");
				adc_val=adc_read(0);
				ldr=(adc_val*100)/1023;
				uart0_float(ldr);
				uart0_string("%");


			}
			if(seconds==3)
			{
				uart0_string("\r\nseconds=");
				uart0_integer(seconds);
				adc_val=adc_read(2);
				vout=(adc_val*3.3)/1023;
				uart0_string("\r\nvoltage level=");
				uart0_float(vout);
				uart0_string("%");


				if(flame==0)
					uart0_string("\r\nFLAME DETECTED");
				else
					uart0_string("\r\nNO FLAME DETECTED");
				if(vibration==0)
					uart0_string("\r\n VIBRATION DETECTED");
				else
					uart0_string("\r\nNO VIBRATION DETECTED");
			}


		}

	}

}


