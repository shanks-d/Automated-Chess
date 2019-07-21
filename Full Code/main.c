#include"sra.c"

#define a 1
#define b 2
#define c 3
#define d 4
#define e 5
#define f 6
#define g 7
#define h 8
#define pwm1a 240
#define pwm1b 240
#define pwm2 150

int moves=0;	//Extra
int pawn=0, hrook=0, bishop=0, knight=0, queen_hrook=0, queen_bishop=0;	//Extra

int kill_white=0, kill_black=0, x_dir=0, y_dir=0;
float x0=4.5, y0=4.5, x1=0, x2=0, y1=0, y2=0, kill_white_x=0, kill_white_y=0.5, kill_black_x=9, kill_black_y=8.5;
int val_y=0, val_x=0, count4=0, count5=0, count7=0, prev_val4=0, prev_val5=0, prev_val7=0, curr_val4=0, curr_val5=0, curr_val7=0, temp_pos_x=0;
int temp_bump=0;
int val_y4=0, temp_pos_y44=0, curr_val44=0, prev_val44=0, count44=0;
int val_y5=0, temp_pos_y55=0, curr_val55=0, prev_val55=0, count55=0;
int val_xe=0, temp_pos_xe=0, curr_val77=0, prev_val77=0, count77=0;
int x=0, y=0, temp_keys=0, temp_xy1=0, temp_xy2=0, temp_lcd1=0, temp_lcd2=0;

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
	delay_sec(1);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(5,1,"B");
	x=2;
	delay_sec(1);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(5,1,"C");
	x=3;
	delay_sec(1);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(5,1,"D");
	x=4;
	delay_sec(1);
}


else if(bit_is_set(PINA,1)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(5,1,"E");
	x=5;
	delay_sec(1);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(5,1,"F");
	x=6;
	delay_sec(1);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(5,1,"G");
	x=7;
	delay_sec(1);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(5,1,"H");
	x=8;
	delay_sec(1);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(12,1,"1");
	y=1;
	delay_sec(1);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(12,1,"2");
	y=2;
	delay_sec(1);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(12,1,"3");
	y=3;
	delay_sec(1);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(12,1,"4");
	y=4;
	delay_sec(1);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(12,1,"5");
	y=5;
	delay_sec(1);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(12,1,"6");
	y=6;
	delay_sec(1);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(12,1,"7");
	y=7;
	delay_sec(1);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(12,1,"8");
	y=8;
	delay_sec(1);
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

void magnet_up()
{
lcd_clear();
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
sbi(PORTC,0);
sbi(PORTC,1);
cbi(PORTC,0);
cbi(PORTC,1);
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
sbi(PORTC,0);
sbi(PORTC,1);
cbi(PORTC,0);
cbi(PORTC,1);
}

void x_pos(int i)
{
	if(i==0)
	{
		val_x = 0;
		cbi(PORTC,3);
		cbi(PORTC,2);
		temp_pos_x = 1;
	}
	
	else if(i>0)
	{
		val_x = i;
		sbi(PORTC,3);
		cbi(PORTC,2);
	}
	
	else if(i<0)
	{
		val_x = -i;
		cbi(PORTC,3);
		sbi(PORTC,2);
	}

	if(bit_is_set(PIND,6))
	{
		prev_val7=1;
	}

	set_pwm2(pwm2);
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
	
	_delay_ms(100);
	lcd_clear();
	lcd_write_int_xy(7,0,count7,3);
	
	if(count7!=val_xe)
	{
		lcd_write_string_xy(4,1,"ERROR 7");
		_delay_ms(100);
		x_pos_error(val_x-count7);
	}
	
	lcd_clear();
	lcd_write_int_xy(7,1,count7-count77,3);
}

void x_pos_error(int m)
{
	if(m==0)
	{
		val_xe = 0;
		cbi(PORTC,3);
		cbi(PORTC,2);
	}
	
	else if(m>0)
	{
		val_xe = m;
		sbi(PORTC,3);
		cbi(PORTC,2);
	}
	
	else if(m<0)
	{
		val_xe = -m;
		cbi(PORTC,3);
		sbi(PORTC,2);
	}

	if(bit_is_set(PIND,6))
	{
		prev_val77=1;
	}

	set_pwm2(pwm2);
	lcd_clear();
	lcd_write_int_xy(7,0,val_xe,3);

	while(temp_pos_xe==0)
	{
		if(bit_is_set(PIND,6))
		{
			curr_val77=1;
		}
		
		if(bit_is_clear(PIND,6))
		{
			curr_val77=0;
		}
		
		if(prev_val77!=curr_val77)
		{
			count77++;
			lcd_write_int_xy(12,0,count77,3);
			prev_val77 = curr_val77;
		}
		
		if(count77==val_xe)
		{
			sbi(PORTC,2);
			sbi(PORTC,3);
			lcd_write_string_xy(9,1,"STOP");
			temp_pos_xe = 1;
		}
	}
	cbi(PORTC,2);
	cbi(PORTC,3);
}

void y_pos(int j)
{
	if(j==0)
	{
		val_y = 0;
		cbi(PORTC,4);
		cbi(PORTC,5);
		cbi(PORTC,6);
		cbi(PORTC,7);
	}
	
	else if(j>0)
	{
		val_y = j;
		sbi(PORTC,4);
		cbi(PORTC,5);
		sbi(PORTC,6);
		cbi(PORTC,7);
	}
	
	else if(j<0)
	{
		val_y = -j;
		cbi(PORTC,4);
		sbi(PORTC,5);
		cbi(PORTC,6);
		sbi(PORTC,7);
	}

	if(bit_is_set(PIND,2))
	{
		prev_val5=1;
	}
	if(bit_is_set(PIND,3))
	{
		prev_val4=1;
	}
	
	if(bit_is_clear(PIND,2))
	{
		prev_val5=0;
	}
	if(bit_is_clear(PIND,3))
	{
		prev_val4=0;
	}
	
	set_pwm1a(pwm1a);
	set_pwm1b(pwm1b);
	int  temp_pos_y4=0, temp_pos_y5=0;
	lcd_clear();
	lcd_write_int_xy(7,0,val_y,3);

	while(1)
	{	
		if(bit_is_set(PIND,3))
		{
			curr_val4=1;
		}
		if(bit_is_set(PIND,2))
		{
			curr_val5=1;
		}
		
		if(bit_is_clear(PIND,3))
		{
			curr_val4=0;
		}
		if(bit_is_clear(PIND,2))
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
			sbi(PORTC,4);
			sbi(PORTC,5);
			lcd_write_string_xy(2,1,"STOP");
			temp_pos_y4 = 1;
		}
		if(count5==val_y)
		{
			sbi(PORTC,6);
			sbi(PORTC,7);
			lcd_write_string_xy(11,1,"STOP");
			temp_pos_y5 = 1;
		}
		
		if(temp_pos_y4&temp_pos_y5)
		{
			break;
		}
	}
	
	_delay_ms(100);
	lcd_clear();
	lcd_write_int_xy(1,0,count4,3);
	lcd_write_int_xy(12,0,count5,3);
	
	cbi(PORTC,4);
	cbi(PORTC,5);
	cbi(PORTC,6);
	cbi(PORTC,7);
	
	if(count4!=val_y)
	{
		lcd_write_string_xy(0,1,"ERROR 4");
		_delay_ms(100);
		y4_pos(val_y-count4);
	}
	
	if(count5!=val_y)
	{
		lcd_write_string_xy(8,1,"ERROR 5");
		_delay_ms(100);
		y5_pos(val_y-count5);
	}
	
	lcd_clear();
	lcd_write_int_xy(2,1,count4-count44,3);
	lcd_write_int_xy(11,1,count5-count55,3);
}

void y4_pos(int k)
{
	if(k==0)
	{
		val_y4 = 0;
		cbi(PORTC,4);
		cbi(PORTC,5);
	}
	
	else if(k>0)
	{
		val_y4 = k;
		sbi(PORTC,4);
		cbi(PORTC,5);
	}
	
	else if(k<0)
	{
		val_y4 = -k;
		cbi(PORTC,4);
		sbi(PORTC,5);
	}

	if(bit_is_set(PIND,3))
	{
		prev_val44=1;
	}

	set_pwm1a(pwm1a);
	lcd_clear();
	lcd_write_int_xy(7,0,val_y4,3);
	
	while(temp_pos_y44==0)
	{
		if(bit_is_set(PIND,3))
		{
			curr_val44=1;
		}
		
		if(bit_is_clear(PIND,3))
		{
			curr_val44=0;
		}
		
		if(prev_val44!=curr_val44)
		{
			count44++;
			lcd_write_int_xy(2,0,count44,3);
			prev_val44 = curr_val44;
		}
		
		if(count44==val_y4)
		{
			sbi(PORTC,4);
			sbi(PORTC,5);
			lcd_write_string_xy(2,1,"STOP");
			temp_pos_y44 = 1;
		}
	}
	cbi(PORTC,4);
	cbi(PORTC,5);
}

void y5_pos(int l)
{
	if(l==0)
	{
		val_y5 = 0;
		cbi(PORTC,6);
		cbi(PORTC,7);
	}
	
	else if(l>0)
	{
		val_y5 = l;
		sbi(PORTC,6);
		cbi(PORTC,7);
	}
	
	else if(l<0)
	{
		val_y5 = -l;
		cbi(PORTC,6);
		sbi(PORTC,7);
	}

	if(bit_is_set(PIND,2))
	{
		prev_val55=1;
	}

	set_pwm1b(pwm1b);
	lcd_clear();
	lcd_write_int_xy(7,0,val_y5,3);
	
	while(temp_pos_y55==0)
	{
		if(bit_is_set(PIND,2))
		{
			curr_val55=1;
		}
		
		if(bit_is_clear(PIND,2))
		{
			curr_val55=0;
		}
		
		if(prev_val55!=curr_val55)
		{
			count55++;
			lcd_write_int_xy(12,0,count55,3);
			prev_val55 = curr_val55;
		}
		
		if(count55==val_y5)
		{
			sbi(PORTC,6);
			sbi(PORTC,7);
			lcd_write_string_xy(9,1,"STOP");
			temp_pos_y55 = 1;
		}
	}
	cbi(PORTC,6);
	cbi(PORTC,7);
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
PORTC=0x00;
DDRB=0xFF;
DDRA=0xF0;

lcd_write_string_xy(4,0,"Press A");
lcd_write_string_xy(4,1,"TO START");

sbi(PORTA,4);

while(bit_is_clear(PINA,0)&&bit_is_set(PORTA,4))
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

/*x_dir=(x2-x1)*16;
y_dir=(y2-y1)*16;

lcd_clear();
lcd_write_string_xy(0,0,"UP");
delay_sec(2);
magnet_up();
lcd_clear();
lcd_write_string_xy(0,0,"DOWN");
delay_sec(2);
magnet_down();
lcd_clear();
lcd_write_string_xy(0,0,"X");
delay_sec(2);
x_pos(x_dir);
lcd_clear();
lcd_write_string_xy(0,0,"Y");
delay_sec(2);
y_pos(y_dir);
_delay_ms(500);*/

if(kill_white==0&&kill_black==0)
{

x_dir=(x1-x0)*16;
y_dir=(y1-y0)*16;

AFTERKILL:
lcd_clear();
lcd_write_string_xy(1,0,"MOVE TO X1,Y1");
x_pos(x_dir);
_delay_ms(500);
y_pos(y_dir);
_delay_ms(500);
magnet_up();
_delay_ms(500);

x_dir=(x2-x1)*16;
y_dir=(y2-y1)*16;

lcd_clear();
lcd_write_string_xy(1,0,"MOVE TO X2,Y2");

if(pawn==1)
{
	y_pos(y_dir);
	_delay_ms(500);
	magnet_down();
}

else if(hrook==1||queen_hrook==1)
{
	if(x_dir==0)
	{
		y_pos(y_dir);
		_delay_ms(500);
	}
	
	else if(y_dir==0)
	{
		x_pos(x_dir);
		_delay_ms(500);
	}
	magnet_down();
}

else if(bishop==1||queen_bishop==1)
{
	if(y_dir>0)
	{
		if(x_dir>0)
		{
			y_pos(8);
			_delay_ms(100);
			x_pos(x_dir-8);
			_delay_ms(100);
			y_pos(y_dir-8);
			_delay_ms(100);
			x_pos(8);
		}
		
		else
		{
			y_pos(8);
			_delay_ms(100);
			x_pos(x_dir+8);
			_delay_ms(100);
			y_pos(y_dir-8);
			_delay_ms(100);
			x_pos(-8);
		}
	}
	
	else
	{
		if(x_dir>0)
		{
			y_pos(-8);
			_delay_ms(100);
			x_pos(x_dir-8);
			_delay_ms(100);
			y_pos(y_dir+8);
			_delay_ms(100);
			x_pos(8);
		}
		
		else
		{
			y_pos(-8);
			_delay_ms(100);
			x_pos(x_dir+8);
			_delay_ms(100);
			y_pos(y_dir+8);
			_delay_ms(100);
			x_pos(-8);
		}
	}
	magnet_down();
}

goto END;
}

else
{

if(moves%2==1)
{
	x_dir=(x2-x0)*16;
	y_dir=(y2-y0)*16;
	
	lcd_clear();
	lcd_write_string_xy(1,0,"MOVE TO X2,Y2");
	x_pos(x_dir);
	_delay_ms(500);
	y_pos(y_dir);
	_delay_ms(500);
	magnet_up();
	_delay_ms(500);
	
	x_dir=(kill_white_x-x2)*16;
	y_dir=(kill_white_y-y2)*16;
	kill_white_y+=0.5;
	
	lcd_clear();
	lcd_write_string_xy(1,0,"GO TO KILL POS");
	lcd_write_string_xy(2,0,"WHITE PIECE");
	y_pos(8);
	_delay_ms(500);
	x_pos(x_dir+8);
	_delay_ms(500);
	y_pos(y_dir-8);
	_delay_ms(500);
	x_pos(-8);
	_delay_ms(500);
	magnet_down();
	_delay_ms(500);
	
	x_dir=(x1-kill_white_x)*16;
	y_dir=(y1-kill_white_y)*16;
	goto AFTERKILL;
}

else
{
	x_dir=(x2-x0)*16;
	y_dir=(y2-y0)*16;
	
	lcd_clear();
	lcd_write_string_xy(1,0,"MOVE TO X2,Y2");
	x_pos(x_dir);
	_delay_ms(500);
	y_pos(y_dir);
	_delay_ms(500);
	magnet_up();
	_delay_ms(500);
	
	x_dir=(kill_black_x-x2)*16;
	y_dir=(kill_black_y-y2)*16;
	kill_black_y-=0.5;
	
	lcd_clear();
	lcd_write_string_xy(1,0,"GO TO KILL POS");
	lcd_write_string_xy(2,0,"BLACK PIECE");
	y_pos(-8);
	_delay_ms(500);
	x_pos(x_dir-8);
	_delay_ms(500);
	y_pos(y_dir+8);
	_delay_ms(500);
	x_pos(8);
	_delay_ms(500);
	magnet_down();
	_delay_ms(500);
	
	x_dir=(x1-kill_black_x)*16;
	y_dir=(y1-kill_black_y)*16;
	goto AFTERKILL;
}

}

END:
lcd_clear();
lcd_write_string_xy(1,0,"MOVE TO ORIGIN");
x_dir=(x0-x2)*16;
y_dir=(y0-y2)*16;
	
x_pos(x_dir);
_delay_ms(500);
y_pos(y_dir);
_delay_ms(500);

//lcd_clear();
lcd_write_string_xy(6,0,"END");

}