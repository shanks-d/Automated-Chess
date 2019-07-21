#include "sra.c"

#define a 1
#define b 2
#define c 3
#define d 4
#define e 5
#define f 6
#define g 7
#define h 8

int x1,x2,y1,y2;			// EXTRA

int len, letter, file, rank, file0, rank0, color, moves=0;

//MOVES
int pawn=0, hrook=0, bishop=0, queen_hrook=0, queen_bishop=0, kill_white=0, kill_black=0;

//HROOK	H
int filew1=a, rankw1=1, filew8=h, rankw8=1, fileb1=a, rankb1=8, fileb8=h, rankb8=8;

//BISHOP B
int filew3=c, rankw3=1, filew6=f, rankw6=1, fileb3=c, rankb3=8, fileb6=f, rankb6=8, bc1_color=0, bf1_color=1, bc8_color=1, bf8_color=0;

//KING K
int filew5=e, rankw5=1, fileb5=e, rankb5=8, ke1_color=0, ke8_color=1;

//QUEEN Q
int filew4=d, rankw4=1, fileb4=d, rankb4=8, qd1_color=1, qd8_color=0;

//KNIGHT N
//int filew2=b, rankw2=1, filew7=g, rankw7=1, fileb2=b, rankb2=8, fileb7=g, rankb7=8;

void check_color()
{
	if(file%2==rank%2)
	{
		color=0;
	}
	if(file%2!=rank%2)
	{
		color=1;
	}
	
	if(filew5%2==rankw5%2)			//WHITE KING COLOR
	{
		ke1_color=0;
		
	}
	if(filew5%2!=rankw5%2)
	{
		ke1_color=1;
	}
	if(fileb5%2==rankb5%2)			//BLACK KING COLOR
	{
		ke8_color=0;
		
	}
	if(fileb5%2!=rankb5%2)
	{
		ke8_color=1;
	}
	 
	if(filew4%2==rankw4%2)			//WHITE QUEEN COLOR
	{
		qd1_color=0;
		
	}
	if(filew4%2!=rankw4%2)
	{
		qd1_color=1;
	}
	if(fileb4%2==rankb4%2)			//BLACK QUEEN COLOR
	{
		qd8_color=0;
		
	}
	if(fileb4%2!=rankb4%2)
	{
		qd8_color=1;
	}
}

void main()
{

lcd_init(underline);
lcd_clear();

DDRB=0xFF;

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
//moves++;
len=3;
letter=4;
file=c;rank=3;
//file0=d;rank0=5;

lcd_write_string_xy(5,0,"BEFORE");
lcd_write_int_xy(2,1,chess[d][5],2);
lcd_write_int_xy(12,1,chess[file][rank],2);
delay_sec(2);

if(len==2)
{
	pawn=1;
	if(moves%2==0)
	{
		if(chess[file][rank-1]==12)
		{
			x2=file;	y2=rank;
			x1=file;	y1=rank-1;
			chess[file][rank]=chess[file][rank-1];
			chess[file][rank-1]=00;
			
		}
		else if(chess[file][rank-2]==12)
		{
			x2=file;	y2=rank;
			x1=file;	y1=rank-2;
			chess[file][rank]=chess[file][rank-2];
			chess[file][rank-2]=00;
		}
	}
	
	else if(moves%2==1)
	{
		if(chess[file][rank+1]==07)
		{ 
			x2=file;	y2=rank;
			x1=file;	y1=rank+1;
			chess[file][rank]=chess[file][rank+1];
			chess[file][rank+1]=00;
		}
		else if(chess[file][rank+2]==07)
		{
			x2=file;	y2=rank;
			x1=file;	y1=rank+2;
			chess[file][rank]=chess[file][rank+2];
			chess[file][rank+2]=00;
		}
	}
	goto END;
}

else if(len==3)			//check the ASCII value of the letter
{
	if(letter==0)	//ASCII OF HROOK
	{
		HROOK:
		hrook=1;
		if(moves%2==0)
		{
			if(filew1==file&&rankw1!=rank)
			{
				x2=file;	x1=x2;
				y2=rank;	y1=rankw1;
				
				chess[file][rank]=chess[filew1][rankw1];
				chess[filew1][rankw1]=00;
				rankw1=rank;
			}
			else if(filew1!=file&&rankw1==rank)
			{
				x2=file;	x1=filew1;
				y2=rank;	y1=y2;
				
				chess[file][rank]=chess[filew1][rankw1];
				chess[filew1][rankw1]=00;
				filew1=file;
			}
			
			else if(filew8==file&&rankw8!=rank)
			{
				x2=file;	x1=x2;
				y2=rank;	y1=rankw8;
				
				chess[file][rank]=chess[filew8][rankw8];
				chess[filew8][rankw8]=00;
				rankw8=rank;
			}
			else if(filew8!=file&&rankw8==rank)
			{
				x2=file;	x1=filew8;
				y2=rank;	y1=y2;
				
				chess[file][rank]=chess[filew8][rankw8];
				chess[filew8][rankw8]=00;
				filew8=file;
			}
		}
		
		else if(moves%2==1)
		{
			if(fileb1==file&&rankb1!=rank)
			{
				x2=file;	x1=x2;
				y2=rank;	y1=rankb1;
				
				chess[file][rank]=chess[fileb1][rankb1];
				chess[fileb1][rankb1]=00;
				rankb1=rank;
			}
			else if(fileb1!=file&&rankb1==rank)
			{
				x2=file;	x1=fileb1;
				y2=rank;	y1=y2;
				
				chess[file][rank]=chess[fileb1][rankb1];
				chess[fileb1][rankb1]=00;
				fileb1=file;
			}
			
			else if(fileb8==file&&rankb8!=rank)
			{
				x2=file;	x1=x2;
				y2=rank;	y1=rankb8;
				
				chess[file][rank]=chess[fileb8][rankb8];
				chess[fileb8][rankb8]=00;
				rankb8=rank;
			}
			else if(fileb8!=file&&rankb8==rank)
			{
				x2=file;	x1=fileb8;
				y2=rank;	y1=y2;
				
				chess[file][rank]=chess[fileb8][rankb8];
				chess[fileb8][rankb8]=00;
				fileb8=file;
			}
		}
		goto END;
	}
	
	else if(letter==1)	//ASCII OF BISHOP
	{
		BISHOP:
		bishop=1;
		check_color();
		
		if(moves%2==0)							//WHITE BISHOP
		{
			if(color==bc1_color)
			{
				x2=rank;	x1=rankw3;
				y2=file;	y1=filew3;
				
				chess[file][rank]=chess[filew3][rankw3];
				chess[filew3][rankw3]=00;
				filew3=file;rankw3=rank;
			}
			else if(color==bf1_color)
			{
				x2=rank;	x1=rankw6;
				y2=file;	y1=filew6;
				chess[file][rank]=chess[filew6][rankw6];
				chess[filew6][rankw6]=00;
				filew6=file;rankw6=rank;
			}
		}
		
		else if(moves%2==1)							//BLACK BISHOP
		{
			if(color==bc8_color)
			{
				x2=rank;	x1=rankb3;
				y2=file;	y1=fileb3;
				
				chess[file][rank]=chess[fileb3][rankb3];
				chess[fileb3][rankb3]=00;
				fileb3=file;rankb3=rank;
			}
			else if(color==bf8_color)
			{
				x2=rank;	x1=rankb6;
				y2=file;	y1=fileb6;
				chess[file][rank]=chess[fileb6][rankb6];
				chess[fileb6][rankb6]=00;
				fileb6=file;rankb6=rank;
			}
		}
		goto END;
	}
	
	else if(letter==2)	//ASCII OF KING
	{
		KING:
		check_color();
		
		if(moves%2==0)
		{
			if(color!=ke1_color)						//WHITE KING as HROOK
			{
				queen_hrook=1;
				if(filew5==file&&rankw5!=rank)
				{
					x2=file;	x1=x2;
					y2=rank;	y1=rankw5;
					
					chess[file][rank]=chess[filew5][rankw5];
					chess[filew5][rankw5]=00;
					rankw5=rank;
				}
				else if(filew5!=file&&rankw5==rank)
				{
					x2=file;	x1=filew5;
					y2=rank;	y1=y2;
					
					chess[file][rank]=chess[filew5][rankw5];
					chess[filew5][rankw5]=00;
					filew5=file;
				}
			}
			
			else if(color==ke1_color)						//WHITE KING as BISHOP
			{
				queen_bishop=1;
				x2=rank;	x1=rankw5;
				y2=file;	y1=filew5;
				
				chess[file][rank]=chess[filew5][rankw5];
				chess[filew5][rankw5]=00;
				filew5=file;rankw5=rank;
			}
		}
		
		else if(moves%2==1)
		{
			if(color!=ke8_color)						//BLACK KING as HROOK
			{
				queen_hrook=1;
				if(fileb5==file&&rankb5!=rank)
				{
					x2=file;	x1=x2;
					y2=rank;	y1=rankb5;
					
					chess[file][rank]=chess[fileb5][rankb5];
					chess[fileb5][rankb5]=00;
					rankb5=rank;
				}
				else if(fileb5!=file&&rankb5==rank)
				{
					x2=file;	x1=fileb5;
					y2=rank;	y1=y2;
					
					chess[file][rank]=chess[fileb5][rankb5];
					chess[fileb5][rankb5]=00;
					fileb5=file;
				}
			}
			
			else if(color==ke8_color)						//BLACK KING as BISHOP
			{
				queen_bishop=1;
				x2=rank;	x1=rankb5;
				y2=file;	y1=fileb5;
				
				chess[file][rank]=chess[fileb5][rankb5];
				chess[fileb5][rankb5]=00;
				fileb5=file;rankb5=rank;
			}
		}
		goto END;
	}
	
	else if(letter==3)	//ASCII OF QUEEN
	{
		QUEEN:
		if(moves%2==0)
		{
			if(filew4==file&&rankw4!=rank)						//WHITE QUEEN as HROOK
			{
				queen_hrook=1;
				x2=file;	x1=x2;
				y2=rank;	y1=rankw4;
				
				chess[file][rank]=chess[filew4][rankw4];
				chess[filew4][rankw4]=00;
				rankw4=rank;
			}
			else if(filew4!=file&&rankw4==rank)
			{
				queen_hrook=1;
				x2=file;	x1=filew4;
				y2=rank;	y1=y2;
				
				chess[file][rank]=chess[filew4][rankw4];
				chess[filew4][rankw4]=00;
				filew4=file;
			}
			
			check_color();
			if(color==qd1_color)						//WHITE QUEEN as BISHOP
			{
				queen_bishop=1;
				if(filew4!=file&&rankw4!=rank)
				{
					x2=rank;	x1=rankw4;
					y2=file;	y1=filew4;
					
					chess[file][rank]=chess[filew4][rankw4];
					chess[filew4][rankw4]=00;
					filew4=file;rankw4=rank;
				}
			}
		}
		
		else if(moves%2==1)
		{
			if(fileb4==file&&rankb4!=rank)						//BLACK QUEEN as HROOK
			{
				queen_hrook=1;
				x2=file;	x1=x2;
				y2=rank;	y1=rankb4;
				
				chess[file][rank]=chess[fileb4][rankb4];
				chess[fileb4][rankb4]=00;
				rankb4=rank;
			}
			else if(fileb4!=file&&rankb4==rank)
			{
				queen_hrook=1;
				x2=file;	x1=fileb4;
				y2=rank;	y1=y2;
				
				chess[file][rank]=chess[fileb4][rankb4];
				chess[fileb4][rankb4]=00;
				fileb4=file;
			}
			
			check_color();
			if(color==qd8_color)						//BLACK QUEEN as BISHOP
			{
				queen_bishop=1;
				if(fileb4!=file&&rankb4!=rank)
				{
					x2=rank;	x1=rankb4;
					y2=file;	y1=fileb4;
					
					chess[file][rank]=chess[fileb4][rankb4];
					chess[fileb4][rankb4]=00;
					fileb4=file;rankb4=rank;
				}
			}
		}
		goto END;
	}
	
	else if(letter==4)						//KNIGHT
	{
		KNIGHT:
		bishop=1;
		if(moves%2==0)
		{
			if(chess[file-2][rank-1]==21)
			{
				x2=file;	x1=file-2;
				y2=rank;	y1=rank-1;
				chess[file][rank]=21;
				chess[file-2][rank-1]=00;
				goto FINISH;
			}
			
			else if(chess[file-2][rank-1]==71)
			{
				x2=file;	x1=file-2;
				y2=rank;	y1=rank-1;
				chess[file][rank]=71;
				chess[file-2][rank-1]=00;
				goto FINISH;
			}
			
			else if(chess[file-2][rank+1]==21)
			{
				x2=file;	x1=file-2;
				y2=rank;	y1=rank+1;
				chess[file][rank]=21;
				chess[file-2][rank+1]=00;
				goto FINISH;
			}
			
			else if(chess[file-2][rank+1]==71)
			{
				x2=file;	x1=file-2;
				y2=rank;	y1=rank+1;
				chess[file][rank]=71;
				chess[file-2][rank+1]=00;
				goto FINISH;
			}
			
			else if(chess[file+2][rank-1]==21)
			{
				x2=file;	x1=file+2;
				y2=rank;	y1=rank-1;
				chess[file][rank]=21;
				chess[file+2][rank-1]=00;
				goto FINISH;
			}
			
			else if(chess[file+2][rank-1]==71)
			{
				x2=file;	x1=file+2;
				y2=rank;	y1=rank-1;
				chess[file][rank]=71;
				chess[file+2][rank-1]=00;
				goto FINISH;
			}
			
			else if(chess[file+2][rank+1]==21)
			{
				x2=file;	x1=file+2;
				y2=rank;	y1=rank+1;
				chess[file][rank]=21;
				chess[file+2][rank+1]=00;
				goto FINISH;
			}
			
			else if(chess[file+2][rank+1]==71)
			{
				x2=file;	x1=file+2;
				y2=rank;	y1=rank+1;
				chess[file][rank]=71;
				chess[file+2][rank+1]=00;
				goto FINISH;
			}
			
			else if(chess[file-1][rank-2]==21)
			{
				x2=file;	x1=file-1;
				y2=rank;	y1=rank-2;
				chess[file][rank]=21;
				chess[file-1][rank-2]=00;
				goto FINISH;
			}
			
			else if(chess[file-1][rank-2]==71)
			{
				x2=file;	x1=file-1;
				y2=rank;	y1=rank-2;
				chess[file][rank]=71;
				chess[file-1][rank-2]=00;
				goto FINISH;
			}
			
			else if(chess[file+1][rank-2]==21)
			{
				x2=file;	x1=file+1;
				y2=rank;	y1=rank-2;
				chess[file][rank]=21;
				chess[file+1][rank-2]=00;
				goto FINISH;
			}
			
			else if(chess[file+1][rank-2]==71)
			{
				x2=file;	x1=file+1;
				y2=rank;	y1=rank-2;
				chess[file][rank]=71;
				chess[file+1][rank-2]=00;
				goto FINISH;
			}
			
			else if(chess[file-1][rank+2]==21)
			{
				x2=file;	x1=file-1;
				y2=rank;	y1=rank+2;
				chess[file][rank]=21;
				chess[file-1][rank+2]=00;
				goto FINISH;
			}
			
			else if(chess[file-1][rank+2]==71)
			{
				x2=file;	x1=file-1;
				y2=rank;	y1=rank+2;
				chess[file][rank]=71;
				chess[file-1][rank+2]=00;
				goto FINISH;
			}
			
			else if(chess[file+1][rank+2]==21)
			{
				x2=file;	x1=file+1;
				y2=rank;	y1=rank+2;
				chess[file][rank]=21;
				chess[file+1][rank+2]=00;
				goto FINISH;
			}
			
			else if(chess[file+1][rank+2]==71)
			{
				x2=file;	x1=file+1;
				y2=rank;	y1=rank+2;
				chess[file][rank]=71;
				chess[file+1][rank+2]=00;
				goto FINISH;
			}
		}
		
		else if(moves%2==1)
		{
			if(chess[file-2][rank-1]==28)
			{
				x2=file;	x1=file-2;
				y2=rank;	y1=rank-1;
				chess[file][rank]=28;
				chess[file-2][rank-1]=00;
				goto FINISH;
			}
			
			else if(chess[file-2][rank-1]==78)
			{
				x2=file;	x1=file-2;
				y2=rank;	y1=rank-1;
				chess[file][rank]=78;
				chess[file-2][rank-1]=00;
				goto FINISH;
			}
			
			else if(chess[file-2][rank+1]==28)
			{
				x2=file;	x1=file-2;
				y2=rank;	y1=rank+1;
				chess[file][rank]=28;
				chess[file-2][rank+1]=00;
				goto FINISH;
			}
			
			else if(chess[file-2][rank+1]==78)
			{
				x2=file;	x1=file-2;
				y2=rank;	y1=rank+1;
				chess[file][rank]=78;
				chess[file-2][rank+1]=00;
				goto FINISH;
			}
			
			else if(chess[file+2][rank-1]==28)
			{
				x2=file;	x1=file+2;
				y2=rank;	y1=rank-1;
				chess[file][rank]=28;
				chess[file+2][rank-1]=00;
				goto FINISH;
			}
			
			else if(chess[file+2][rank-1]==78)
			{
				x2=file;	x1=file+2;
				y2=rank;	y1=rank-1;
				chess[file][rank]=78;
				chess[file+2][rank-1]=00;
				goto FINISH;
			}
			
			else if(chess[file+2][rank+1]==28)
			{
				x2=file;	x1=file+2;
				y2=rank;	y1=rank+1;
				chess[file][rank]=28;
				chess[file+2][rank+1]=00;
				goto FINISH;
			}
			
			else if(chess[file+2][rank+1]==78)
			{
				x2=file;	x1=file+2;
				y2=rank;	y1=rank+1;
				chess[file][rank]=78;
				chess[file+2][rank+1]=00;
				goto FINISH;
			}
			
			else if(chess[file-1][rank-2]==28)
			{
				x2=file;	x1=file-1;
				y2=rank;	y1=rank-2;
				chess[file][rank]=28;
				chess[file-1][rank-2]=00;
				goto FINISH;
			}
			
			else if(chess[file-1][rank-2]==78)
			{
				x2=file;	x1=file-1;
				y2=rank;	y1=rank-2;
				chess[file][rank]=78;
				chess[file-1][rank-2]=00;
				goto FINISH;
			}
			
			else if(chess[file+1][rank-2]==28)
			{
				x2=file;	x1=file+1;
				y2=rank;	y1=rank-2;
				chess[file][rank]=28;
				chess[file+1][rank-2]=00;
				goto FINISH;
			}
			
			else if(chess[file+1][rank-2]==78)
			{
				x2=file;	x1=file+1;
				y2=rank;	y1=rank-2;
				chess[file][rank]=78;
				chess[file+1][rank-2]=00;
				goto FINISH;
			}
			
			else if(chess[file-1][rank+2]==28)
			{
				x2=file;	x1=file-1;
				y2=rank;	y1=rank+2;
				chess[file][rank]=28;
				chess[file-1][rank+2]=00;
				goto FINISH;
			}
			
			else if(chess[file-1][rank+2]==78)
			{
				x2=file;	x1=file-1;
				y2=rank;	y1=rank+2;
				chess[file][rank]=78;
				chess[file-1][rank+2]=00;
				goto FINISH;
			}
			
			else if(chess[file+1][rank+2]==28)
			{
				x2=file;	x1=file+1;
				y2=rank;	y1=rank+2;
				chess[file][rank]=28;
				chess[file+1][rank+2]=00;
				goto FINISH;
			}
			
			else if(chess[file+1][rank+2]==78)
			{
				x2=file;	x1=file+1;
				y2=rank;	y1=rank+2;
				chess[file][rank]=78;
				chess[file+1][rank+2]=00;
				goto FINISH;
			}
		}
		
		FINISH:
		lcd_clear();
	}
	goto END;
}

else if(len==5)
{
	if(letter==0)	//ASCII OF HROOK	
	{
		hrook=1;
		x2=file;	y2=rank;
		x1=file0;	y1=rank0;
		chess[file][rank]=chess[file0][rank0];
		chess[file0][rank0]=00;
	}
	
	if(letter==4)	//ASCII OF KNIGHT	
	{
		bishop=1;
		x2=file;	y2=rank;
		x1=file0;	y1=rank0;
		chess[file][rank]=chess[file0][rank0];
		chess[file0][rank0]=00;
	}
	goto END;
}

else if(len==4)
{
	/*if(secondlast_array_element==ASCII OF =)
	{*/
		if(letter==0)			//ASCII OF HROOK
		{
			if(moves%2==0)
			{
				kill_black=1;
			}
			
			else if(moves%2==1)
			{
				kill_white=1;
			}
			goto HROOK;
		}
		
		else if(letter==1)			//ASCII OF BISHOP
		{
			if(moves%2==0)
			{
				kill_black=1;
			}
			
			else if(moves%2==1)
			{
				kill_white=1;
			}
			goto BISHOP;
		}
		
		else if(letter==2)			//ASCII OF KING
		{
			if(moves%2==0)
			{
				kill_black=1;
			}
			
			else if(moves%2==1)
			{
				kill_white=1;
			}
			goto KING;
		}
		
		else if(letter==3)			//ASCII OF QUEEN
		{
			if(moves%2==0)
			{
				kill_black=1;
			}
			
			else if(moves%2==1)
			{
				kill_white=1;
			}
			goto QUEEN;
		}
		
		else if(letter==4)			//ASCII OF KNIGHT
		{
			if(moves%2==0)
			{
				kill_black=1;
			}
			
			else if(moves%2==1)
			{
				kill_white=1;
			}
			goto KNIGHT;
		}
		
		else
		{
			bishop=1;
			if(moves%2==0)
			{
				kill_black=1;
				x2=file;	y2=rank;
				x1=letter;	y1=rank-1;
				chess[file][rank]=chess[letter][rank-1];
				chess[letter][rank-1]=00;
			}
			
			else if(moves%2==1)
			{
				kill_white=1;
				x2=file;	y2=rank;
				x1=letter;	y1=rank+1;
				chess[file][rank]=chess[letter][rank+1];
				chess[letter][rank+1]=00;
			}
		}
	/*}
	
	else if(secondlast_array_element==ASCII OF =)
	{
		//first element of string is file, second is rank and last is letter
		if(moves%2==0)
		{
			x2=file;	y2=rank;
			x1=file;	y1=rank-1;
			
			if(letter==0)			//ASCII OF HROOK
			{
				chess[file][rank]=chess[
			}
			
			else if(letter==1)			//ASCII OF BISHOP
			{
				goto BISHOP;
			}
			
			else if(letter==3)			//ASCII OF QUEEN
			{
				goto QUEEN;
			}
			
			else if(letter==4)			//ASCII OF KNIGHT
			{
				goto KNIGHT;
			}
		}
		
		else if(moves%2==1)
		{
			x2=file;	y2=rank;
			x1=letter;	y1=rank+1;
			chess[file][rank]=chess[letter][rank+1];
			chess[letter][rank+1]=00;
		}
	}*/
	goto END;
}

else if(len==6)
{
	if(letter==0)	//ASCII OF HROOK	
	{
		if(moves%2==0)
		{
			kill_black=1;
		}
		
		else if(moves%2==1)
		{
			kill_white=1;
		}
		hrook=1;
		x2=file;	y2=rank;
		x1=file0;	y1=rank0;
		chess[file][rank]=chess[file0][rank0];
		chess[file0][rank0]=00;
	}
	
	if(letter==4)	//ASCII OF KNIGHT	
	{
		if(moves%2==0)
		{
			kill_black=1;
		}
		
		else if(moves%2==1)
		{
			kill_white=1;
		}
		bishop=1;
		x2=file;	y2=rank;
		x1=file0;	y1=rank0;
		chess[file][rank]=chess[file0][rank0];
		chess[file0][rank0]=00;
	}
	goto END;
}
	

END:
lcd_clear();
lcd_write_string_xy(5,0,"AFTER");
lcd_write_int_xy(2,1,chess[d][5],2);
lcd_write_int_xy(12,1,chess[file][rank],2);
delay_sec(2);
lcd_clear();
lcd_write_int_xy(2,0,x1,1);
lcd_write_int_xy(12,0,y1,1);
lcd_write_int_xy(2,1,x2,1);
lcd_write_int_xy(12,1,y2,1);

}