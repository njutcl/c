#include<stdio.h>
#include<conio.h>
#include<windows.h>

int tone(char ch)
{int key[]={220, 246, 277 , 293 , 329 , 369 , 415 ,
	    440, 493, 554 , 587 , 659 , 739 , 830 ,
	    880, 987, 1108, 1174, 1318, 1479, 1661,
	    1760};
 switch(ch)
 {case 'z':
  case 'Z':return(key[0]); break;
  case 'x':
  case 'X':return(key[1]); break;
  case 'c':
  case 'C':return(key[2]); break;
  case 'v':
  case 'V':return(key[3]); break;
  case 'b':
  case 'B':return(key[4]); break;
  case 'n':
  case 'N':return(key[5]); break;
  case 'm':
  case 'M':return(key[6]); break;
  case 'a':
  case 'A':return(key[7]); break;
  case 's':
  case 'S':return(key[8]); break;
  case 'd':
  case 'D':return(key[9]); break;
  case 'f':
  case 'F':return(key[10]); break;
  case 'g':
  case 'G':return(key[11]); break;
  case 'h':
  case 'H':return(key[12]); break;
  case 'j':
  case 'J':return(key[13]); break;
  case 'q':
  case 'Q':return(key[14]); break;
  case 'w':
  case 'W':return(key[15]); break;
  case 'e':
  case 'E':return(key[16]); break;
  case 'r':
  case 'R':return(key[17]); break;
  case 't':
  case 'T':return(key[18]); break;
  case 'y':
  case 'Y':return(key[19]); break;
  case 'u':
  case 'U':return(key[20]); break;
  case '1':
  case '!':return(key[21]); break;
  default :return -1;
 }
}


void display(void)
{system("cls");
 printf("                                      . . . . . . . :\n");
 printf("          1-2-3-4-5-6-7-1-2-3-4-5-6-7-1-2-3-4-5-6-7-1\n");
 printf("          ^ ^ ^ ^ ^ ^ ^ \n");
 printf("          Z-X-C-V-B-N-M-A-S-D-F-G-H-J-Q-W-E-R-T-Y-U-1\n");
 printf("                       'Esc' to exit!\n");
}


int main()
{char ch;
 
 display();
 
 do
 {ch=getch();
  Beep(tone(ch),300);
 }while(ch!=27);

 return 0;
}
