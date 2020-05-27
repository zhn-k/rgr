
using namespace std;
#include<iostream>
#include<string>
#include"kontragent.h"
#include"order.h"
#include"cashIN.h"
#include"cashOUT.h"
#include <fstream>


int main()
{
int i,x,k,j, date1, pay1=0, pay2=0, account1, account2, balance=0,n = 0;
string purpose1, purpose2, title1,title2;
ofstream fout;
fout.open("information.txt", ios::app);
cout<<"enter the number of elements"<<endl;
cin>>x;

kontragent kin[x];
kontragent kout[x];
cashIN in[x];
cashOUT out[x];
cout<<"\nenter  elements of cashIN\n\n"<<endl;
fout<<"Elements of cashIN\n";
for(i=0; i<x;  i++)
{
    kin[i].CIN();
    in[i].CIN(&kin[i]);
cout<<"\n\t\t**********\n";
}
for(i=0; i<x;  i++)
{
    in[i].print();
    fout<<in[i];
}
fout<<"Elements of cashOUT\n";
cout<<"\nenter  elements of cashOUT\n\n";

for(j=0; j<x; j++)
{
   kout[j].CIN();
    out[j].CIN(&kout[j]);
    cout<<"\n\t\t**********\n";

}
for(j=0; j<x; j++)
{
    out[j].print();
    fout<<out[j];
}
cout<<"\n information purpose 1\n"<<"\n information account 2\n"<<"\n information title 3\n"<<"\n information balance 4\n";
cin>>k;
switch(k){
/////////////////////////////////////////////////
case 1:
cout <<"purpose1"<<endl;
cin>>purpose1;

n=-1;
for ( i = 0; i < x; i++)
{
if (in[i].getPurpose() == purpose1)
n= i;

}

 if (n!= -1)
 {
    in[ n].print();
    fout<<"information (purpose)\n";
    fout<<in[n];
 }
 else
 {
    cout << " purpose it's not find" << endl;
    fout<<"information (purpose)\n";
    fout<<  " \npurpose it's not find\n";
 }

cout <<"purpose2"<<endl;
cin>>purpose2;

n=-1;
for ( j = 0; j < x; j++)
{
if (out[j].getPurpose() == purpose2)
n= j;

}
if (n!= -1)
{cout <<"purpose2"<<endl;
  out[ n].print();
  fout<<"information (purpose)\n";
  fout<<out[n];
}
else
{
    cout << " purpose it's not find\n" ;
    fout<<"information (purpose)\n";
    fout<<"purpose it's not find\n" ;
 }
 break;
 ///////////////////////////////////////////////////////
case 2:
    cout <<"account1"<<endl;
    cin>>account1;
     n= -1;
for ( i = 0; i < x; i++)
 {
     if (kin[i].getAccount()  == account1)
     n= i;
 }

if (n!= -1)
 {
    in[ n].print();
    fout<<"information (account)\n";
    fout<<in[n];
 }
else
 {
    cout << " account it's not find\n" ;
    fout<<"information (account)\n";
    fout<<"account it's not find\n" ;
 }

    cout <<"account2"<<endl;
    cin>>account2;
    n= -1;
for ( j = 0; j < x; j++)
 {
     if (kout[j].getAccount() == account2)
     n= j;
 }

if (n!= -1)
 {
    out[ n].print();
    fout<<"information (account)\n";
    fout<<out[n];
 }
 else
 {
    cout << " account it's not find\n";
    fout<<"information (account)\n";
    fout<<"account it's not find\n" ;
 }
 break;
//////////////////////////////////////////////////
 case 3 :
    cout <<"title1"<<endl;
    cin>>title1;
    n= -1;
for ( i = 0; i < x; i++)
 {
     if (kin[i].getTitle()  == title1)
     n= i;
 }

 if (n!= -1)
{
    in[ n].print();
    fout<<"information (title)\n";
    fout<<in[n];
}
 else
 {
    cout << " title it's not find\n" ;
    fout<<"information (title)\n";
    fout<<"title it's not find\n" ;
 }

    cout <<"title2"<<endl;
    cin>>title2;
    n= -1;

for ( j = 0; j < x; j++)
 {
    if (kout[j].getTitle() == title2)
    n= j;
 }

 if (n!= -1)
 {
    out[ n].print();
    fout<<"information (title)\n";
    fout<<out[n];
 }
 else
 {
    cout << " title it's not find\n";
    fout<<"information (title)\n";
    fout<<"title it's not find\n" ;
 }
 break;
////////////////////////////////////////
case 4:
    cout <<"\n\t\t\tdate for balance\n"<<endl;
    cin>>date1;

for ( i = 0; i < x; i++)
 {
     if (in[i].getDate()  <= date1)
    {
      pay1=pay1+in[i].getPay();
    }
 }
for ( j=0; j<x;  j++)
 {
     if (out[j].getDate()  <= date1)
    {
      pay2=pay2+out[j].getPay();
    }
 }
if ((pay1!=0)&&(pay2!=0))
 {
    balance=pay1-pay2;
    cout<<"balance = "<<balance<<"pay1 - "<<pay1<<"pay2 "<<pay2;
    fout<<"information (balance)\n";
    fout<<"balance= "<<balance;
 }
 break;
 }
fout.close();
    return 0;
}
