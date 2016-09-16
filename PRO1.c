#include<stdlib.h>
#include<ctype.h>
#include<dos.h>
#include<graphics.h>
union REGS i,o;
char c[25][25],a[50];
int x,y,j;
float t;
void mouse();
void but();
void store(char []);
void process();
void button(int,int,int,int,char[]);
void main()
{
int gd=DETECT,gm,k=0,j;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
cleardevice();
setbkcolor(4);
setcolor(8);
but();
i.x.ax=1;
int86(51,&i,&i);
printf("\n\n\n\n\n\n\n\n\n\n\n");
while(1)
{
	mouse();
	k=strlen(a);
	if(x>50&&x<80&&y>0&&y<20)
	{
	printf("+");
	a[k++]='+';
	a[k]='\0';
	}
	if(x>50&&x<80&&y>35&&y<55)
	{
	printf("-");
	a[k++]='-';
	a[k]='\0';
	}
	if(x>50&&x<80&&y>70&&y<90)
	{
	printf("x");
	a[k++]='*';
	a[k]='\0';
	}
	if(x>50&&x<80&&y>105&&y<125)
	{
	printf("/");
	a[k++]='/';
	a[k]='\0';
	}
	if(x>50&&x<80&&y>140&&y<160)
	store(a);
	if(x>100&&x<160&&y>0&&y<20)
	{
	printf("1");
	a[k++]='1';
	a[k]='\0';
	}
	if(x>100&&x<160&&y>35&&y<55)
	{
	printf("2");
	a[k++]='2';
	a[k]='\0';
	}
	if(x>100&&x<160&&y>70&&y<90)
	{
	printf("3");
	a[k++]='3';
	a[k]='\0';
	}
	if(x>100&&x<160&&y>105&&y<125)
	{
	printf("4");
	a[k++]='4';
	a[k]='\0';
	}
	if(x>100&&x<160&&y>140&&y<160)
	{
	printf("5");
	a[k++]='5';
	a[k]='\0';
	}
	if(x>170&&x<230&&y>0&&y<20)
	{
	printf("6");
	a[k++]='6';
	a[k]='\0';
	}
	if(x>170&&x<230&&y>35&&y<55)
	{
	printf("7");
	a[k++]='7';
	a[k]='\0';
	}
	if(x>170&&x<230&&y>70&&y<90)
	{
	printf("8");
	a[k++]='8';
	a[k]='\0';
	}
	if(x>170&&x<230&&y>105&&y<125)
	{
	printf("9");
	a[k++]='9';
	a[k]='\0';
	}
	if(x>170&&x<230&&y>140&&y<160)
	{
	printf("0");
	a[k++]='0';
	a[k]='\0';
	}
	if(x>240&&x<300&&y>0&&y<20)
	{
	clrscr();
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	cleardevice();
	but();
	printf("\r");
	k=0;
	a[k]='\0';
	}
	if(x>240&&x<300&&y>35&&y<55)
	{
	exit('0');
	}
	if(x>240&&x<300&&y>70&&y<90)
	{
	printf("\b \b");
	k=k-1;
	a[k]='\0';
	}
	if(x>240&&x<300&&y>105&&y<125)
	{
	printf(".");
	a[k++]='.';
	a[k]='\0';
	}
	x=0;
	y=0;
	}
}
void button(int a,int b,int a2,int b2,char c[10])
{
int x,y;
for(x=a;x<a2+1;x++)
for(y=b;y<b2+1;y++)
putpixel(x,y,6);
setcolor(11);
rectangle(a,b,a2,b2);
outtextxy(a+10,b+10,c);
}
void mouse()
{
i.x.ax=5;
int86(51,&i,&o);
if(o.x.bx==1)
{
x=o.x.cx;
y=o.x.dx;
}
}
void but()
{
button(50,0,80,20,"+");
button(50,35,80,55,"-");
button(50,70,80,90,"x");
button(50,105,80,125,"/");
button(50,140,90,160,"ans");
button(100,0,160,20,"one");
button(100,35,160,55,"two");
button(100,70,160,90,"three");
button(100,105,160,125,"four");
button(100,140,160,160,"five");
button(170,0,230,20,"six");
button(170,35,230,55,"seven");
button(170,70,230,90,"eight");
button(170,105,230,125,"nine");
button(170,140,230,160,"zero");
button(240,0,300,20,"clear");
button(240,35,300,55,"exit");
button(240,70,300,90,"del");
button(240,105,300,125,".dot");
}
void store()
{
	int i=0,j=0,k;
	for(k=0,i=0,j=0;k<strlen(a);k++)
	{
	if(isdigit(a[k])||a[k]=='.'||(a[k]=='-'&&!isdigit(a[k-1])))
	{
	c[i][j++]=a[k];
	c[i][j]='\0';
	}
	else if(!isdigit(a[k])&&a[k]!='.'||(a[k]=='-'&&isdigit(a[k-1])))
	{
	j=0;
	i++;
	c[i][j]=a[k];
	c[i++][j+1]='\0';
	}
	}
	process();
}
void process()
{
float e,b;
e=atof(c[0]);
b=atof(c[2]);
switch(c[1][0])
{
case '+':
printf("=%0.2f",e+b);
sprintf(a,"%f",e+b);
break;
case '-':
printf("=%0.2f",e-b);
sprintf(a,"%f",e-b);
break;
case '*':
printf("=%0.2f",e*b);
sprintf(a,"%f",e*b);
break;
case '/':
if(b==0)
{
printf("infinity system cannot handle");
delay(5000);
exit('0');
}
else
{
printf("=%0.2f",e/b);
sprintf(a,"%f",e/b);
}
break;
}
}