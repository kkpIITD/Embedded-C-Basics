#include<avr/io.h>
#include<avr/interrupt.h>
#include<compat/deprecated.h>



int main()
{
	int i=0;
	sbi(DDRC,0);
	
	
	while(1)
	{
		PORTC^=(1<<0);
		
		for(i=0;i<227;i++)
		{
			TCCR1A=(1<<COM1A1);
			TCCR1B=(1<<WGM12)|(1<<CS10);
			TCNT1=12;
			while(!(TIFR&(1<<TOV1)));
			TIFR=0b00000100;
			TCCR1B=0;
		}
	}
	
}