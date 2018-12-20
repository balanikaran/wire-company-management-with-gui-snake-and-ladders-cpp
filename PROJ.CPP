#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

void textmod();
void graphmod();
void menu();
void custmenu();
void boundary(int);
void welcome();
void products();
void enedmenu();
void table();
void cusrec();
void allrec();
void create();
void modify();
void deleter();
void loading();
void link();
void showresult(int);
/*


		     CODE STARTS FOR WIRE COMPANY



								       */
//#########################################################################
	    //class declaration

class wirecomp
{
  public:  int ccode,wcore,wcode,wlen;
	   char wtype[10],wcolor[10],cname[20],wsize[10];

	   void getdata();
	   int getccode();
};

      //class functions declaration

void wirecomp::getdata()
{
clrscr();
cout<<"\n\tCUSTOMER NAME:  ";
gets(cname);

clrscr();
cout<<"\n\tCUSTOMER CODE:  ";
cin>>ccode;


again:
clrscr();
cout<<"\n\t1 ->16/22 mm"<<endl;
cout<<"\t2 ->24/20 mm"<<endl;
cout<<"\t3 ->12/30 mm"<<endl;
cout<<"\t4 ->22/30 mm"<<endl;
cout<<"\t5 ->36/30 mm"<<endl;
cout<<"\t6 ->56/30 mm"<<endl;
cout<<"\n\tWIRE CODE(for size):  ";
cin>>wcode;
   switch(wcode)
   {
   case 1: strcpy(wsize,"16/22 mm");
	   break;
   case 2: strcpy(wsize,"24/20 mm");
	   break;
   case 3: strcpy(wsize,"12/30 mm");
	   break;
   case 4: strcpy(wsize,"22/30 mm");
	   break;
   case 5: strcpy(wsize,"36/30 mm");
	   break;
   case 6: strcpy(wsize,"56/30 mm");
	   break;
   default: cout<<"\n\twrong choice, try again...";
	    delay(500);
	    goto again;
   }

clrscr();
cout<<"\n\t-> '1' (single)";
cout<<"\n\t-> '2' (double)";
cout<<"\n\n\tWIRE CORE:  ";
cin>>wcore;

clrscr();
cout<<"\n\tWIRE LENGTH:  ";
cin>>wlen;

clrscr();
cout<<"\n\tWIRE COLOR:  ";
gets(wcolor);
}

int wirecomp::getccode()
{
return ccode;
}

//########################################################################
//########################################################################
void textmod()
{
closegraph();
}
//#######################################################################
void graphmod()
{
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\turboc3\\BGI");
}

//########################################################################
//########################################################################
void menu()
{
 graphmod();
again:
cleardevice();
 setcolor(BLUE);
 setbkcolor(2);
 boundary(1);
 settextstyle(1,0,4);
 setcolor(6);
 outtextxy(170,60,"***MAIN MENU***");
 settextstyle(TRIPLEX_FONT,0,2);
 setcolor(1);
 outtextxy(180,140,"1. CUSTOMER MENU");
 outtextxy(180,160,"2. ENTRY/EDIT MENU");
 outtextxy(180,180,"3. PRODUCT AND PRICE LIST");
 outtextxy(180,200,"4. EXIT");

 setcolor(5);
 outtextxy(170,260,"PRESS KEY OF YOUR CHOICE...");
 char ch=getch();

   switch(ch)
   {
    case '1': custmenu();
	      break;
    case '2': enedmenu();
	      break;
    case '3': products();
	      break;
    case '4': link();
	      break;
    default : setcolor(RED);
	      outtextxy(130,300,"WRONG CHOICE ENTERED, TRY AGAIN...");
	      delay(1000);
	      goto again;
   }

}
//##########################################################################
//##########################################################################
void custmenu()
{
  again:
   cleardevice();
   boundary(6);
   setbkcolor(15);
   settextstyle(SANS_SERIF_FONT,0,4);
   setcolor(6);
   outtextxy(170,80,"CUSTOMER MENU...");
   settextstyle(1,0,2);
   outtextxy(170,160,"1. VIEW ALL CUTOMERS RECORDS");
   outtextxy(170,180,"2. CUSTOMER RECORD");
   outtextxy(170,200,"3. BACK TO MAIN MENU");
   setcolor(5);
   outtextxy(170,240,"PRESS KEY OF YOUR CHOICE...");
    char ch=getch();

    switch(ch)
    {
      case '1':allrec();
	       break;
      case '2':cusrec();
	       break;
      case '3':menu();
	       break;
      default: setcolor(4);
	       outtextxy(130,280,"WRONG CHOICE ENTERED, TRY AGAIN...");
	       delay(1000);
	       goto again;
    }

}
//#########################################################################
//#########################################################################
void boundary(int c)
{
setcolor(c);
settextstyle(SANS_SERIF_FONT,0,2);
int i;
for(i=35;i<=590;i+=12)
outtextxy(i,20,"ß");
for(i=20;i<=430;i+=10)
outtextxy(590,i,"ß");
for(i=590;i>=35;i-=12)
outtextxy(i,430,"ß");
for(i=430;i>=20;i-=10)
outtextxy(35,i,"ß");
}
//########################################################################
//########################################################################
void welcome()
{

   graphmod();
   setbkcolor(5);
   settextstyle(TRIPLEX_FONT,0,4);
   outtextxy(35,20,"ßßß WELCOME TO WIRE COMPANY ßßß");

   for(int i=32;i<=430;i++)
   {
   outtextxy(35,i,"ß");
   outtextxy(585,i,"ß");
   delay(5);
   }

   for(i=35;i<=570;i++)
   {
   outtextxy(i,430,"ß");
   delay(5);
   }

   settextstyle(SANS_SERIF_FONT,0,2);
   outtextxy(200,200,"ENTER THE PASSWORD");

   char pass[]="karan007b",pas[9];

   for(i=0;i<9;i++)
   {
   pas[i]=getch();
   outtextxy(250+(i*10),250,"*");
   }

   int flag=1;
   for(i=0;i<9;i++)
   {
     if(pass[i]!=pas[i])
     flag=0;
   }

   if(flag==1)
   {
   menu();
   }
   else
   {
   outtextxy(200,400,"INCORRECT...(exiting)...");
   delay(1000);
   link();
   }

}
//########################################################################
//########################################################################
void products()
{
 cleardevice();
 setbkcolor(11);
 boundary(15);
 setcolor(1);
 settextstyle(3,0,4);
 outtextxy(180,80,"PRODUCTS LIST...");
 settextstyle(1,0,2);
 setcolor(4);
 outtextxy(50,160,"Sno.   SIZE   AREA  CURRENT  SINGLECORE  LENGTH");
 settextstyle(0,0,1);
 setcolor(2);
 outtextxy(50,200,"  1.    16/22mm    0.50        4 A             300            90m");
 outtextxy(50,220,"  2.    24/20mm    0.75        7 A             450            90m");
 outtextxy(50,240,"  3.    12/30mm    1.00       11 A             510            90m");
 outtextxy(50,260,"  4.    22/30mm    1.50       14 A             770            90m");
 outtextxy(50,280,"  5.    36/30mm    2.50       19 A            1200            90m");
 outtextxy(50,300,"  6.    56/30mm    4.00       26 A            1900            90m");
 setcolor(6);
 outtextxy(290,425,"PRESS ANY KEY TO GO BACK TO MAIN MENU");
 getch();
 menu();
}
//########################################################################
//########################################################################
void enedmenu()
{
 again:
  cleardevice();
  setbkcolor(1);
  boundary(3);
  settextstyle(3,0,4);
  outtextxy(170,80,"ENTRY/EDIT MENU...");
  settextstyle(1,0,2);
  outtextxy(170,140,"1. CREATE A NEW RECORD");
  outtextxy(170,160,"2. MODIFY AN EXISTING RECORD");
  outtextxy(170,180,"3. DELETE A RECORD");
  outtextxy(170,200,"4. BACK TO MAIN MENU");
   setcolor(5);
   outtextxy(170,240,"PRESS KEY OF YOUR CHOICE...");
    char ch=getch();

    switch(ch)
    {
      case '1':create();
	       break;
      case '2':modify();
	       break;
      case '3':deleter();
	       break;
      case '4':menu();
	       break;
      default: setcolor(4);
	       outtextxy(130,280,"WRONG CHOICE ENTERED, TRY AGAIN...");
	       delay(1000);
	       goto again;
    }
}
//########################################################################
//########################################################################
void table()
{
int i;
for(i=0;i<80;i++)
cout<<"#";
cout<<"  CNAME   |   CCODE   |   WCODE   |    WSIZE   |   WCORE   |   WLEN   |   WCOL"<<endl;
for(i=0;i<80;i++)
cout<<"#";
}
//##########################################################################
//##########################################################################
void cusrec()
{
  int c;

  ifstream fin;
  wirecomp p;

  fin.open("wirerec.dat",ios::binary|ios::in);
  if(!fin)
  {
   cout<<"\n\tFILE CAN'T BE OPENED...(EXITING)...";
   delay(200);
   exit(0);
  }
  else
  {
  textmod();
  loading();
  clrscr();
  cout<<"\n\tENTER THE CODE OF CUSTOMER WHOSE RECORD YOU WANT TO VIEW...\n\n\t\t\n\t";
  cin>>c;
  fin.read((char*)&p,sizeof(p));
    if(p.getccode()==c)
    {
    graphmod();
    cleardevice();
    setbkcolor(14);
    boundary(2);
    settextstyle(3,0,4);
    setcolor(8);
    outtextxy(80,50,"PARTICULAR CUSTOMER RECORD.");
    settextstyle(0,0,1);
    setcolor(4);
    outtextxy(150,140,"CUSTOMER NAME: ");
    outtextxy(150,180,"CUSTOMER CODE: ");
    outtextxy(150,220,"WIRE CODE: ");
    outtextxy(150,260,"WIRE SIZE: ");
    outtextxy(150,300,"WIRE CORE: ");
    outtextxy(150,340,"WIRE LENGTH: ");
    outtextxy(150,380,"WIRE COLOR: ");
    setcolor(1);
    outtextxy(400,140,p.cname);
       char cc[5];
       itoa(p.ccode,cc,10);
       outtextxy(400,180,cc);
	  char wc[5];
	  itoa(p.wcode,wc,10);
	  outtextxy(400,220,wc);
	     outtextxy(400,260,p.wsize);
		char wcr[5];
		itoa(p.wcore,wcr,10);
		outtextxy(400,300,wcr);
		   char wl[5];
		   itoa(p.wlen,wl,10);
		   outtextxy(400,340,wl);
		      outtextxy(400,380,p.wcolor);
    }

  }
  fin.close();
  getch();
  menu();
}
//##########################################################################
//##########################################################################

void allrec()
{ textmod();
  loading();
  clrscr();
  ifstream fin;
  wirecomp a;
  fin.open("wirerec.dat",ios::binary|ios::in);
   if(!fin)
   {
   cout<<"\n\tFILE CAN'T BE OPENED...(EXITING)...";
   delay(200);
   exit(0);
   }
   else
   {
   int i=4;
   table();
   while(!fin.eof())
   {

   fin.read((char*)&a,sizeof(a));
     if(!fin.eof())
     {
   gotoxy(2,i);
   cout<<a.cname;
   gotoxy(17,i);
   cout<<a.ccode;
   gotoxy(29,i);
   cout<<a.wcode;
   gotoxy(38,i);
   cout<<a.wsize;
   gotoxy(54,i);
   cout<<a.wcore;
   gotoxy(65,i);
   cout<<a.wlen;
   gotoxy(75,i);
   cout<<a.wcolor;
   i++;
   }
   }
   }
}
//#########################################################################
//#########################################################################
void create()
{
   textmod();
   loading();
   clrscr();
   wirecomp c;
   ofstream fout;
   fout.open("wirerec.dat",ios::binary|ios::app);
   if(!fout)
   {
   cout<<"\n\tFILE CAN'T BE OPENED...(EXITING)...";
   delay(200);
   exit(0);
   }
   else
   {
      c.getdata();
      fout.write((char*)&c,sizeof(c));
   }
     fout.close();
      cout<<"\n\tRECORD CREATED...!!!";
      cout<<"\n\tRETURNING TO MAIN MENU...";
      delay(700);
      graphmod();
      menu();
}
//########################################################################
//########################################################################
void modify()
{
  textmod();
  loading();
  clrscr();
  int c;


  wirecomp m;
  fstream f;
  f.open("wirerec.dat",ios::binary|ios::in|ios::app);
  if(!f)
   {
   cout<<"\n\tFILE CAN'T BE OPENED...(EXITING)...";
   delay(200);
   exit(0);
   }
   else
   {
   cout<<"\n\tENTER THE CUSTOMER CODE TO MODIFY:  ";
   cin>>c;
      while(f)
      {
       f.read((char*)&m,sizeof(m));
       if(m.getccode()==c)
       {
	m.getdata();
	f.seekp(-1*sizeof(m),ios::cur);
	f.write((char*)&m,sizeof(m));
	break;
       }
      }
   }
   f.close();
   cout<<"\n\tDATA SUCCESSFULLY MODIFIED...";
   cout<<"\n\tRETURNING TO MAIN MENU...";
   delay(500);
   graphmod();
   menu();
}
//##########################################################################
//##########################################################################
void deleter()
{
  textmod();
  loading();
  clrscr();
  wirecomp d;
  ifstream fin;
  ofstream fout;
  int c;
  fin.open("wirerec.dat",ios::binary|ios::in);
  fout.open("temp.dat",ios::binary|ios::out);
  if(!fin)
   {
   cout<<"\n\tFILE CAN'T BE OPENED...(EXITING)...";
   delay(200);
   exit(0);
   }
   else
   {
    cout<<"\n\tENTER THE CUSTOMER CODE TO DELETE:  ";
    cin>>c;
      while(fin)
      {
      fin.read((char*)&d,sizeof(d));
      if(d.getccode()!=c)
      {
	fout.write((char*)&d,sizeof(d));
      }
      }
   }
   fout.close();
   fin.close();
   remove("wirerec.dat");
   rename("temp.dat","wirerec.dat");
   cout<<"\n\tRECORD DELETED...!!!";
   cout<<"\n\tRETURNING TO MAIN MENU...";
   delay(500);
   menu();
}
//#########################################################################
//#########################################################################
/*


			 CODE ENDS FOR WIRE COMPANY


									  */
//**************************************************************************
//##########################################################################

//##########################################################################
//##########################################################################
//##########################################################################
/*

		   CODE STARTS FO SNAKE AND LADDERS GAME


									  */
//##########################################################################


void ipad()
{
    setbkcolor(3);
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    sector(50,50,90,180,40,40);
    sector(590,50,0,90,40,40);
    sector(50,430,180,270,40,40);
    sector(590,430,270,360,40,40);

    bar(10,50,50,430);
    bar(50,10,590,50);
    bar(590,50,630,430);
    bar(50,430,590,470);

    setfillstyle(SOLID_FILL,13);
    bar(50,50,590,430);

    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL,DARKGRAY);
    sector(320,450,0,360,15,15);

    setcolor(15);
    rectangle(315,445,325,455);

    setcolor(DARKGRAY);
    sector(320,25,0,360,6,6);

    bar(305,40,335,43);
}
//#####################################################################
//#####################################################################
void outerbox()
{
   line(70,70,560,70);
   line(560,70,560,410);
   line(560,410,70,410);
   line(70,410,70,70);
}
//#####################################################################
//#####################################################################
void innerbox()
{
   line(80,80,400,80);
   line(400,80,400,400);
   line(400,400,80,400);
   line(80,400,80,80);

}
//#####################################################################
//#####################################################################
void divisions()
{
 int i;
   for(i=80;i<360;i+=32)
   {
   line(i+32,80,i+32,400);
   }

   for(i=80;i<368;i+=32)
   {
   line(80,i+32,400,i+32);
   }

}
//#####################################################################
//#####################################################################
void counting()
{
   setcolor(15);
   int i;

   int a=1,j,z,b=100;

   for(j=384,z=1;j>=91,z<=10;j-=32,z++)
   {
   if(z%2!=0)
   {
   for(i=91;i<=384;i+=32)
   {
   char p[10];
   itoa(a,p,10);

   moveto(i,j);
   outtext(p);

   a+=1;
   }
   a+=10;
   }

   }

   b=100;
   for(j=91,z=1;j<=384,z<=10;j+=33,z++)
   {
   if(z%2==1)
   {
   for(i=87;i<=384;i+=32)
   {
   char p[10];
   itoa(b,p,10);

   moveto(i,j);
   outtext(p);

   b--;
   }
   b-=10;
   }
   }

}
//#####################################################################
//#####################################################################
void snake()
{
  int i;
  setlinestyle(SOLID_LINE,0,3);
  setcolor(4);
  int x=107,y=383;
  for(i=1;i<=9;i++)
     {
      if(i%2!=0)
	{
	 line(x,y,x+15,y);
	 x+=15;
	}

      else
	{
	 line(x,y,x,y-15);
	 y-=15;
	}

     }



  x=290,y=185;
  for(i=1;i<=9;i++)
     {
      if(i%2!=0)
	{
	 line(x,y,x+5,y);
	 x+=5;
	}

      else
	{
	 line(x,y,x,y-15);
	 y-=15;
	}

     }



  x=340,y=310;
  for(i=1;i<=15;i++)
     {
      if(i%2!=0)
	{
	 line(x,y,x+5,y);
	 x+=5;
	}

      else
	{
	 line(x,y,x,y-15);
	 y-=15;
	}

     }

     x=130; y=100;
     for(i=1;i<=20;i++)
     {
	if(i%2!=0)
	{
	line(x,y,x+13,y);
	x+=13;
	}

	else
	{
	line(x,y,x,y+27);
	y+=27;
	}

	}


     x=260; y=233;
     for(i=1;i<=8;i++)
     {
	if(i%2!=0)
	{
	line(x,y,x+13,y);
	x+=13;
	}

	else
	{
	line(x,y,x,y+27);
	y+=27;
	}

	}

}
//####################################################################
//####################################################################
void android()
{
    cleardevice();
    ipad();
setfillstyle(SOLID_FILL,2);
  setcolor(2);

      bar(200,200,220,270);    	           //left arm
      delay(100);
      bar(230,180,370,320);                //tummy
      delay(100);
      bar(380,200,400,270);                //right arm
      delay(100);
      bar(250,320,280,360);                //left leg
      delay(100);
      bar(318,320,348,360);                //right leg
      delay(100);
      sector(210,270,180,360,10,10);       //left arm lower curve
      delay(100);
      sector(210,200,0,180,10,10);         //left arm upper curve
      delay(100);
      sector(390,270,180,360,10,10);       //right arm lower curve
      delay(100);
      sector(390,200,0,180,10,10);         //right arm upper curve
      delay(100);
      sector(265,360,180,360,15,15);       //left leg curve
      delay(100);
      sector(333,360,180,360,15,15);       //right leg curve
      delay(100);
      sector(300,170,0,180,70,60);         //head

   setlinestyle(SOLID_LINE,1,3);
      line(255,100,265,120);               //left antena
      delay(100);
      line(350,100,340,120);               //right antena
      delay(100);

   setlinestyle(SOLID_LINE,1,1);
   setfillstyle(SOLID_FILL,15);
      fillellipse(270,145,6,6);            //left eye
      delay(100);
      fillellipse(320,145,6,6);            //right eye
      delay(100);
      setcolor(15);
      outtextxy(250,280,"BYE BYE...!!!");
      delay(800);
      exit(1);

}
//####################################################################
//####################################################################
void ladders()
{
   setlinestyle(SOLID_LINE,1,3);
   setcolor(2);
   {line(310,380,375,280);
   line(325,390,390,290);
   line(328,350,340,360);
   line(343,330,358,337);
   line(360,305,377,314);}


   {
   line(250,190,280,130);
   line(265,200,295,135);
   line(257,175,275,180);
   line(272,145,287,150);
   }

   {
   line(91,135,120,250);
   line(107,128,138,245);
   line(93,147,110,140);
   line(101,177,119,170);
   line(110,215,127,208);
   }

   {
   line(180,100,245,350);
   line(200,100,265,350);
   line(186,120,204,115);
   line(192,150,213,145);
   line(200,180,220,175);
   line(208,210,228,205);
   line(216,240,236,235);
   line(228,280,248,275);
   line(235,317,255,310);
   }

}
//#####################################################################
//#####################################################################
void dice()
{
setcolor(15);
setfillstyle(SOLID_FILL,8);
bar3d(440,110,500,170,25,1);
}
//#####################################################################
//#####################################################################
void chance()
{
setfillstyle(SOLID_FILL,8);
bar(410,180,550,210);
}
//#####################################################################
//#####################################################################
void playercolor()
{
outtextxy(430,230,"Player 1    Z");
setfillstyle(SOLID_FILL,1);
fillellipse(515,233,7,7);
outtextxy(430,255,"Player 2    M");
setfillstyle(SOLID_FILL,14);
fillellipse(515,258,7,7);
}
//#####################################################################
//#####################################################################
void resultbox()
{
setfillstyle(SOLID_FILL,DARKGRAY);
bar(410,275,550,390);
outtextxy(436,290,"RESULT BOX");
}
//#####################################################################
//#####################################################################
void putdiceno(int ran)
{
char put[2];
itoa(ran,put,10);
outtextxy(465,140,put);
}
//#####################################################################
//#####################################################################
void showchancep1()
{
outtextxy(446,193,"PLAYER 1");
}
//#####################################################################
//#####################################################################
void showchancep2()
{
outtextxy(446,193,"PLAYER 2");
}
//####################################################################
//####################################################################
void remp1(int p1)
{
  setcolor(13);
  setlinestyle(SOLID_LINE,1,1);
  setfillstyle(SOLID_FILL,13);

      switch(p1)
      {
      case 0: break;
      case 1: fillellipse(88,374,3,3);
	      break;
      case 2: fillellipse(120,374,3,3);
	      break;
      case 3: fillellipse(152,374,3,3);
	      break;
      case 4: fillellipse(184,374,3,3);
	      break;
      case 5: fillellipse(216,374,3,3);
	      break;
      case 6: fillellipse(248,374,3,3);
	      break;
      case 7: fillellipse(280,374,3,3);
	      break;
      case 8: fillellipse(312,374,3,3);
	      break;
      case 9: fillellipse(344,374,3,3);
	      break;
      case 10:fillellipse(376,374,3,3);
	      break;
      case 11:fillellipse(376,342,3,3);
	      break;
      case 12:fillellipse(344,342,3,3);
	      break;
      case 13:fillellipse(312,342,3,3);
	      break;
      case 14:fillellipse(280,342,3,3);
	      break;
      case 15:fillellipse(248,342,3,3);
	      break;
      case 16:fillellipse(216,342,3,3);
	      break;
      case 17:fillellipse(184,342,3,3);
	      break;
      case 18:fillellipse(152,342,3,3);
	      break;
      case 19:fillellipse(120,342,3,3);
	      break;
      case 20:fillellipse(88,342,3,3);
	      break;
      case 21:fillellipse(88,310,3,3);
	      break;
      case 22:fillellipse(120,310,3,3);
	      break;
      case 23:fillellipse(152,310,3,3);
	      break;
      case 24:fillellipse(184,310,3,3);
	      break;
      case 25:fillellipse(216,310,3,3);
	      break;
      case 26:fillellipse(248,310,3,3);
	      break;
      case 27:fillellipse(280,310,3,3);
	      break;
      case 28:fillellipse(312,310,3,3);
	      break;
      case 29:fillellipse(344,310,3,3);
	      break;
      case 30:fillellipse(376,310,3,3);
	      break;
      case 31:fillellipse(376,278,3,3);
	      break;
      case 32:fillellipse(344,278,3,3);
	      break;
      case 33:fillellipse(312,278,3,3);
	      break;
      case 34:fillellipse(280,278,3,3);
	      break;
      case 35:fillellipse(248,278,3,3);
	      break;
      case 36:fillellipse(216,278,3,3);
	      break;
      case 37:fillellipse(184,278,3,3);
	      break;
      case 38:fillellipse(152,278,3,3);
	      break;
      case 39:fillellipse(120,278,3,3);
	      break;
      case 40:fillellipse(88,278,3,3);
	      break;
      case 41:fillellipse(88,246,3,3);
	      break;
      case 42:fillellipse(120,246,3,3);
	      break;
      case 43:fillellipse(152,246,3,3);
	      break;
      case 44:fillellipse(184,246,3,3);
	      break;
      case 45:fillellipse(216,246,3,3);
	      break;
      case 46:fillellipse(248,246,3,3);
	      break;
      case 47:fillellipse(280,246,3,3);
	      break;
      case 48:fillellipse(312,246,3,3);
	      break;
      case 49:fillellipse(344,246,3,3);
	      break;
      case 50:fillellipse(376,246,3,3);
	      break;
      case 51:fillellipse(376,214,3,3);
	      break;
      case 52:fillellipse(344,214,3,3);
	      break;
      case 53:fillellipse(312,214,3,3);
	      break;
      case 54:fillellipse(280,214,3,3);
	      break;
      case 55:fillellipse(248,214,3,3);
	      break;
      case 56:fillellipse(216,214,3,3);
	      break;
      case 57:fillellipse(184,214,3,3);
	      break;
      case 58:fillellipse(152,214,3,3);
	      break;
      case 59:fillellipse(120,214,3,3);
	      break;
      case 60:fillellipse(88,214,3,3);
	      break;
      case 61:fillellipse(88,182,3,3);
	      break;
      case 62:fillellipse(120,182,3,3);
	      break;
      case 63:fillellipse(152,182,3,3);
	      break;
      case 64:fillellipse(184,182,3,3);
	      break;
      case 65:fillellipse(216,182,3,3);
	      break;
      case 66:fillellipse(248,182,3,3);
	      break;
      case 67:fillellipse(280,182,3,3);
	      break;
      case 68:fillellipse(312,182,3,3);
	      break;
      case 69:fillellipse(344,182,3,3);
	      break;
      case 70:fillellipse(376,182,3,3);
	      break;
      case 71:fillellipse(376,150,3,3);
	      break;
      case 72:fillellipse(344,150,3,3);
	      break;
      case 73:fillellipse(312,150,3,3);
	      break;
      case 74:fillellipse(280,150,3,3);
	      break;
      case 75:fillellipse(248,150,3,3);
	      break;
      case 76:fillellipse(216,150,3,3);
	      break;
      case 77:fillellipse(184,150,3,3);
	      break;
      case 78:fillellipse(152,150,3,3);
	      break;
      case 79:fillellipse(120,150,3,3);
	      break;
      case 80:fillellipse(88,150,3,3);
	      break;
      case 81:fillellipse(88,118,3,3);
	      break;
      case 82:fillellipse(120,118,3,3);
	      break;
      case 83:fillellipse(152,118,3,3);
	      break;
      case 84:fillellipse(184,118,3,3);
	      break;
      case 85:fillellipse(216,118,3,3);
	      break;
      case 86:fillellipse(248,118,3,3);
	      break;
      case 87:fillellipse(280,118,3,3);
	      break;
      case 88:fillellipse(312,118,3,3);
	      break;
      case 89:fillellipse(344,118,3,3);
	      break;
      case 90:fillellipse(376,118,3,3);
	      break;
      case 91:fillellipse(376,86,3,3);
	      break;
      case 92:fillellipse(344,86,3,3);
	      break;
      case 93:fillellipse(312,86,3,3);
	      break;
      case 94:fillellipse(280,86,3,3);
	      break;
      case 95:fillellipse(248,86,3,3);
	      break;
      case 96:fillellipse(216,86,3,3);
	      break;
      case 97:fillellipse(184,86,3,3);
	      break;
      case 98:fillellipse(152,86,3,3);
	      break;
      case 99:fillellipse(120,86,3,3);
	      break;
      case 100:
      default :fillellipse(88,86,3,3);
      }
}
//######################################################################
//######################################################################
void remp2(int p2)
{
  setcolor(13);
  setlinestyle(SOLID_LINE,1,1);
  setfillstyle(SOLID_FILL,13);

      switch(p2)
      {
      case 0: break;
      case 1: fillellipse(104,374,3,3);
	      break;
      case 2: fillellipse(136,374,3,3);
	      break;
      case 3: fillellipse(168,374,3,3);
	      break;
      case 4: fillellipse(200,374,3,3);
	      break;
      case 5: fillellipse(232,374,3,3);
	      break;
      case 6: fillellipse(264,374,3,3);
	      break;
      case 7: fillellipse(296,374,3,3);
	      break;
      case 8: fillellipse(328,374,3,3);
	      break;
      case 9: fillellipse(360,374,3,3);
	      break;
      case 10:fillellipse(392,374,3,3);
	      break;
      case 11:fillellipse(392,342,3,3);
	      break;
      case 12:fillellipse(360,342,3,3);
	      break;
      case 13:fillellipse(328,342,3,3);
	      break;
      case 14:fillellipse(296,342,3,3);
	      break;
      case 15:fillellipse(264,342,3,3);
	      break;
      case 16:fillellipse(232,342,3,3);
	      break;
      case 17:fillellipse(200,342,3,3);
	      break;
      case 18:fillellipse(168,342,3,3);
	      break;
      case 19:fillellipse(136,342,3,3);
	      break;
      case 20:fillellipse(104,342,3,3);
	      break;
      case 21:fillellipse(104,310,3,3);
	      break;
      case 22:fillellipse(136,310,3,3);
	      break;
      case 23:fillellipse(168,310,3,3);
	      break;
      case 24:fillellipse(200,310,3,3);
	      break;
      case 25:fillellipse(232,310,3,3);
	      break;
      case 26:fillellipse(264,310,3,3);
	      break;
      case 27:fillellipse(296,310,3,3);
	      break;
      case 28:fillellipse(328,310,3,3);
	      break;
      case 29:fillellipse(360,310,3,3);
	      break;
      case 30:fillellipse(392,310,3,3);
	      break;
      case 31:fillellipse(392,278,3,3);
	      break;
      case 32:fillellipse(360,278,3,3);
	      break;
      case 33:fillellipse(328,278,3,3);
	      break;
      case 34:fillellipse(296,278,3,3);
	      break;
      case 35:fillellipse(264,278,3,3);
	      break;
      case 36:fillellipse(232,278,3,3);
	      break;
      case 37:fillellipse(200,278,3,3);
	      break;
      case 38:fillellipse(168,278,3,3);
	      break;
      case 39:fillellipse(136,278,3,3);
	      break;
      case 40:fillellipse(104,278,3,3);
	      break;
      case 41:fillellipse(104,246,3,3);
	      break;
      case 42:fillellipse(136,246,3,3);
	      break;
      case 43:fillellipse(168,246,3,3);
	      break;
      case 44:fillellipse(200,246,3,3);
	      break;
      case 45:fillellipse(232,246,3,3);
	      break;
      case 46:fillellipse(264,246,3,3);
	      break;
      case 47:fillellipse(296,246,3,3);
	      break;
      case 48:fillellipse(328,246,3,3);
	      break;
      case 49:fillellipse(360,246,3,3);
	      break;
      case 50:fillellipse(392,246,3,3);
	      break;
      case 51:fillellipse(392,214,3,3);
	      break;
      case 52:fillellipse(360,214,3,3);
	      break;
      case 53:fillellipse(328,214,3,3);
	      break;
      case 54:fillellipse(296,214,3,3);
	      break;
      case 55:fillellipse(264,214,3,3);
	      break;
      case 56:fillellipse(232,214,3,3);
	      break;
      case 57:fillellipse(200,214,3,3);
	      break;
      case 58:fillellipse(168,214,3,3);
	      break;
      case 59:fillellipse(136,214,3,3);
	      break;
      case 60:fillellipse(104,214,3,3);
	      break;
      case 61:fillellipse(104,182,3,3);
	      break;
      case 62:fillellipse(136,182,3,3);
	      break;
      case 63:fillellipse(168,182,3,3);
	      break;
      case 64:fillellipse(200,182,3,3);
	      break;
      case 65:fillellipse(232,182,3,3);
	      break;
      case 66:fillellipse(264,182,3,3);
	      break;
      case 67:fillellipse(296,182,3,3);
	      break;
      case 68:fillellipse(328,182,3,3);
	      break;
      case 69:fillellipse(360,182,3,3);
	      break;
      case 70:fillellipse(392,182,3,3);
	      break;
      case 71:fillellipse(392,150,3,3);
	      break;
      case 72:fillellipse(360,150,3,3);
	      break;
      case 73:fillellipse(328,150,3,3);
	      break;
      case 74:fillellipse(296,150,3,3);
	      break;
      case 75:fillellipse(264,150,3,3);
	      break;
      case 76:fillellipse(232,150,3,3);
	      break;
      case 77:fillellipse(200,150,3,3);
	      break;
      case 78:fillellipse(168,150,3,3);
	      break;
      case 79:fillellipse(136,150,3,3);
	      break;
      case 80:fillellipse(104,150,3,3);
	      break;
      case 81:fillellipse(104,118,3,3);
	      break;
      case 82:fillellipse(136,118,3,3);
	      break;
      case 83:fillellipse(168,118,3,3);
	      break;
      case 84:fillellipse(200,118,3,3);
	      break;
      case 85:fillellipse(232,118,3,3);
	      break;
      case 86:fillellipse(264,118,3,3);
	      break;
      case 87:fillellipse(296,118,3,3);
	      break;
      case 88:fillellipse(328,118,3,3);
	      break;
      case 89:fillellipse(360,118,3,3);
	      break;
      case 90:fillellipse(392,118,3,3);
	      break;
      case 91:fillellipse(392,86,3,3);
	      break;
      case 92:fillellipse(360,86,3,3);
	      break;
      case 93:fillellipse(328,86,3,3);
	      break;
      case 94:fillellipse(296,86,3,3);
	      break;
      case 95:fillellipse(264,86,3,3);
	      break;
      case 96:fillellipse(232,86,3,3);
	      break;
      case 97:fillellipse(200,86,3,3);
	      break;
      case 98:fillellipse(168,86,3,3);
	      break;
      case 99:fillellipse(136,86,3,3);
	      break;
      case 100:
      default :fillellipse(104,86,3,3);
      }
}
//######################################################################
//######################################################################
void putp1(int p1)
{
  setcolor(1);
  setlinestyle(SOLID_LINE,1,1);
  setfillstyle(SOLID_FILL,1);

      switch(p1)
      {
      case 0: break;
      case 1: fillellipse(88,374,3,3);
	      break;
      case 2: fillellipse(120,374,3,3);
	      break;
      case 3: fillellipse(152,374,3,3);
	      break;
      case 4: fillellipse(184,374,3,3);
	      break;
      case 5: fillellipse(216,374,3,3);
	      break;
      case 6: fillellipse(248,374,3,3);
	      break;
      case 7: fillellipse(280,374,3,3);
	      break;
      case 8: fillellipse(312,374,3,3);
	      break;
      case 9: fillellipse(344,374,3,3);
	      break;
      case 10:fillellipse(376,374,3,3);
	      break;
      case 11:fillellipse(376,342,3,3);
	      break;
      case 12:fillellipse(344,342,3,3);
	      break;
      case 13:fillellipse(312,342,3,3);
	      break;
      case 14:fillellipse(280,342,3,3);
	      break;
      case 15:fillellipse(248,342,3,3);
	      break;
      case 16:fillellipse(216,342,3,3);
	      break;
      case 17:fillellipse(184,342,3,3);
	      break;
      case 18:fillellipse(152,342,3,3);
	      break;
      case 19:fillellipse(120,342,3,3);
	      break;
      case 20:fillellipse(88,342,3,3);
	      break;
      case 21:fillellipse(88,310,3,3);
	      break;
      case 22:fillellipse(120,310,3,3);
	      break;
      case 23:fillellipse(152,310,3,3);
	      break;
      case 24:fillellipse(184,310,3,3);
	      break;
      case 25:fillellipse(216,310,3,3);
	      break;
      case 26:fillellipse(248,310,3,3);
	      break;
      case 27:fillellipse(280,310,3,3);
	      break;
      case 28:fillellipse(312,310,3,3);
	      break;
      case 29:fillellipse(344,310,3,3);
	      break;
      case 30:fillellipse(376,310,3,3);
	      break;
      case 31:fillellipse(376,278,3,3);
	      break;
      case 32:fillellipse(344,278,3,3);
	      break;
      case 33:fillellipse(312,278,3,3);
	      break;
      case 34:fillellipse(280,278,3,3);
	      break;
      case 35:fillellipse(248,278,3,3);
	      break;
      case 36:fillellipse(216,278,3,3);
	      break;
      case 37:fillellipse(184,278,3,3);
	      break;
      case 38:fillellipse(152,278,3,3);
	      break;
      case 39:fillellipse(120,278,3,3);
	      break;
      case 40:fillellipse(88,278,3,3);
	      break;
      case 41:fillellipse(88,246,3,3);
	      break;
      case 42:fillellipse(120,246,3,3);
	      break;
      case 43:fillellipse(152,246,3,3);
	      break;
      case 44:fillellipse(184,246,3,3);
	      break;
      case 45:fillellipse(216,246,3,3);
	      break;
      case 46:fillellipse(248,246,3,3);
	      break;
      case 47:fillellipse(280,246,3,3);
	      break;
      case 48:fillellipse(312,246,3,3);
	      break;
      case 49:fillellipse(344,246,3,3);
	      break;
      case 50:fillellipse(376,246,3,3);
	      break;
      case 51:fillellipse(376,214,3,3);
	      break;
      case 52:fillellipse(344,214,3,3);
	      break;
      case 53:fillellipse(312,214,3,3);
	      break;
      case 54:fillellipse(280,214,3,3);
	      break;
      case 55:fillellipse(248,214,3,3);
	      break;
      case 56:fillellipse(216,214,3,3);
	      break;
      case 57:fillellipse(184,214,3,3);
	      break;
      case 58:fillellipse(152,214,3,3);
	      break;
      case 59:fillellipse(120,214,3,3);
	      break;
      case 60:fillellipse(88,214,3,3);
	      break;
      case 61:fillellipse(88,182,3,3);
	      break;
      case 62:fillellipse(120,182,3,3);
	      break;
      case 63:fillellipse(152,182,3,3);
	      break;
      case 64:fillellipse(184,182,3,3);
	      break;
      case 65:fillellipse(216,182,3,3);
	      break;
      case 66:fillellipse(248,182,3,3);
	      break;
      case 67:fillellipse(280,182,3,3);
	      break;
      case 68:fillellipse(312,182,3,3);
	      break;
      case 69:fillellipse(344,182,3,3);
	      break;
      case 70:fillellipse(376,182,3,3);
	      break;
      case 71:fillellipse(376,150,3,3);
	      break;
      case 72:fillellipse(344,150,3,3);
	      break;
      case 73:fillellipse(312,150,3,3);
	      break;
      case 74:fillellipse(280,150,3,3);
	      break;
      case 75:fillellipse(248,150,3,3);
	      break;
      case 76:fillellipse(216,150,3,3);
	      break;
      case 77:fillellipse(184,150,3,3);
	      break;
      case 78:fillellipse(152,150,3,3);
	      break;
      case 79:fillellipse(120,150,3,3);
	      break;
      case 80:fillellipse(88,150,3,3);
	      break;
      case 81:fillellipse(88,118,3,3);
	      break;
      case 82:fillellipse(120,118,3,3);
	      break;
      case 83:fillellipse(152,118,3,3);
	      break;
      case 84:fillellipse(184,118,3,3);
	      break;
      case 85:fillellipse(216,118,3,3);
	      break;
      case 86:fillellipse(248,118,3,3);
	      break;
      case 87:fillellipse(280,118,3,3);
	      break;
      case 88:fillellipse(312,118,3,3);
	      break;
      case 89:fillellipse(344,118,3,3);
	      break;
      case 90:fillellipse(376,118,3,3);
	      break;
      case 91:fillellipse(376,86,3,3);
	      break;
      case 92:fillellipse(344,86,3,3);
	      break;
      case 93:fillellipse(312,86,3,3);
	      break;
      case 94:fillellipse(280,86,3,3);
	      break;
      case 95:fillellipse(248,86,3,3);
	      break;
      case 96:fillellipse(216,86,3,3);
	      break;
      case 97:fillellipse(184,86,3,3);
	      break;
      case 98:fillellipse(152,86,3,3);
	      break;
      case 99:fillellipse(120,86,3,3);
	      break;
      case 100:
      default :fillellipse(88,86,3,3);
      }
}
//######################################################################
//######################################################################
void putp2(int p2)
{
  setcolor(14);
  setlinestyle(SOLID_LINE,1,1);
  setfillstyle(SOLID_FILL,14);

      switch(p2)
      {
      case 0: break;
      case 1: fillellipse(104,374,3,3);
	      break;
      case 2: fillellipse(136,374,3,3);
	      break;
      case 3: fillellipse(168,374,3,3);
	      break;
      case 4: fillellipse(200,374,3,3);
	      break;
      case 5: fillellipse(232,374,3,3);
	      break;
      case 6: fillellipse(264,374,3,3);
	      break;
      case 7: fillellipse(296,374,3,3);
	      break;
      case 8: fillellipse(328,374,3,3);
	      break;
      case 9: fillellipse(360,374,3,3);
	      break;
      case 10:fillellipse(392,374,3,3);
	      break;
      case 11:fillellipse(392,342,3,3);
	      break;
      case 12:fillellipse(360,342,3,3);
	      break;
      case 13:fillellipse(328,342,3,3);
	      break;
      case 14:fillellipse(296,342,3,3);
	      break;
      case 15:fillellipse(264,342,3,3);
	      break;
      case 16:fillellipse(232,342,3,3);
	      break;
      case 17:fillellipse(200,342,3,3);
	      break;
      case 18:fillellipse(168,342,3,3);
	      break;
      case 19:fillellipse(136,342,3,3);
	      break;
      case 20:fillellipse(104,342,3,3);
	      break;
      case 21:fillellipse(104,310,3,3);
	      break;
      case 22:fillellipse(136,310,3,3);
	      break;
      case 23:fillellipse(168,310,3,3);
	      break;
      case 24:fillellipse(200,310,3,3);
	      break;
      case 25:fillellipse(232,310,3,3);
	      break;
      case 26:fillellipse(264,310,3,3);
	      break;
      case 27:fillellipse(296,310,3,3);
	      break;
      case 28:fillellipse(328,310,3,3);
	      break;
      case 29:fillellipse(360,310,3,3);
	      break;
      case 30:fillellipse(392,310,3,3);
	      break;
      case 31:fillellipse(392,278,3,3);
	      break;
      case 32:fillellipse(360,278,3,3);
	      break;
      case 33:fillellipse(328,278,3,3);
	      break;
      case 34:fillellipse(296,278,3,3);
	      break;
      case 35:fillellipse(264,278,3,3);
	      break;
      case 36:fillellipse(232,278,3,3);
	      break;
      case 37:fillellipse(200,278,3,3);
	      break;
      case 38:fillellipse(168,278,3,3);
	      break;
      case 39:fillellipse(136,278,3,3);
	      break;
      case 40:fillellipse(104,278,3,3);
	      break;
      case 41:fillellipse(104,246,3,3);
	      break;
      case 42:fillellipse(136,246,3,3);
	      break;
      case 43:fillellipse(168,246,3,3);
	      break;
      case 44:fillellipse(200,246,3,3);
	      break;
      case 45:fillellipse(232,246,3,3);
	      break;
      case 46:fillellipse(264,246,3,3);
	      break;
      case 47:fillellipse(296,246,3,3);
	      break;
      case 48:fillellipse(328,246,3,3);
	      break;
      case 49:fillellipse(360,246,3,3);
	      break;
      case 50:fillellipse(392,246,3,3);
	      break;
      case 51:fillellipse(392,214,3,3);
	      break;
      case 52:fillellipse(360,214,3,3);
	      break;
      case 53:fillellipse(328,214,3,3);
	      break;
      case 54:fillellipse(296,214,3,3);
	      break;
      case 55:fillellipse(264,214,3,3);
	      break;
      case 56:fillellipse(232,214,3,3);
	      break;
      case 57:fillellipse(200,214,3,3);
	      break;
      case 58:fillellipse(168,214,3,3);
	      break;
      case 59:fillellipse(136,214,3,3);
	      break;
      case 60:fillellipse(104,214,3,3);
	      break;
      case 61:fillellipse(104,182,3,3);
	      break;
      case 62:fillellipse(136,182,3,3);
	      break;
      case 63:fillellipse(168,182,3,3);
	      break;
      case 64:fillellipse(200,182,3,3);
	      break;
      case 65:fillellipse(232,182,3,3);
	      break;
      case 66:fillellipse(264,182,3,3);
	      break;
      case 67:fillellipse(296,182,3,3);
	      break;
      case 68:fillellipse(328,182,3,3);
	      break;
      case 69:fillellipse(360,182,3,3);
	      break;
      case 70:fillellipse(392,182,3,3);
	      break;
      case 71:fillellipse(392,150,3,3);
	      break;
      case 72:fillellipse(360,150,3,3);
	      break;
      case 73:fillellipse(328,150,3,3);
	      break;
      case 74:fillellipse(296,150,3,3);
	      break;
      case 75:fillellipse(264,150,3,3);
	      break;
      case 76:fillellipse(232,150,3,3);
	      break;
      case 77:fillellipse(200,150,3,3);
	      break;
      case 78:fillellipse(168,150,3,3);
	      break;
      case 79:fillellipse(136,150,3,3);
	      break;
      case 80:fillellipse(104,150,3,3);
	      break;
      case 81:fillellipse(104,118,3,3);
	      break;
      case 82:fillellipse(136,118,3,3);
	      break;
      case 83:fillellipse(168,118,3,3);
	      break;
      case 84:fillellipse(200,118,3,3);
	      break;
      case 85:fillellipse(232,118,3,3);
	      break;
      case 86:fillellipse(264,118,3,3);
	      break;
      case 87:fillellipse(296,118,3,3);
	      break;
      case 88:fillellipse(328,118,3,3);
	      break;
      case 89:fillellipse(360,118,3,3);
	      break;
      case 90:fillellipse(392,118,3,3);
	      break;
      case 91:fillellipse(392,86,3,3);
	      break;
      case 92:fillellipse(360,86,3,3);
	      break;
      case 93:fillellipse(328,86,3,3);
	      break;
      case 94:fillellipse(296,86,3,3);
	      break;
      case 95:fillellipse(264,86,3,3);
	      break;
      case 96:fillellipse(232,86,3,3);
	      break;
      case 97:fillellipse(200,86,3,3);
	      break;
      case 98:fillellipse(168,86,3,3);
	      break;
      case 99:fillellipse(136,86,3,3);
	      break;
      case 100:
      default :fillellipse(104,86,3,3);
      }
}
//######################################################################
//######################################################################
int checkresult(int p1,int p2)
{
if(p1>=100)
   {
   outtextxy(446,330,"P1 WON ;)");
   return 1;
   }
   else if(p2>=100)
   {
   outtextxy(446,330,"P2 WON ;)");
   return 2;
   }else{
   return 0;
   }
}
//######################################################################
//######################################################################
int snakebitep1(int p1)
{
if(p1==24)
  p1=1;
  else if(p1==55)
	 p1=13;
	 else if(p1==70)
		p1=29;
		else if(p1==88)
		       p1=67;
		       else if(p1==99);
			      p1=6;

return p1;
}
//######################################################################
//######################################################################
int ladderupp1(int p1)
{
if(p1==8)
   p1=31;
   else if(p1==15)
	   p1=97;
	   else if(p1==42)
		   p1=81;
		   else if(p1==66)
			   p1=87;

return p1;
}
//######################################################################
//######################################################################
int snakebitep2(int p2)
{
if(p2==24)
  p2=1;
  else if(p2==55)
	 p2=13;
	 else if(p2==70)
		p2=29;
		else if(p2==88)
		       p2=67;
		       else if(p2==99);
			      p2=6;

return p2;
}
//######################################################################
//######################################################################
int ladderupp2(int p2)
{
if(p2==8)
   p2=31;
   else if(p2==15)
	   p2=97;
	   else if(p2==42)
		   p2=81;
		   else if(p2==66)
			   p2=87;

return p2;
}
//######################################################################
//######################################################################
void immediateexit(char ch)
{
if ((ch=='q')||(ch=='Q'))
   {
   link();
   }
}
//######################################################################
//######################################################################
void gameplay()
{
randomize();
int p1=0,p2=0,chan=1,i,j,ran=0,flag=0,res=0;
char ch;
       randomize();
       do
       {
       ran=random(6)+1;
       if(chan%2!=0)
       {
       dice();
       setcolor(1);
       putdiceno(ran);
       chance();
       showchancep1();
       againp1:
       ch=getch();
       immediateexit(ch);
       if((ch=='z')||(ch=='Z'))
       {
       remp1(p1);
       p1+=ran;
	    if((p1==24)||(p1==55)||(p1==70)||(p1==88)||(p1==99))
	      p1=snakebitep1(p1);
	    else if((p1==8)||(p1==15)||(p1==42)||(p1==66))
	      p1=ladderupp1(p1);
       putp1(p1);
       }
       else
       goto againp1;
       }
       else if(chan%2==0)
       {
       dice();
       setcolor(14);
       putdiceno(ran);
       chance();
       showchancep2();
       againp2:
       ch=getch();
       immediateexit(ch);
       if((ch=='m')||(ch=='M'))
       {
       remp2(p2);
       p2+=ran;
	    if((p2==24)||(p2==55)||(p2==70)||(p2==88)||(p2==99))
	      p2=snakebitep2(p2);
	    else if((p2==8)||(p2==15)||(p2==42)||(p2==66))
	      p2=ladderupp2(p2);
       putp2(p2); }
       else
       goto againp2;
       }
       chan+=1;
	    if((p1>=100)||(p2>=100))
	    {
	     flag=1;
	     res=checkresult(p1,p2);
	    }
       }while(flag!=1);
   showresult(res);
}
//#####################################################################
void showresult(int res)
{
ipad();
settextstyle(4,0,4);
setcolor(15);
if(res==1)
outtextxy(190,200,"PLAYER 1 WON");
else if(res==2)
     outtextxy(190,200,"PLAYER 2 WON");

getch();
}
//#####################################################################
void gamesnl()
{
    settextstyle(0,0,1);
    cleardevice();
    ipad();
    outerbox();
    divisions();
    counting();
    snake();
    ladders();
    dice();
    chance();
    playercolor();
    resultbox();
    gameplay();
    link();
}
//#######################################################################
/*

		  CODE ENDS FOR SNAKE AND LADDERS GAME


*/
//#######################################################################
//#######################################################################
/*
		  LINKING BOTH THE CODES USING A FUNCTION

*/

void link()
{
again:
   cleardevice();
   ipad();
   settextstyle(2,0,4);
   setcolor(15);
   outtextxy(505,415,"DOUBLE'O SEVEN");
   settextstyle(3,0,4);
   setcolor(1);
   outtextxy(240,60,"IPAD MENU");
   setcolor(4);
   setfillstyle(1,4);
   bar3d(80,120,200,240,10,1);
   setcolor(2);
   setfillstyle(1,2);
   bar3d(255,120,375,240,10,1);
   setcolor(3);
   setfillstyle(1,3);
   bar3d(430,120,550,240,10,1);

   setcolor(15);
   settextstyle(1,0,2);
   outtextxy(130,125,"1.");
   outtextxy(305,125,"2.");
   outtextxy(480,125,"3.");
   outtextxy(115,165,"WIRE");
   outtextxy(95,200,"COMPANY");
   outtextxy(265,165,"SNAKES &");
   outtextxy(275,200,"LADDERS");
   outtextxy(470,170,"EXIT");
   settextstyle(3,0,2);
   setcolor(1);
   outtextxy(170,280,"PRESS KEY OF YOUR CHOICE...");
   char ch=getch();

    switch(ch)
    {
     case '1':welcome();
	      break;
     case '2':gamesnl();
	      break;
     case '3':android();
	      break;
     default:setcolor(RED);
	     outtextxy(140,320,"WRONG CHOICE ENTERED, TRY AGAIN...");
	     delay(500);
	     goto again;
    }
}
/*

		       LINK FINISHED...


*/
///#####################################################################
//#########################################################################
/*

		       CODE FOR LOADING...

*/
void one()
{
int i;
for(i=7;i<=11;i++)
   {
   gotoxy(39,i);
   cprintf("ß");
   }
}

void two()
{
int i,y=8;
for(i=48;i>=42;i-=2)
   {
   gotoxy(i,y);
   cprintf("ß");
   y++;
   }
}

void three()
{
int i;
for(i=42;i<=50;i+=2)
   {
   gotoxy(i,12);
   cprintf("ß");
   }
}

void four()
{
int i,y=13;
for(i=42;i<=48;i+=2)
   {
   gotoxy(i,y);
   cprintf("ß");
   y++;
   }
}

void five()
{
int i;
for(i=13;i<=17;i++)
   {
   gotoxy(39,i);
   cprintf("ß");
   }
}

void six()
{
int i,y=13;
for(i=36;i>=30;i-=2)
   {
   gotoxy(i,y);
   cprintf("ß");
   y++;
   }
}

void seven()
{
int i;
for(i=36;i>=28;i-=2)
   {
   gotoxy(i,12);
   cprintf("ß");
   }
}

void eight()
{
int i,y=8;
for(i=30;i<=36;i+=2)
   {
   gotoxy(i,y);
   cprintf("ß");
   y++;
   }
}


void load(int i,int col=0)
{
 textcolor(col);
 gotoxy(30,3);
 cout<<"WORKING ON IT...!!!";
 one();
 delay(100);
 two();
 delay(100);
 three();
 delay(100);
 four();
 delay(100);
 five();
 delay(100);
 six();
 delay(100);
 seven();
 delay(100);
 eight();
 delay(100);
 gotoxy(((i-1)*8)+8,22);
 cout<<"ßßßßßßßß";
}

void loading()
{
  textmod();
  clrscr();
  randomize();
  int col;
  _setcursortype(_NOCURSOR);
  clrscr();
  int i=1;
  for(;i<10;i++)
  {
    col=random(7)+1;

      if(i%2==0)
      load(i,col);
      else
      load(i);

  }
  textcolor(15);

}



/*
		      LOADING CODE ENDS...

*/
//######################################################################
//######################################################################
void main()
{
clrscr();

graphmod();
link();

getch();
}