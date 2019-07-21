#include"sra.c"

void main()
{

pwm1_init();
lcd_init(underline);
lcd_clear();

DDRD=0b10110000;
PORTD=0b11111111;

DDRC=0xFF;
PORTC=0xFF;

DDRB=0xFF;

int val = 48, count2 = 0, prev_val2 = 0, curr_val2 = 0, count3 = 0, prev_val3 = 0, curr_val3 = 0;

lcd_write_string_xy(2,0,"Press D0");

if(bit_is_set(PIND,2))
{
	prev_val3=1;
}
if(bit_is_set(PIND,3))
{
	prev_val2=1;
}

while(bit_is_set(PIND,0))
{
}

lcd_clear();
sbi(PORTC,4);
cbi(PORTC,5);
sbi(PORTC,7);
cbi(PORTC,6);
set_pwm1a(240);
set_pwm1b(240);
//lcd_write_string_xy(5,1,"START");

while(1)
{
	if(bit_is_set(PIND,2))
	{
		curr_val3=1;
	}
	
	if(bit_is_clear(PIND,2))
	{
		curr_val3=0;
	}
	if(bit_is_set(PIND,3))
	{
		curr_val2=1;
	}
	
	if(bit_is_clear(PIND,3))
	{
		curr_val2=0;
	}
	
	if(prev_val2!=curr_val2)
	{
		count2++;
		lcd_write_int_xy(5,0,count2,3);
		prev_val2 = curr_val2;
	}
	
	if(count2==val)
	{
		sbi(PORTC,4);
		sbi(PORTC,5);
		lcd_write_string_xy(2,1,"STOP");
	}
	
	if(prev_val3!=curr_val3)
	{
		count3++;
		lcd_write_int_xy(12,0,count3,3);
		prev_val3 = curr_val3;
	}
	
	if(count3==val)
	{
		sbi(PORTC,6);
		sbi(PORTC,7);
		lcd_write_string_xy(9,1,"STOP");
	}
}
}