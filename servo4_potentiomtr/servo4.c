#include<avr/io.h>
#include<avr/interrupt.h>
#include<compat/deprecated.h>
#include<util/delay.h>
#include"uart.c"
#include"uart.h"

void initADC();
unsigned int ReadADC(unsigned int);

volatile int cnt=0;

int main()
{
	initADC();
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	sei();
	float angle,i,b;
	float val1;
	char str[5];
	sbi(DDRC,0);
	cbi(DDRA,2);
	cbi(PORTC,0);
	
	
	
	uart_puts("hi");
	
	_delay_ms(300);

	
	TCCR1A=(1<<COM1A1)|(0<<WGM10)|(1<<WGM11);
	TCCR1B=(1<<CS11)|(1<<WGM12)|(1<<WGM13);
	TIMSK|=(1<<TOIE1)|(1<<OCIE1A);
	//cbi(PORTC,0);
	
	
	
	
	while(1)
	{
		i=ReadADC(2);
		b=(180/1024);
		angle=(0.17578125*i);
		val1=(angle/90.0);
		dtostrf(angle,4,4,str);
		uart_puts(str);
		uart_putc('\n\r');
		_delay_ms(300);
		
		ICR1=40000;
		OCR1A=((1000)+(3.90625*i));
		
		
	}
	
}

ISR(TIMER1_OVF_vect)
{
	sbi(PORTC,0);
}

ISR(TIMER1_COMPA_vect)
{
	cbi(PORTC,0);
}

ISR(TIMER1_COMPB_vect)
{
	
}

void initADC()
{
	ADMUX|=(1<<REFS0);
	ADMUX|=(1<<REFS1);
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

unsigned int ReadADC(unsigned int ch)
{
	ADMUX &=0xf0;
	ch=ch&0b00000111;
	ADMUX|=ch;
	ADCSRA|=(1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)));
	ADCSRA|=(1<<ADIF);
	return(ADCW);
}
 