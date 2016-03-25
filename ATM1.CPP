#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
#include<fstream.h>
class atm
{
public:
long pin, actno,bal,wid,dip,amt,interest,SNo;
char name[20];
void getdata()
{
cout<<"Enter the S.No";
cin>>SNo;
cout<<"enter Client name";
cin>>name;
cout<<"ENTER THE PIN";
cin>>pin;
cout<<"ENTER THE ACCOUNT NO";
cin>>actno;
cout<<"ENTEr THE BALANCE AMOUNT: Rs ";
cin>>bal;
}
void putdata()
{
cout<<setw(10)<<SNo<<setw(15)<<name<<setw(15)<<pin<<setw(15)<<actno<<setw(15)<<bal<<endl;
}
}; //class closed
void main()
{
clrscr();
atm q;
long d;
top2:
gotoxy(25,8);
cout<<"enter the 4_digit pin"<<endl;
gotoxy(34,9);cin>>d;
fstream a0;
a0.open("bank2.dat",ios::in|ios::out|ios::binary|ios::app);
a0.seekg(0,ios::beg);
a0.read((char*)&q,sizeof(q));
while(a0.eof()==0)
  {
if(d==q.pin)
  {
char f2;
top1:
cout<<endl;
gotoxy(68,10);
cout<<"(B)alance"<<endl;
gotoxy(68,12);
cout<<"(W)ithdrawal"<<endl;
gotoxy(68,14);
cout<<"(D)eposit"<<endl;
gotoxy(68,16);
cout<<"(E)xit"<<endl;
gotoxy(34,10);
cin>>f2;
switch(f2)
  {
//case to DEPOSIT
case 'd':
clrscr();
a0.close();
long dr;
fstream t1;
t1.open("bank2.dat",ios::in|ios::out|ios::binary);
gotoxy(25,8);cout<<"enter the amount"<<endl;
gotoxy(33,9);cout<<"Rs";cin>>dr;
int ob=q.SNo;
int pos;
pos=(ob-1)*sizeof(q);
t1.seekp(pos,ios::beg);
q.bal=q.bal+dr;
gotoxy(25,10);cout<<"NEW BALANCE AMOUNT ";
gotoxy(30,11);cout<<"Rs"<<q.bal;
t1.write((char *)&q,sizeof(q)-pos);
gotoxy(25,13);
cout<<"TRANSCATION IS SUCCESSFULL";
getch();
clrscr();
goto top1;
break;
//case to show BALANCE
case 'b':
clrscr();
gotoxy(25,8);cout<<"AVAILABLE BALANCE";
gotoxy(32,9);cout<<"Rs"<<q.bal;
getch();
clrscr();
goto top1;
break;
//case to WITHDRAWAL
case 'w':
a0.close();
clrscr();
long d;
fstream t12;
t12.open("bank2.dat",ios::in|ios::out|ios::binary);
gotoxy(25,8);cout<<"enter the amount"<<endl;
gotoxy(30,9);cout<<"Rs";cin>>d;
long re=q.bal-d;
if(re<0)
{
gotoxy(25,10);cout<<"Sorry not enough Balance for the transcation";
gotoxy(25,11);cout<<"Available Balance is  Rs"<<q.bal;
}
else
{
int or=q.SNo;
int pos1;
pos1=(or-1)*sizeof(q);
t12.seekp(pos1,ios::beg);
q.bal=q.bal-d;
gotoxy(25,10);cout<<"NEW BALANCE";
gotoxy(30,11);cout<<"Rs"<<q.bal;
t12.write((char *)&q, sizeof(q)-pos1);
gotoxy(25,13);cout<<"TRANSCATION IS SUCCESSFUL";
}
getch();
clrscr();
goto top1;
break;
//case to EXIT
case 'e':
clrscr();
goto top2;
break;
case 'o':
clrscr();
getch();
exit(0);
break;
default :
clrscr();
gotoxy(27,8);cout<<"ERROR";
gotoxy(25,9);cout<<"WRONG CHOICE ENTERED";
goto top1;
break;
}
}
if(d==0000)
{
clrscr();
char st[10]="ssr";
char p[10];
int i=0;
char cc;
cout<<"Please Enter Password";
do
{
cc=getch();
cout<<"*";
p[i]=cc;
i++;
}while(cc!='\r');
int m=strcmp(p,st);cout<<m;
m=m-13;
if(m==0)
{
gotoxy(6,10);
cout<<"  LOGIN   SUCCESSFUL"<<endl;
cout<<"Enter Any key to Enter Project";
getch();
goto top;
}
else
{
cout<<" WRONG PIN ENTERED";
getch();
exit(0);
}
top;
int s;
cout<<"Enter your choice"<<endl;
cout<<"1 to insert"<<endl;
cout<<"2 to Display"<<endl;
cout<<"3 to search"<<endl;
cout<<"4 to update"<<endl;
cout<<"5 to remove"<<endl;
cout<<"6 to exit"<<endl;
cin>>s;
switch(s)
  {
//case to INSERT
case 1:
clrscr();
fstream f1;
f1.open("bank2.dat",ios::in|ios::out|ios::binary|ios::app);
char c='y';
while(c=='y')
{
q.getdata();
f1.write((char*)&q,sizeof(q));
cout<<"To enter more record press y or press n";
cin>>c;
}
clrscr();
f1.seekg(0,ios::beg);
f1.read((char*)&q,sizeof(q));
cout<<setw(10)<<"S.No"<<setw(15)<<"Client Name"<<setw(15)<<"pin"<<setw(15)<<"Account No"<<setw(15)<<"Balance Amt"<<endl;
while(f1.eof()==0)
  {
q.putdata();
f1.read((char*)&q,sizeof(q));
  }
getch();
goto top;
break;
//case to DISPLAY
case 2:
clrscr();
fstream f2;
f2.open("bank2.dat",ios::in|ios::out|ios::binary|ios::app);
f2.seekg(0,ios::beg);
f2.read((char*)&q,sizeof(q));
cout<<setw(10)<<"S.No"<<setw(15)<<"Client Name"<<setw(15)<<"pin"<<setw(15)<<"Account No"<<setw(15)<<"Balance Amt"<<endl;
while(f2.eof()==0)
  {
q.putdata();
f2.read((char*)&q,sizeof(q));
  }
getch();
goto top;
break;
//case to SEARCH
case 3:
fstream f3;
f3.open("bank2.dat",ios::in|ios::out|ios::binary|ios::app);
long h,flag=0;
cout<<"Enter the account no to be searched";
cin>>h;
f3.seekg(0,ios::beg);
f3.read((char*)&q,sizeof(q));
cout<<setw(10)<<"S.No"<<setw(15)<<"Client Name"<<setw(15)<<"pin"<<setw(15)<<"Account No"<<setw(15)<<"Balance Amt"<<endl;
while(f3.eof()==0)
  {
if(h==q.actno)
  {
q.putdata();
flag=1;
  }
f3.read((char*)&q,sizeof(q));
  }
if(flag==0)
cout<<"Record not found";
f3.close();
getch();
goto top;
break;
//case to REMOVE
case 5:
long actn;
fstream f4;
fstream f5;
f4.open("bank2.dat",ios::in|ios::out|ios::binary|ios::app);
f5.open("ac.dat",ios::in|ios::out|ios::binary|ios::app);
cout<<"Enter Account No you want to remove";
cin>>actn;
f4.seekg(0,ios::beg);
f4.read((char *)&q,sizeof(q));
clrscr();
while(f4.eof()==0)
  {
if(actn!=q.actno)
f5.write((char *)&q, sizeof(q));
f4.read((char *)&q,sizeof(q));
  }
f5.close();
f4.close();
remove("bank2.dat");
rename("ac.dat","bank2.dat");
cout<<"Account Successfully removed";
getch();
goto top;
break;
//case to UPDATE
case 4:
fstream f6;
f6.open("bank2.dat",ios::in|ios::out|ios::binary);
long sn;
cout<<"Enter S.No you want to update";
cin>>sn;
int pos;
pos=(sn-1)*sizeof(q);
f6.seekp(pos,ios::beg);
q.getdata();
f6.write((char *)&q, sizeof(q));
cout<<"Record Updated Successfully";
getch();
goto top;
break;
//case to EXIT
case 0:
cout<<setw(50)<<"                            Bye Bye                        ";
getch();
exit(0);
break;
default:
cout<<"Wrong choice enter";
getch();
goto top;
break;
}//switch closed
}//if closed
else
{
clrscr();
gotoxy(25,8);
cout<<"WRONG PIN ENTERED";
goto top2;
}
a0.read((char*)&q,sizeof(q));
a0.close();
}
getch();
}
