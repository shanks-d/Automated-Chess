#include"sra.c"

void check()
{

if(bit_is_set(PINA,0)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(2,0,"A");
	delay_sec(1);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(2,0,"B");
	delay_sec(1);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(2,0,"C");
	delay_sec(1);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(2,0,"D");
	delay_sec(1);
}


else if(bit_is_set(PINA,1)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(2,0,"E");
	delay_sec(1);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(2,0,"F");
	delay_sec(1);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(2,0,"G");
	delay_sec(1);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(2,0,"H");
	delay_sec(1);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(2,0,"1");
	delay_sec(1);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(2,0,"2");
	delay_sec(1);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(2,0,"3");
	delay_sec(1);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(2,0,"4");
	delay_sec(1);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(2,0,"5");
	delay_sec(1);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(2,0,"6");
	delay_sec(1);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(2,0,"7");
	delay_sec(1);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(2,0,"8");
	delay_sec(1);
}
}

void main()
{

lcd_init(underline);
lcd_clear();

DDRA=0xF0;
DDRB=0xFF;

while(1)
{
	cbi(PORTA,4);cbi(PORTA,5);cbi(PORTA,6);sbi(PORTA,7);
	check();
	cbi(PORTA,4);cbi(PORTA,5);sbi(PORTA,6);cbi(PORTA,7);
	check();
	cbi(PORTA,4);sbi(PORTA,5);cbi(PORTA,6);cbi(PORTA,7);
	check();
	sbi(PORTA,4);cbi(PORTA,5);cbi(PORTA,6);cbi(PORTA,7);
	check();
}
}