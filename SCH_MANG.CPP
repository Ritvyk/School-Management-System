/////school managment system by RITVIK software like finish///:>>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
void databasePage();
void menu();
struct newstu
{
  char name[50];
  char fathername[50];
  char subject[50];
  char mothername[50];
  int standard;
  int age;

};
void exitMenu()
{
   cleardevice();
   printf("\n\n\n\n\nt\t\t\tTHANKS FOR USING");
   printf("\n\n\n\n\t\t\tCREATED BY RITVIK");
   getch();
   cleardevice();
   exit(0);

}
void studentList()
{
  FILE *fp;
  char ch;
  int choice;
  cleardevice();
  fp=fopen("DATA_NEW.txt","r");
  while(1)
  {
     ch=getc(fp);
     printf("%c",ch);
     if(ch==EOF)
     {
       break;
     }

  }

  fclose(fp);
   printf("\n\nPLEASE RESTART THE APPLICATION\nPRESS ANY KEY TO RETURN MAIN MENU.\n");

  getch();
  cleardevice();
  menu();


}
void newStudent()
{
   struct newstu data;
   FILE *fp;
   FILE *NewStuFile;
   long int id;
   char Stu_class[3],newData[20];
   int i,choice1;
   cleardevice();
   id=rand()*rand();
   printf("\n\n\n\n\t\t\t\t\t*****NEW STUDENT ENROLLMENT******\n\n");
   fp=fopen("DATA_NEW.txt","a");
   printf("1.Enter Name Of The Student : ");
   gets(data.name);
   printf("\n2.Enter Father's Name Of The Student : ");
   gets(data.fathername);
   printf("\n3.Enter Mother's Name Of The Student : ");
   gets(data.mothername);
   printf("\n5.Enter Standard Of The Student : ");
   scanf("%d",&data.standard);
   printf("\n4.Enter Age : ");
   scanf("%d",&data.age);
   fprintf(fp,"\n");
   fprintf(fp,data.name);
   fprintf(fp,"\t\t");
   fprintf(fp,data.fathername);
   fprintf(fp,"\t\t\t");
   fprintf(fp,data.mothername);
   fprintf(fp,"\t\t");
   sprintf(Stu_class,"%d",data.standard);
   fprintf(fp,Stu_class);
   printf("\n\nLOADING.");
   for(i=0;i<4;i++)
   {  delay(1000);
      printf(".");
   }
   printf("\n\n\n\t****Student Enrollment Is completed Successfully ****");
   printf("\n\nTHE STUDENT ID = 3129%ld",id);
   fclose(fp);  ////erollment file closed here
   strcpy(newData,data.name);
   NewStuFile=fopen(newData,"a");
   fprintf(NewStuFile,"NAME\t\tFATHER'S NAME\t\tMOTHER'S NAME\tCLASS");
   fprintf(NewStuFile,"\n");
   fprintf(NewStuFile,data.name);
   fprintf(NewStuFile,"\t\t");
   fprintf(NewStuFile,data.fathername);
   fprintf(NewStuFile,"\t\t\t");
   fprintf(NewStuFile,data.mothername);
   fprintf(NewStuFile,"\t\t");
   fprintf(NewStuFile,Stu_class);
   fclose(NewStuFile);
   printf("\n\nPLEASE RESTART THE APPLICATION\nPRESS ANY KEY TO RETURN MAIN MENU....\n");

  getch();
  cleardevice();
  menu();

}
void studentSearch()
{

   char read,name[20];
   FILE *fp;
   cleardevice();
   printf("\n\n\n\t\t********SEARCH SECTION*********\n\n");
   printf("Enter Name Of The Student :  ");
   gets(name);
   fp=fopen(name,"r");
   printf("\n\n\t\t*****[THE STUDENT'S DETAILS ARE]******\n\n");
   while(1)
   {
     read=getc(fp);
     printf("%c",read);
     if(read==EOF)
     {
	 printf("\n\n\n\t\t*******PRESS ANY KEY TO EXIT********\n");
	 getch();
	 cleardevice();
	 exit(0);
     }

   }


  fclose(fp);
}
void databasePage()
{
  int cursorX=270,cursorY=210;
  char option;
  int check;
  cleardevice();


   while(1)
 {
   settextstyle(3,HORIZ_DIR,2);
  outtextxy(100,100,".......What You Want To Do ?........ ");
	 /////heading///

  circle(cursorX,cursorY,6);          ///cursor
  settextstyle(2,HORIZ_DIR,5);
  setfillstyle(1,RED);
  circle(270,210,3) ;          ///points
  floodfill(270,210,WHITE);

   setfillstyle(1,RED);           ///points
  circle(270,230,3);
  floodfill(270,230,WHITE);

   setfillstyle(1,RED);           ///points
  circle(270,250,3);
  floodfill(270,250,WHITE);
   setfillstyle(1,RED);           ///points
  circle(270,270,3);
  floodfill(270,270,WHITE);
  outtextxy(300,200,"New Admission");
  outtextxy(300,220,"Total Student List");
  outtextxy(300,240,"Search Student Detail");
  outtextxy(300,260,"Exit");
  option=getch();
  switch(option)
  {
     case 'w': if(cursorY==210)
     {
	cursorY+=0;
     }
     else
     {
	 cursorY-=20;cleardevice();
     }

     break;
     case 's': if(cursorY==270)
     {
	cursorY+=0;
     }
     else
     {
	 cursorY+=20;cleardevice();

     }

      break;

  }
  if(option=='o')
  {
     cleardevice();
     exit(0);
  }
  if(option=='e')    ///selection key is E to enter the option
  {
	if(cursorY==210)    ///first point
	{
	   newStudent();
	}
	else if(cursorY==230)       //second point
	{
	   studentList();
	}
	if(cursorY==250)
	{
	  studentSearch();
	}


	else
	{
	  exitMenu();
	}
  }
 }     ///loop ends here


}
/////database menu function ends here

void aboutDatabase()
{
   cleardevice();
   printf("This Program is purely made up on C Programming language \nusing Basic graphics in a creative way is the Key\n");
   printf("Using Basic header files and thier functions in a creative way and using them right according to thier concepts bring us to develop this software\n.This Software Cum Database is designed by RITVIK B.Tech First Year Student");
   printf("Hoping That you are Enjoying it !");
   printf("\n\n=> To ENTER in an option please press 'E' ");
   printf("\n\n=> To MOVE DOWN please press 's' ");
   printf("\n\n=> To MOVE UP please press 'w' ");
   printf("\n*******PRESS ANY KEY TO RETURN TO MAIN MENU******\n");
   getch();
   cleardevice();
   menu();

}
void menu()
{
  int gd=DETECT,gm;
  int cursorX=270, cursorY=210;
  char option,tempOption;

  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  setbkcolor(BLUE);

  textcolor(YELLOW);
  while(1)
 {

  circle(cursorX,cursorY,6);          ///cursor
  settextstyle(2,HORIZ_DIR,5);
  setfillstyle(1,RED);
  circle(270,210,3) ;          ///points
  floodfill(270,210,WHITE);

   setfillstyle(1,RED);           ///points
  circle(270,230,3);
  floodfill(270,230,WHITE);

   setfillstyle(1,RED);           ///points
  circle(270,250,3);
  floodfill(270,250,WHITE);
  outtextxy(300,200,"INTO DATABASE");
  outtextxy(300,220,"ABOUT");
  outtextxy(300,240,"EXIT");
  option=getch();
  switch(option)
  {
     case 'w': if(cursorY==210)
     {
	cursorY+=0;
     }
     else
     {
	 cursorY-=20;cleardevice();

     }

     break;
     case 's': if(cursorY==250)
     {
	cursorY+=0;
     }
     else
     {
	 cursorY+=20;cleardevice();

     }

      break;

  }
  if(option=='o')
  {
     cleardevice();
     exit(0);
  }
  if(option=='e')    ///selection key is E to enter the option
  {
	if(cursorY==210)
	{
		databasePage();
	}
	if(cursorY==230)
	{
	  aboutDatabase();
	}
	else
	{
	   exitMenu();
	}

  }
 }


}
void main()
{

	char password[6];
	int check,k;
	again:
	clrscr();
	printf("\t\t\t*********SCHOOL MANAGMENT SYSTEM**********\n\n");
	printf("\n\t\t\tENTER PASSWORD : ");
		for(k=0;k<6;k++)
		{
		  password[k]=getch();
		  delay(20);
		  printf("*");
		}
		check=strcmp(password,"ritvik");
		if(check==0)
		{
		  getch(); ///for just a pause
		  menu();
		}
		else if(check!=0)
		{
		  getch();
		  goto again;
	       }




}