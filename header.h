#include<lpc21xx.h>
extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char );
extern unsigned char uart0_rx(void);
extern void uart0_string(char *);
extern void uart0_integer(int );
extern void uart0_float(float );
extern void adc_init(void);
extern unsigned int adc_read(unsigned int ch_num);
extern void timer0_intr_init(void);
extern void TIMER0_HANDLER(void)__irq;
extern void config_vic_for_TIMER0(void);

