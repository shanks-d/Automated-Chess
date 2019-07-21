#include"sra.c"

void main()
{
pwm1_init();
lcd_init(underline);
lcd_clear();

DDRC=0xFF;
PORTC=0x00;
DDRB=0xFF;
DDRD=0xF0;
PORTD=0xFF;
//DDRD=0b01110000;
//PORTD=0b11111111;
lcd_write_string_xy(5,0,"PRESS D0");

while(1)
{
if(bit_is_clear(PIND,0))
{
lcd_clear();
for(int i=0;i<300;i=i+5)
{
sbi(PORTC,4);
sbi(PORTC,6);
cbi(PORTC,5);
cbi(PORTC,7);

set_pwm1a(i);
set_pwm1b(i);
lcd_write_int_xy(5,0,i,3);
delay_sec(3);
}
}
}
}