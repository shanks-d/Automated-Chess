#include"sra.c"

#define a 1
#define b 2
#define c 3
#define d 4
#define e 5
#define f 6
#define g 7
#define h 8
#define pwm1a 252
#define pwm1b 248
#define pwm2 145

int moves=1, x_move=0, y_move=0;
int pawn=0, hrook=0, bishop=0, knight=0, queen_hrook=0, queen_bishop=0;
int  x1=0, x2=0, y1=0, y2=0, kill_white=0, kill_black=0, x_dir=0, y_dir=0;
float x0=9.5, y0=4.5, kill_white_x=0, kill_white_y=0.5, kill_black_x=9, kill_black_y=8.5;
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
	delay_sec(1);
	temp_lcd1++;
}

if(temp_lcd2!=0)
{
	lcd_clear();
	lcd_write_string_xy(0,0,"ENTER FINAL POS:");
	lcd_write_string_xy(3,1,"X:");
	lcd_write_string_xy(10,1,"Y:");
	temp_lcd2=0;
	delay_sec(1);
	temp_xy2++;
}

if(bit_is_set(PINA,0)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(5,1,"A");
	x=1;
	_delay_ms(500);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(5,1,"B");
	x=2;
	_delay_ms(500);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(5,1,"C");
	x=3;
	_delay_ms(500);
}

else if(bit_is_set(PINA,0)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(5,1,"D");
	x=4;
	_delay_ms(500);
}


else if(bit_is_set(PINA,1)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(5,1,"E");
	x=5;
	_delay_ms(500);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(5,1,"F");
	x=6;
	_delay_ms(500);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(5,1,"G");
	x=7;
	_delay_ms(500);
}

else if(bit_is_set(PINA,1)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(5,1,"H");
	x=8;
	_delay_ms(500);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(12,1,"1");
	y=1;
	_delay_ms(500);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(12,1,"2");
	y=2;
	_delay_ms(500);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(12,1,"3");
	y=3;
	_delay_ms(500);
}

else if(bit_is_set(PINA,2)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(12,1,"4");
	y=4;
	_delay_ms(500);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,4))
{
	lcd_write_string_xy(12,1,"5");
	y=5;
	_delay_ms(500);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,5))
{
	lcd_write_string_xy(12,1,"6");
	y=6;
	_delay_ms(500);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,6))
{
	lcd_write_string_xy(12,1,"7");
	y=7;
	_delay_ms(500);
}

else if(bit_is_set(PINA,3)&&bit_is_set(PINA,7))
{
	lcd_write_string_xy(12,1,"8");
	y=8;
	_delay_ms(500);
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
while(bit_is_clear(PIND,1))//set
{
	if(temp_bump==0)
	{
		lcd_write_string_xy(5,1,"MOVE UP");
		cbi(PORTC,0);
		sbi(PORTC,1);
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
		cbi(PORTC,0);
		sbi(PORTC,1);
	}
	temp_bump++;
}
sbi(PORTC,0);
sbi(PORTC,1);
_delay_ms(150);
temp_bump=0;
while(bit_is_clear(PIND,0))
{
	if(temp_bump==0)
	{
		lcd_clear();
		lcd_write_string_xy(5,0,"SHASHANK");
		sbi(PORTC,0);
		cbi(PORTC,1);
		//_delay_ms(30);
	}
	temp_bump++;
}
lcd_clear();
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
		sbi(PORTC,0);
		cbi(PORTC,1);
	}
	temp_bump++;
}
temp_bump=0;
while(bit_is_set(PIND,1))//clear
{
	if(temp_bump==0)
	{
		lcd_clear();
		lcd_write_string_xy(5,1,"MOVE DOWN");
		sbi(PORTC,0);
		cbi(PORTC,1);
	}
	temp_bump++;
}
lcd_clear();
sbi(PORTC,0);
sbi(PORTC,1);
cbi(PORTC,0);
cbi(PORTC,1);
}

void x_origin()
{
	set_pwm2(170);
	_delay_ms(100);
	while(bit_is_set(PINB,4))
	{
		cbi(PORTC,3);
		sbi(PORTC,2);
	}
	sbi(PORTC,3);
	sbi(PORTC,2);
	_delay_ms(100);
	cbi(PORTC,3);
	cbi(PORTC,2);
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
	
	val_x=0, count7=0, prev_val7=0, curr_val7=0, temp_pos_x=0;
	val_xe=0, temp_pos_xe=0, curr_val77=0, prev_val77=0, count77=0;
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
	
	val_y=0, count4=0, count5=0, prev_val4=0, prev_val5=0, curr_val4=0, curr_val5=0, temp_pos_x=0;
	temp_pos_y4=0, temp_pos_y5=0;
	val_y4=0, temp_pos_y44=0, curr_val44=0, prev_val44=0, count44=0;
	val_y5=0, temp_pos_y55=0, curr_val55=0, prev_val55=0, count55=0;
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
DDRB=0b11101111;
PORTB=0xFF;
DDRA=0xF0;

int chess[10][10]= {	{00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
						{00, 11, 12, 00, 00, 00, 00, 07, 18, 00},
						{00, 21, 12, 00, 00, 00, 00, 07, 28, 00},
						{00, 31, 12, 00, 00, 00, 00, 07, 38, 00},
						{00, 41, 12, 00, 00, 00, 00, 07, 48, 00},
						{00, 51, 12, 00, 00, 00, 00, 07, 58, 00},
						{00, 61, 12, 00, 00, 00, 00, 07, 68, 00},
						{00, 71, 12, 00, 00, 00, 00, 07, 78, 00},
						{00, 81, 12, 00, 00, 00, 00, 07, 88, 00},
						{00, 00, 00, 00, 00, 00, 00, 00, 00, 00},
					};

lcd_write_string_xy(4,0,"Press A");
lcd_write_string_xy(4,1,"TO START");

sbi(PORTA,4);
while(bit_is_clear(PINA,0)&&bit_is_set(PORTA,4))
{
}
cbi(PORTA,4);
while(1)
{
lcd_clear();

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
delay_sec(1);
lcd_clear();
if(chess[x1][y1]==00||((chess[x2][y2]!=00)&&(chess[x1][y1]==00)))		//EMPTY MOVE
{
	x2=x0;y2=y0;
	lcd_clear();
	lcd_write_string_xy(0,0,"EMPTY MOVE");
	goto END;
}	
if(chess[x2][y2]!=00)		//KILL
{
	if(moves%2==0)
	{
		lcd_write_string_xy(3,1,"KILL BLACK");
		kill_black=1;
		bishop=1;
	}
	else if(moves%2==1)
	{
		lcd_write_string_xy(3,1,"KILL WHITE");
		kill_white=1;
		bishop=1;
	}
}

if(chess[x1][y1]==12||chess[x1][y1]==07)			//PAWN
{
	if((y2-y1<=2||y1-y2<=2)&&x1==x2)
	{
		lcd_write_string_xy(6,0,"PAWN");
		pawn=1;
		chess[x2][y2]=chess[x1][y1];
		chess[x1][y1]=00;
	}
	else if((y2-y1==x2-x1)||(y2-y1==x1-x2)||(y1-y2==x2-x1)||(y1-y2==x1-x2))
	{
		lcd_write_string_xy(6,0,"PAWN");
		bishop=1;
		chess[x2][y2]=chess[x1][y1];
		chess[x1][y1]=00;
	}
	else
	{
		lcd_clear();
		lcd_write_string_xy(2,0,"INVALID MOVE");
		x2=x0;y2=y0;
		goto END;
	}
}

else if(chess[x1][y1]==11||chess[x1][y1]==81||chess[x1][y1]==18||chess[x1][y1]==88)		//HROOK
{
	if((x2==x1&&y2!=y1)||(y2==y1&&x2!=x1))
	{
		lcd_write_string_xy(6,0,"ROOK");
		hrook=1;
		chess[x2][y2]=chess[x1][y1];
		chess[x1][y1]=00;
	}
	else
	{
		lcd_clear();
		lcd_write_string_xy(2,0,"INVALID MOVE");
		x2=x0;y2=y0;
		goto END;
	}
}
	
else if(chess[x1][y1]==31||chess[x1][y1]==61||chess[x1][y1]==38||chess[x1][y1]==68)		//BISHOP
{
	if((y2-y1==x2-x1)||(y2-y1==x1-x2)||(y1-y2==x2-x1)||(y1-y2==x1-x2))
	{
		lcd_write_string_xy(5,0,"BISHOP");
		bishop=1;
		chess[x2][y2]=chess[x1][y1];
		chess[x1][y1]=00;
	}
	else
	{
		lcd_clear();
		lcd_write_string_xy(2,0,"INVALID MOVE");
		x2=x0;y2=y0;
		goto END;
	}
}		

else if(chess[x1][y1]==51||chess[x1][y1]==58)		//KING
{
	if((y2==y1&&x2!=x1)||(x2==x1&&y2!=y1))
	{
		lcd_write_string_xy(6,0,"KING");
		queen_hrook=1;
		chess[x2][y2]=chess[x1][y1];
		chess[x1][y1]=00;
	}
	else if((y2-y1==x2-x1)||(y2-y1==x1-x2)||(y1-y2==x2-x1)||(y1-y2==x1-x2))
	{
		lcd_write_string_xy(6,0,"KING");
		queen_bishop=1;
		chess[x2][y2]=chess[x1][y1];
		chess[x1][y1]=00;
	}
	else
	{
		lcd_clear();
		lcd_write_string_xy(2,0,"INVALID MOVE");
		x2=x0;y2=y0;
		goto END;
	}
}

else if(chess[x1][y1]==41||chess[x1][y1]==48)		//QUEEN
{
	if((y2==y1&&x2!=x1)||(x2==x1&&y2!=y1))
	{
		lcd_write_string_xy(5,0,"QUEEN");
		queen_hrook=1;
		chess[x2][y2]=chess[x1][y1];
		chess[x1][y1]=00;
	}
	else if((y2-y1==x2-x1)||(y2-y1==x1-x2)||(y1-y2==x2-x1)||(y1-y2==x1-x2))
	{
		lcd_write_string_xy(5,0,"QUEEN");
		queen_bishop=1;
		chess[x2][y2]=chess[x1][y1];
		chess[x1][y1]=00;
	}
	else
	{
		lcd_clear();
		lcd_write_string_xy(2,0,"INVALID MOVE");
		x2=x0;y2=y0;
		goto END;
	}
}
	
else if(chess[x1][y1]==21||chess[x1][y1]==71||chess[x1][y1]==28||chess[x1][y1]==78)		//KNIGHT
{
	if((x2-x1==2&&y2-y1==1)||(x2-x1==2&&y2-y1==-1)||(x2-x1==-2&&y2-y1==1)||(x2-x1==-2&&y2-y1==-1)||(x2-x1==1&&y2-y1==2)||(x2-x1==1&&y2-y1==-2)||(x2-x1==-1&&y2-y1==2)||(x2-x1==-1&&y2-y1==-2))
	{
		lcd_write_string_xy(5,0,"KNIGHT");
		bishop=1;
		chess[x2][y2]=chess[x1][y1];
		chess[x1][y1]=00;
	}
	else
	{
		lcd_clear();
		lcd_write_string_xy(2,0,"INVALID MOVE");
		x2=x0;y2=y0;
		goto END;
	}
}
_delay_ms(1000);
/*END:
y_dir=(4.5)*18;

x_origin();
lcd_clear();
lcd_write_string_xy(0,0,"Y");
delay_sec(1);
y_pos(y_dir);
delay_sec(1);
lcd_clear();
magnet_down();
delay_sec(100);
*/
if(kill_white==0&&kill_black==0)
{
switch((int)(x0-x1-0.5))
{
case 1:x_dir=(x1-x0)*16+2;break;
case 2:x_dir=(x1-x0)*16+1;break;
case 3:x_dir=(x1-x0)*16-1;break;
case 4:x_dir=(x1-x0)*16;break;
case 5:x_dir=(x1-x0)*16;break;
case 6:x_dir=(x1-x0)*16+3;break;
case 7:x_dir=(x1-x0)*16+3;break;
case 8:x_dir=(x1-x0)*16+1;break;
default:break;
}
switch(y1)
{
case 1:y_dir=(y1-y0)*16+7;break;
case 2:y_dir=(y1-y0)*16+6;break;
case 3:y_dir=(y1-y0)*16+4;break;
case 4:y_dir=(y1-y0)*16+4;break;
case 5:y_dir=(y1-y0)*16+3;break;
case 6:y_dir=(y1-y0)*16+4;break;
case 7:y_dir=(y1-y0)*16-3;break;
case 8:y_dir=(y1-y0)*16-3;break;
default:break;
}

AFTERKILL:
lcd_clear();
lcd_write_string_xy(1,0,"MOVE TO X1,Y1");
y_pos(y_dir);
_delay_ms(500);
x_pos(-x_dir);
_delay_ms(500);
magnet_up();
_delay_ms(500);
if(x2-x1>0)
{
	x_move=x2-x1;
}
else if(x2-x1<0)
{
	x_move=x1-x2;
}
else
{
	x_move=0;
}
switch(x_move)
{
case 1:x_dir=(x2-x1)*16+4;break;//-2
case 2:x_dir=(x2-x1)*16+1;break;//-1
case 3:x_dir=(x2-x1)*16-1;break;//-3
case 4:x_dir=(x2-x1)*16;break;//-3
case 5:x_dir=(x2-x1)*16;break;//-3
case 6:x_dir=(x2-x1)*16+3;break;//-5
case 7:x_dir=(x2-x1)*16+3;break;//-6
case 8:x_dir=(x2-x1)*16+1;break;//-6
default:break;
}
if(y2-y1>0)
{
	y_move=y2-y1;
}
else if(y1-y2<0)
{
	y_move=y1-y2;
}
else
{
	y_move=0;
}
switch(y_move)
{
case 1:y_dir=(y2-y1)*16-2;break;
case 2:y_dir=(y2-y1)*16-4;break;
case 3:y_dir=(y2-y1)*16+4;break;
case 4:y_dir=(y2-y1)*16+4;break;
case 5:y_dir=(y2-y1)*16+3;break;
case 6:y_dir=(y2-y1)*16+4;break;
case 7:y_dir=(y2-y1)*16-3;break;
case 8:y_dir=(y2-y1)*16-3;break;
default:break;
}

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
		x_pos(-x_dir);
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
			x_pos(-x_dir+8);
			_delay_ms(100);
			y_pos(y_dir-8);
			_delay_ms(100);
			x_pos(-10);
		}
		
		else
		{
			y_pos(8);
			_delay_ms(100);
			x_pos(-x_dir-8);
			_delay_ms(100);
			y_pos(y_dir-8);
			_delay_ms(100);
			x_pos(8);
		}
	}
	
	else
	{
		if(x_dir>0)
		{
			y_pos(-8);
			_delay_ms(100);
			x_pos(-x_dir+8);
			_delay_ms(100);
			y_pos(y_dir+8);
			_delay_ms(100);
			x_pos(-8);
		}
		
		else
		{
			y_pos(-8);
			_delay_ms(100);
			x_pos(-x_dir-8);
			_delay_ms(100);
			y_pos(y_dir+8);
			_delay_ms(100);
			x_pos(8);
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
	x_pos(-x_dir);
	_delay_ms(500);
	y_pos(y_dir);
	_delay_ms(500);
	magnet_up();
	_delay_ms(500);
	
	x_dir=(kill_white_x-x2)*16;
	y_dir=(kill_white_y-y2)*16;
	
	lcd_clear();
	lcd_write_string_xy(1,0,"GO TO KILL POS");
	lcd_write_string_xy(2,0,"WHITE PIECE");
	y_pos(8);
	_delay_ms(500);
	x_pos(-x_dir-8);
	_delay_ms(500);
	y_pos(y_dir-8);
	_delay_ms(500);
	x_pos(8);
	_delay_ms(500);
	magnet_down();
	_delay_ms(500);
	
	x_dir=(x1-kill_white_x)*16;
	y_dir=(y1-kill_white_y)*16;
	switch(x1)
	{
	case 1:x_dir=(x1)*16+2;break;
	case 2:x_dir=(x1)*16+1;break;
	case 3:x_dir=(x1)*16-1;break;
	case 4:x_dir=(x1)*16;break;
	case 5:x_dir=(x1)*16;break;
	case 6:x_dir=(x1)*16+3;break;
	case 7:x_dir=(x1)*16+3;break;
	case 8:x_dir=(x1)*16+1;break;
	default:break;
	}
	switch(y1)
	{
	case 1:y_dir=(y1-0.5)*16+7;break;
	case 2:y_dir=(y1-0.5)*16+6;break;
	case 3:y_dir=(y1-0.5)*16+4;break;
	case 4:y_dir=(y1-0.5)*16+4;break;
	case 5:y_dir=(y1-0.5)*16+3;break;
	case 6:y_dir=(y1-0.5)*16+4;break;
	case 7:y_dir=(y1-0.5)*16-3;break;
	case 8:y_dir=(y1-0.5)*16-3;break;
	default:break;
	}
	kill_white_y+=0.5;
	goto AFTERKILL;
}

else
{
	x_dir=(x2-x0)*16;
	y_dir=(y2-y0)*16;
	
	lcd_clear();
	lcd_write_string_xy(1,0,"MOVE TO X2,Y2");
	x_pos(-x_dir);
	_delay_ms(500);
	y_pos(y_dir);
	_delay_ms(500);
	magnet_up();
	_delay_ms(500);
	
	x_dir=(kill_black_x-x2)*16;
	y_dir=(kill_black_y-y2)*16;
	
	lcd_clear();
	lcd_write_string_xy(1,0,"GO TO KILL POS");
	lcd_write_string_xy(2,0,"BLACK PIECE");
	y_pos(-8);
	_delay_ms(500);
	x_pos(-x_dir+8);
	_delay_ms(500);
	y_pos(y_dir+8);
	_delay_ms(500);
	x_pos(-8);
	_delay_ms(500);
	magnet_down();
	_delay_ms(500);
	
	x_dir=(x1-kill_black_x)*16;
	y_dir=(y1-kill_black_y)*16;
	kill_black_y-=0.5;
	goto AFTERKILL;
}

}

END:
lcd_clear();
lcd_write_string_xy(1,0,"MOVE TO ORIGIN");
y_dir=(y0-y2)*16;

x_origin();
_delay_ms(100);
if(x2!=x0)
{
	x_pos(15);
}
_delay_ms(500);
y_pos(y_dir);
_delay_ms(500);

lcd_clear();
lcd_write_string_xy(6,0,"END");
delay_sec(1);
x_move=0, y_move=0;//moves++;
pawn=0, hrook=0, bishop=0, knight=0, queen_hrook=0, queen_bishop=0;
x1=0, x2=0, y1=0, y2=0, kill_white=0, kill_black=0, x_dir=0, y_dir=0;
x0=9.5, y0=4.5, kill_white_x=0, kill_white_y=0.5;
val_y=0, val_x=0, count4=0, count5=0, count7=0, prev_val4=0, prev_val5=0, prev_val7=0, curr_val4=0, curr_val5=0, curr_val7=0, temp_pos_x=0;
temp_bump=0;
val_y4=0, temp_pos_y44=0, curr_val44=0, prev_val44=0, count44=0;
val_y5=0, temp_pos_y55=0, curr_val55=0, prev_val55=0, count55=0;
val_xe=0, temp_pos_xe=0, curr_val77=0, prev_val77=0, count77=0;
x=0, y=0, temp_keys=0, temp_xy1=0, temp_xy2=0, temp_lcd1=0, temp_lcd2=0;
}
}