#include"sra.c"

void encoder(int a)
{
int count=1;
while(a|=0)
{
	if(bit_is_set(PIND,0))
	{
		while(bit_is_set(PIND,0))
		{
			motor_left_forward();
		}
		
		while(bit_is_clear(PIND,0));
		{
			motor_left_forward();
		}
		lcd_write_int_xy(count-1,0,count,2);
	}
	
	else if(bit_is_clear(PIND,0))
	{
		while(bit_is_clear(PIND,0))
		{
			motor_left_forward();
		}
		
		while(bit_is_set(PIND,0));
		{
			motor_left_forward();
		}
		lcd_write_int_xy(count-1,0,count,2);
	}
	
	a-=1;count+=1;
}

motor_stop();

}


void motor_left_forward()
{
	sbi(PORTC,4);
	cbi(PORTC,5);
	set_pwm1b(250);
}

void motor_right_forward()
{
	sbi(PORTC,6);
	cbi(PORTC,7);
	set_pwm1b(250);
}

void motor_left_backward()
{
	cbi(PORTC,4);
	sbi(PORTC,5);
	set_pwm1b(250);
}

void motor_right_backward()
{
	cbi(PORTC,6);
	sbi(PORTC,7);
	set_pwm1b(250);
}

void motor_stop()
{
	sbi(PORTC,4);
	sbi(PORTC,5);
	sbi(PORTC,6);
	sbi(PORTC,7);
	set_pwm1b(399);
}


void main()
{
pwm2_init();
DDRC=0xF0;
PORTC=0xF0;

lcd_init(underline);
lcd_clear();

DDRD=0xFF;
PORTD=0xF0;

DDRB=0xFF;

while(1)
{
	if(bit_is_set(PIND,2))
	{
		motor_left_forward();
		delay_sec(1);
		
		motor_left_backward();
		delay_sec(1);
		
		motor_right_forward();
		delay_sec(1);
		
		motor_right_backward();
		delay_sec(1);
		
		motor_stop();
	}
	
	else if(bit_is_set(PIND,3))
	{
		encoder(16);
	}
}
}
