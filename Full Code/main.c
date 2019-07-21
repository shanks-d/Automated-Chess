#include"sra.c"

int x_dir=0, y_dir=0;
float x0=4.5, y0=4.5, x=0, y=0, x1=0, x2=0, y1=0, y2=0;
int val_y=0, val_x=0, count4=0, count5=0, count7=0, prev_val4=0, prev_val5=0, prev_val7=0, curr_val4=0, curr_val5=0, curr_val7=0, temp_pos_x=0, temp_pos_y=0;
int temp_keys=0, temp_xy1=0, temp_xy2=0, temp_lcd1=0, temp_lcd2=0;
int temp_bump=0;

void magnet_up()
{
lcd_clear();
temp_bump=0;
while(bit_is_set(PIND,1))
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
while(bit_is_set(PIND,0))
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
lcd_clear();
temp_bump=0;
while(bit_is_clear(PIND,0))
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
while(bit_is_clear(PIND,1))
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

void x_pos(int b)
{
	if(b==0)
	{
		val_x = 0;
		cbi(PORTC,3);
		cbi(PORTC,2);
		temp_pos_x = 1;
	}
	
	else if(b>0)
	{
		val_x = b;
		sbi(PORTC,3);
		cbi(PORTC,2);
	}
	
	else if(b<0)
	{
		val_x = -b;
		cbi(PORTC,3);
		sbi(PORTC,2);
	}

	//val_x = b;

	if(bit_is_set(PIND,6))
	{
		prev_val7=1;
	}
	
	sbi(PORTC,3);
	cbi(PORTC,2);
	set_pwm2(150);
	lcd_clear();
	lcd_write_int_xy(7,0,val_x,3);

	while(temp_pos_x==0)
	{
		if(bit_is_set(PIND,6))
		{
			curr_val7=1;
		}
		
		if(bit_is_clear(PIND,6))
		{
			curr_val7=0;
		}
		
		if(prev_val7!=curr_val7)
		{
			count7++;
			lcd_write_int_xy(12,0,count7,3);
			prev_val7 = curr_val7;
		}
		
		if(count7==val_x)
		{
			sbi(PORTC,2);
			sbi(PORTC,3);
			lcd_write_string_xy(9,1,"STOP");
			temp_pos_x = 1;
		}
	}
	cbi(PORTC,2);
	cbi(PORTC,3);
}

void y_pos(int a)
{
	if(y1==y2)
	{
		val_y = 0;
		cbi(PORTC,4);
		cbi(PORTC,5);
		cbi(PORTC,6);
		cbi(PORTC,7);
		temp_pos_y = 1;
	}
	
	else if(a>0)
	{
		val_y = a;
		sbi(PORTC,4);
		cbi(PORTC,5);
		sbi(PORTC,6);
		cbi(PORTC,7);
	}
	
	else if(a<0)
	{
		val_y = -a;
		cbi(PORTC,4);
		sbi(PORTC,5);
		cbi(PORTC,6);
		sbi(PORTC,7);
	}
	
	//val_y = a;

	if(bit_is_set(PIND,3))
	{
		prev_val5=1;
	}
	
	if(bit_is_set(PIND,2))
	{
		prev_val4=1;
	}

	sbi(PORTC,4);
	cbi(PORTC,5);
	cbi(PORTC,7);
	sbi(PORTC,6);
	set_pwm1a(238);
	set_pwm1b(242);
	lcd_clear();
	lcd_write_int_xy(7,0,val_y,3);

	while(temp_pos_y==0)
	{
		if(bit_is_set(PIND,2))
		{
			curr_val4=1;
		}
		if(bit_is_set(PIND,3))
		{
			curr_val5=1;
		}
		
		if(bit_is_clear(PIND,2))
		{
			curr_val4=0;
		}
		if(bit_is_clear(PIND,3))
		{
			curr_val5=0;
		}
		
		if(prev_val4!=curr_val4)
		{
			count4++;
			lcd_write_int_xy(1,0,count4,3);
			prev_val4 = curr_val4;
		}
		if(prev_val5!=curr_val5)
		{
			count5++;
			lcd_write_int_xy(12,0,count5,3);
			prev_val5 = curr_val5;
		}
		
		if(count4==val_y)
		{
			sbi(PORTC,6);
			sbi(PORTC,7);
			lcd_write_string_xy(11,1,"STOP");
			//temp_pos_y = 1;
		}
		if(count5==val_y)
		{
			sbi(PORTC,4);
			sbi(PORTC,5);
			lcd_write_string_xy(2,1,"STOP");
			//temp_pos_y = 1;
		}
		
		if(count4==val_y&&count5==val_y)
		{
			temp_pos_y = 1;
		}
	}
	cbi(PORTC,4);
	cbi(PORTC,5);
	cbi(PORTC,6);
	cbi(PORTC,7);
}

void check()
{

if(temp_lcd1==0)
{
	lcd_clear();
	lcd_write_string_xy(0,0,"ENTER INIT POS:");
	lcd_write_string_xy(3,1,"X:");
	lcd_write_string_xy(10,1,"Y:");
	_delay_ms(500);
	temp_lcd1++;
}

if(temp_lcd2!=0)
{
	lcd_clear();
	lcd_write_string_xy(0,0,"ENTER FINAL POS:");
	lcd_write_string_xy(3,1,"X:");
	lcd_write_string_xy(10,1,"Y:");
	_delay_ms(500);
	temp_lcd2=0;
	temp_xy2++;
}

if(bit_is_set(PINA,0)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(5,1,"A");
	x=1;
	_delay_ms(100);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(5,1,"B");
	x=2;
	_delay_ms(100);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(5,1,"C");
	x=3;
	_delay_ms(100);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(5,1,"D");
	x=4;
	_delay_ms(100);
}


else if(bit_is_set(PINA,1)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(5,1,"E");
	x=5;
	_delay_ms(100);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(5,1,"F");
	x=6;
	_delay_ms(100);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(5,1,"G");
	x=7;
	_delay_ms(100);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(5,1,"H");
	x=8;
	_delay_ms(100);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(12,1,"1");
	y=1;
	_delay_ms(1000);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(12,1,"2");
	y=2;
	_delay_ms(1000);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(12,1,"3");
	y=3;
	_delay_ms(1000);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(12,1,"4");
	y=4;
	_delay_ms(1000);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(12,1,"5");
	y=5;
	_delay_ms(1000);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(12,1,"6");
	y=6;
	_delay_ms(1000);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(12,1,"7");
	y=7;
	_delay_ms(1000);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(12,1,"8");
	y=8;
	_delay_ms(1000);
}
	
if(x!=0&&y!=0)
{
	if(temp_xy1==0)
	{
		x1=x;y1=y;
		temp_xy1++;
		temp_lcd2++;
		x=0;y=0;
	}

	if(temp_xy2!=0)
	{
		x2=x;y2=y;
		temp_xy2++;
		temp_keys++;
	}
}

}

void main()
{

pwm2_init();
pwm1_init();

lcd_init(underline);
lcd_clear();

DDRD=0b10110000;
PORTD=0xFF;

DDRC=0xFF;
PORTC=0xFF;

DDRB=0xFF;

DDRA=0xF0;

lcd_write_string_xy(4,0,"Press A");
lcd_write_string_xy(4,1,"TO START");
sbi(PORTA,4);

while(bit_is_clear(PINA,0)&&bit_is_set(PINA,4))
{
}

while(temp_keys==0)
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

lcd_clear();
lcd_write_string_xy(1,0,"X1");lcd_write_string_xy(5,0,"Y1");
lcd_write_string_xy(10,0,"X2");lcd_write_string_xy(13,0,"Y2");
lcd_write_int_xy(1,1,x1,1);lcd_write_int_xy(5,1,y1,1);
lcd_write_int_xy(10,1,x2,1);lcd_write_int_xy(13,1,y2,1);
_delay_ms(1000);

x_dir=(x1-x0)*16;
y_dir=(y1-y0)*16;
	
x_pos(x_dir);
_delay_ms(500);
y_pos(y_dir);
_delay_ms(500);
magnet_up();

x_dir=(x2-x1)*16;
y_dir=(y2-y1)*16;

lcd_clear();
lcd_write_string_xy(6,0,"END");

}