#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
class student
{
 public:
  char name[20];
  char dept[10];
  int rollno,sem,marks;
 public:
 void getdata()
 {
  cout<<"Enter NAme of Student";
  cin>>name;
  cout<<"Enter Deptt.";
  cin>>dept;
  cout<<"Enter Rollno.";
  cin>>rollno;
  cout<<"Enter Sem";
  cin>>sem;
  cout<<"Enter Marks";
  cin>>marks;
 }
 void putdata()
 {
  cout<<setw(20)<<name<<setw(10)<<dept<<setw(10)<<rollno<<setw(10)<<sem<<setw(10)<<marks<<endl;
 }
};
// class ended
 void main()
 {
  clrscr();
  char str[10]="hello";
  char pass[10];
  int i=0;
  char cc;
  cout<<"Enter Password";
  do
  {
    cc=getch();
    cout<<"*";
    pass[i]=cc;
    i++;
  }while(cc!='\r');
  int z=strcmp(pass,str);
  z=z-13;
  if(z==0)
  {
    gotoxy(6,10);
    cout<<"  LOGIN   SUCCESSFUL"<<endl;
    cout<<"Enter Any key to Enter Project";

    getch();
    goto lab;
  }
  else
 {
   cout<<" WRONG PASSWORD";
   getch();
   exit(0);
 }

 lab:

 student s;
 top:
 clrscr();
 gotoxy(5,5);
 cout<<"ADMIT CARD MANAGEMENT SYSTEM"<<endl;
 cout<<"Enter 1 to Insert Record"<<endl;
 cout<<"Enter 2 to Display all Record"<<endl;
 cout<<"Enter 3 to Search Record"<<endl;
 cout<<"Enter 4 to Delete Record"<<endl;
 cout<<"Enter 5 to Update Record"<<endl;
 cout<<"Enter 0 to Exit"<<endl;
 int ch;
 cout<<"Enter ur choice";
 cin>>ch;

  switch(ch)
  {
  case 1:
       {
       fstream f1;
       f1.open("ab.dat",ios::in|ios::out|ios::binary|ios::app);
       char ch1='y';
       while(ch1=='y')
       {
	s.getdata();
	f1.write((char *)&s, sizeof(s));
	 cout<<"Do you want to input more records";
	 cin>>ch1;
       }
       clrscr();
       f1.seekg(0,ios::beg);
       f1.read((char *)&s,sizeof(s));
       cout<<setw(20)<<"Name"<<setw(10)<<"Dept"<<setw(10)<<"Rollno"<<setw(10)<<"Sem"<<setw(10)<<"Marks"<<endl;

       while(f1.eof()==0)
       {
	s.putdata();
	f1.read((char *)&s,sizeof(s));
       }
	f1.close();
       }
	getch();
	goto top;
	break;
       case 2:
       {
       clrscr();
       fstream f2;
       f2.open("ab.dat",ios::in|ios::out|ios::binary|ios::app);

       f2.seekg(0,ios::beg);
       f2.read((char *)&s,sizeof(s));
       cout<<setw(20)<<"Name"<<setw(10)<<"Dept"<<setw(10)<<"Rollno"<<setw(10)<<"Sem"<<setw(10)<<"Marks"<<endl;

       while(f2.eof()==0)
       {
	s.putdata();
	f2.read((char *)&s,sizeof(s));

       }
	f2.close();
	getch();
	goto top;
       }
	break;
       case 3:
       {
       fstream f3;
       f3.open("ab.dat",ios::in|ios::out|ios::binary|ios::app);
       int r;
       clrscr();
       cout<<"Enter rollno. u want to search";
       cin>>r;
       f3.seekg(0,ios::beg);
       f3.read((char *)&s,sizeof(s));
       cout<<setw(20)<<"Name"<<setw(10)<<"Dept"<<setw(10)<<"Rollno"<<setw(10)<<"Sem"<<setw(10)<<"Marks"<<endl;
       int flag=0;
       clrscr();
       while(f3.eof()==0)
       {
	if(r==s.rollno)
       {
	 s.putdata();
	 flag=1;
       }

	f3.read((char *)&s,sizeof(s));

       }
       if(flag==0)
	cout<<"Record  not found";
       f3.close();
       goto top;
       }
       break;

       case 4:
     {
      fstream f4;
      fstream f5;
      f4.open("ab.dat",ios::in|ios::out|ios::binary|ios::app);
      f5.open("abc.dat",ios::in|ios::out|ios::binary);
      cout<<"Enter rollno.  u want to delete";
      int rno;
      cin>>rno;
       f4.seekg(0,ios::beg);
       f4.read((char *)&s,sizeof(s));
      // cout<<setw(20)<<"Name"<<setw(10)<<"Dept"<<setw(10)<<"Rollno"<<setw(10)<<"Sem"<<setw(10)<<"Marks"<<endl;
      // int flag=0;
       clrscr();
       while(f4.eof()==0)
       {
	if(rno!=s.rollno)
	f5.write((char *)&s, sizeof(s));
	f4.read((char *)&s,sizeof(s));
       }
	f4.close();
	f5.close();
       remove("ab.dat");
       rename("abc.dat","ab.dat");
       goto top;
     }
     break;

     case 5:
     {
     fstream f6;
     f6.open("ab.dat",ios::in|ios::out|ios::binary);
     int n;
     cout<<"Enter Record no. u want to update";
     cin>>n;
     int pos;
     pos=(n-1)*sizeof(s);
     f6.seekp(pos,ios::beg);
     s.getdata();
     f6.write((char *)&s, sizeof(s));
     cout<<"Record Updated Successfully";

       }
       goto top;
       break;
}

getch();
}