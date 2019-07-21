#include"sra.c"

int temp_bump = 0;

void magnet_up()
{

temp_bump=0;
while(bit_is_clear(PIND,1))
{
	if(temp_bump==0)
	{
		lcd_write_string_xy(5,1,"MOVE UP");
		sbi(PORTC,0);
		cbi(PORTC,1);
	}
	temp_bump++;
}

temp_bump=0;
while(bit_is_clear(PIND,0))
{
	
	if(temp_bump==0)
	{
		lcd_clear();
		lcd_write_string_xy(5,0,"MOVE UP");
		sbi(PORTC,0);
		cbi(PORTC,1);
	}
	temp_bump++;
}

}

void magnet_down()
{

temp_bump=0;
while(bit_is_set(PIND,0))
{
	if(temp_bump==0)
	{
		lcd_clear();
		lcd_write_string_xy(5,0,"MOVE DOWN");
		cbi(PORTC,0);
		sbi(PORTC,1);
	}
	temp_bump++;
}

temp_bump=0;
while(bit_is_set(PIND,1))
{
	if(temp_bump==0)
	{
		lcd_clear();
		lcd_write_string_xy(5,1,"MOVE DOWN");
		cbi(PORTC,0);
		sbi(PORTC,1);
	}
	temp_bump++;
}

}

void main()
{

lcd_init(underline);
lcd_clear();

DDRD=0xF0;
PORTD=0xFF;

DDRB=0xFF;

DDRC=0xFF;
PORTC=0xFF;

lcd_write_string_xy(0,0,"PRESS D2 FOR UP");
lcd_write_string_xy(0,1,"PRESS D3 FOR DN");

while(1)
{

if(bit_is_clear(PIND,2))
{
	lcd_clear();
	magnet_up();
	sbi(PORTC,0);
	sbi(PORTC,1);
}

if(bit_is_clear(PIND,3))
{
	lcd_clear();
	magnet_down();
	sbi(PORTC,0);
	sbi(PORTC,1);
}

}
}