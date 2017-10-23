#include<avr/io.h>
#include<avr/interrupt.h>
#include<compat/deprecated.h>
#include<util/delay.h>



volatile int cnt=0;

int main()
{
	int i=0;
	sbi(DDRC,0);
	DDRD=0xff;
	sbi(PORTD,2);
	cbi(PORTD,3);

	

	
	
	
	
	TCCR1A|=(1<<COM1A1)|(1<<COM1B0)|(1<<WGM10)|(1<<WGM11);
	TCCR1B=(1<<CS10)|(1<<CS12);
	//TIMSK|=(1<<TOIE1)|(1<<OCIE1A);
	OCR1A=800;
	OCR1B=700  ;
	sei();
	
	
	while(1);
	{
	/*OCR1A=255;
	_delay_ms(5000);
	
	OCR1A=180;
	_delay_ms(4000);
	
	OCR1A=120;
	_delay_ms(4000);
	
	OCR1A=50;
	_delay_ms(000);*/
	
	
	}
	
}

