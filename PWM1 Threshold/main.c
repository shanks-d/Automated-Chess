#include"sra.c"

void main()
{

pwm1_init();
DDRC=0xF0;
PORTC=0xF0;
DDRB=0xFF;
DDRD=0xF0;
PORTD=0xFF;

while(1)
{
	if(bit_is_clear(PIND,0))
	{
		set_pwm1b(334);
		while(1)
		{
			sbi(PORTC,4);
			cbi(PORTC,5);
			_delay_ms(1000);
			sbi(PORTC,5);
			cbi(PORTC,4);
			_delay_ms(1000);
		}
	}
	
	if(bit_is_clear(PIND,1))
	{
		while(1)
		{
			sbi(PORTC,4);
			cbi(PORTC,5);
			for(int i=4;i<335;i=i+10)
			{	
				set_pwm1b(i);
				_delay_ms(500);
			}
			_delay_ms(1000);
			sbi(PORTC,5);
			cbi(PORTC,4);
			for(int i=4;i<335;i=i+10)
			{	
				set_pwm1b(i);
				_delay_ms(500);
			}
		}
	}
}

}