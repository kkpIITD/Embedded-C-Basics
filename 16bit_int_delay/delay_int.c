#include<avr/io.h>
#include<avr/interrupt.h>
#include<compat/deprecated.h>

volatile int cnt=0;

int main()
{
	int i=0;
	sbi(DDRC,0);
	
	
	TCCR1A=(1<<COM1A1);
	TCCR1B=(1<<CS10);
	TIMSK|=(1<<TOIE1);
	sei();
	
	
	while(1)
	{
		while((cnt/227)==0);
			PORTC^=(1<<0);
			cnt=0;
	}
	
}

ISR(TIMER1_OVF_vect)
{
	cnt++;
	//PORTC^=(1<<0);
}