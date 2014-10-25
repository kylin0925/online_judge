#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define WIDTH 39
#define HEIGHT 24
#define BMAX 250
#define BMIN 50
#define DELAYTIME delay(220)
#define MOVE gotoxy(4,25);
class Character
{
 protected:
	int EN,AC,LK,HR,HP,HPmax,ENmax,ENmin,ACmax,ACmin,LKmax,LKmin,Total;
 public:
	void Set(void);
	int  FindBomb(int,int);
	void Cure(void);
	void CoutHP(void);
	void SetHP(void);
};
class Human:     public Character{ public:Human();     };
class Deathclaws:public Character{ public:Deathclaws();};
class Mutants:   public Character{ public:Mutants();   };
class Bomb
{
 private:
	int BR,AT;
	void Set(void);
 public:
	Bomb();
	void Get(int*,int*);
};
class Myst
{
 private:
	int map[WIDTH][HEIGHT],step;
	Character *p;
	Bomb bow;
	int Road(int,int);
	int Go  (int,int);
 public:
	Myst();
       ~Myst();
};
void main(void){ Myst s; }
void Character::Set(void)
{
 int esc=1,x[3],min[3],max[3],y=1,locate=0,temp=1;
 x[0]=min[0]=ENmin;
 x[1]=min[1]=ACmin;
 x[2]=min[2]=LKmin;
      max[0]=ENmax;
      max[1]=ACmax;
      max[2]=LKmax;
 clrscr();
 printf("-> EN:%02i(%02i-%02i)\n",x[0],ENmin,ENmax);
 printf("   AC:%02i(%02i-%02i)\n",x[1],ACmin,ACmax);
 printf("   LK:%02i(%02i-%02i)\n",x[2],LKmin,LKmax);
 printf("   EN+AC+LK=%i",Total);
 gotoxy(3,1);
 while(esc)
 {
	switch(getch())
	{
		case UP:   { temp=1;y--;if(y<1)y=3;locate=y-1; }break;
		case DOWN: { temp=1;y++;if(y>3)y=1;locate=y-1; }break;
		case LEFT: { temp=0;if( x[locate]>min[locate] )x[locate]--; }break;
		case RIGHT:{ temp=0;if( x[locate]<max[locate] &&
				      ( x[0]+x[1]+x[2])<Total )x[locate]++; }break;
		case ENTER:if((x[0]+x[1]+x[2])==Total)esc=0;
	}
	if(temp)
	{
		printf("\b\b  ");
		gotoxy(1,y);
		printf("->");
	}
	else
	{
		gotoxy(7,y);
		printf("%02i",x[locate]);
		gotoxy(3,y);
	}
 }
 EN=x[0];
 AC=x[1];
 LK=x[2];
 HPmax=HP=EN*5+20;
 if(EN<6)HR=1;
 else
 {
	if(EN<10)HR=2;
	else HR=3;
 }
}
int Character::FindBomb(int BR,int AT)
{
 if(BR>LK)
 {
	int temp=rand()%AC+1;
	temp=AT-temp;
	if(temp<=0)temp=1;
	HP-=temp;
	if(HP<0)HP=0;
	CoutHP();
 }
 return HP;
}
void Character::Cure(void)  { HP+=HR;if(HP>HPmax)HP=HPmax;CoutHP();}
void Character::CoutHP(void){ MOVE;printf("%2i",HP);}
void Character::SetHP(void) { MOVE;printf("\b\b\bHP:%2i/%2i",HP,HPmax);}
Human::Human()
{
 ENmax=ACmax=LKmax=10;
 ENmin=ACmin=LKmin=1;
 Total=15;
}
Deathclaws::Deathclaws()
{
 ENmax=12;ENmin=3;
 ACmax=15;ACmin=5;
 LKmax=6; LKmin=1;
 Total=20;
}
Mutants::Mutants()
{
 ENmax=15;ENmin=5;
 ACmax=12; ACmin=3;
 LKmax=4; LKmin=1;
 Total=19;
}
Bomb::Bomb() { Set(); }
void Bomb::Set(void)
{
 BR=(rand()%13)+1;
 AT=(rand()%8)+3;
}
void Bomb::Get(int *x,int *y)
{
 *x=BR;
 *y=AT;
 Set();
}
Myst::Myst()
{
 clrscr();
 _setcursortype(_NOCURSOR);
 srand(time(0));
 step=0;
 p=NULL;
 int a,b,c=1,d,e,esc=1,num=(BMAX+BMIN)/2,start;
 for(a=0;a<WIDTH;a++)
	for(b=0;b<HEIGHT;b++)
		map[a][b]=0;
 Road(rand()%(WIDTH -2)+1,rand()%(HEIGHT-2)+1);
 do
 {
	b=rand()%(HEIGHT-2)+1;
	if(map[1][b]==1)map[0][b]=1;
 }
 while(map[1][b]==0);
 start=b;
 do
 {
	b=rand()%(HEIGHT-2)+1;
	if(map[WIDTH-2][b]==1)map[WIDTH-1][b]=1;
 }
 while(map[WIDTH-2][b]==0);
 printf("-> Human\n");
 printf("   Dethclaws\n");
 printf("   Mutants");
 gotoxy(3,1);
 while(esc)
 {
	switch(getch())
	{
		case UP:   { c--;if(c<1)c=3; }break;
		case DOWN: { c++;if(c>3)c=1; }break;
		case ENTER:esc=0;
	}
	printf("\b\b  ");
	gotoxy(1,c);
	printf("->");
 }
 if(c==1)     p=new Human;
 else if(c==2)p=new Deathclaws;
 else if(c==3)p=new Mutants;
 if(p==NULL)return;
 p->Set();
 clrscr();
 printf("\n-> BOMB+1\n");
 printf("<- BOMB-1\n");
 printf("%c  BOMB+10\n",24);
 printf("%c  BOMB-10",25);
 gotoxy(1,1);
 printf("BOMB NUMBER(%i-%i):%3i",BMIN,BMAX,(BMAX+BMIN)/2);
 for(esc=1;esc==1;)
 {
	switch(getch())
	{
		case UP:   if(num<=BMAX-10)num+=10;break;
		case DOWN: if(num>=BMIN+10)num-=10;break;
		case LEFT: if(num> BMIN)num--;  break;
		case RIGHT:if(num< BMAX)num++;  break;
		case ENTER:esc=0;
	}
	printf("\b\b\b%3i",num);
 }
 for(c=0;c<num;c++)
 {
	d=rand()%(WIDTH-2)+1;
	e=rand()%(HEIGHT-2)+1;
	for(b=1;b<HEIGHT-1;b++)
	{
		for(a=1;a<WIDTH-1;a++)
		{
			if(map[d][e]==1)
			{
				map[d][e]=2;
				a=WIDTH;
				b=HEIGHT;
			}
			d++;
			if(d>WIDTH-2)
			{
				d=1;
				e++;
				if(e>HEIGHT-2)e=1;
			}
		}
	}
	if(a<WIDTH||b<HEIGHT)break;
 }
 textbackground(6);
 gotoxy(1,1);
 for(b=c=0,d=1;b<HEIGHT;b++)
 {
	for(a=0;a<WIDTH;a++)
	{
		if(map[a][b]==0)cprintf("%c%c",193+c,193+d);
		else if(map[a][b]==1)printf("  ");
		else if(map[a][b]==2)printf("%c%c",17,16);
	}
	printf("\n");
	if(c){ c=0;d=1; }
	else { c=1;d=0; }
 }
 p->SetHP();
 Go(0,start);
}
int Myst::Road (int x,int y)
{
 map[x][y]=1;
 int a,b,esc,d=rand()%4,re[4]={0,0,0,0};
 for(esc=0;esc<4;esc++)
 {
	while(re[d])d=rand()%4;
	switch(d)
	{
		case 0:{a=1; b=0; }break;
		case 1:{a=-1;b=0; }break;
		case 2:{a=0; b=1; }break;
		case 3:{a=0; b=-1;}break;
	}
	if(map[x+a][y+b]==0 && (x+a)<(WIDTH-1) &&
			       (x+a)>0         &&
			       (y+b)<(HEIGHT-1)&&
			       (y+b)>0)
	{
		if(d==0||d==1)
		{
			if(map[x+a*2][y]==0  &&
			   map[x+a*2][y-1]==0&&
			   map[x+a*2][y+1]==0&&
			   map[x+a][y-1]==0  &&
			   map[x+a][y+1]==0)if(Road(x+a,y+b))return 1;
		}
		else
		{
			if(map[x][y+b*2]==0  &&
			   map[x-1][y+b*2]==0&&
			   map[x+1][y+b*2]==0&&
			   map[x-1][y+b]==0  &&
			   map[x+1][y+b]==0)if(Road(x+a,y+b))return 1;
		}

	}
	re[d]=1;
 }
 return 0;
}
int Myst::Go(int x,int y)
{
 gotoxy(2*x+1,y+1);
 printf("%c%c",219,219);
 DELAYTIME;
 if(x==WIDTH-1)return 1;
 int a,b,c=1,temp;
 step++;
 if(step==6)
 {
	step=1;
	p->Cure();
 }
 if(map[x][y]==2)
 {
	bow.Get(&a,&b);
	if(p->FindBomb(a,b)==0)return 1;
 }
 map[x][y]=0;
 do
 {
	switch(c)
	{
		case 1:{a=1; b=0; }break;
		case 2:{a=0; b=1; }break;
		case 3:{a=-1;b=0; }break;
		case 4:{a=0; b=-1;}break;
	}
	if(x+a>0)if(map[x+a][y+b])
	{
		gotoxy(2*x+1,y+1);
		printf("  ");
		if(Go(x+a,y+b))return 1;
		else
		{
			step++;
			if(step==6)
			{
				step=1;
				p->Cure();
			}
			gotoxy(2*x+1,y+1);
			printf("%c%c",219,219);
			DELAYTIME;
		}
	}
	if(c==4)
	{
	       gotoxy(2*x+1,y+1);
	       printf("  ");
	       return 0;
	}
	c++;
 }while(1);
}
Myst::~Myst()
{
 delete p;
 _setcursortype(_NORMALCURSOR);
 textbackground(0);
}