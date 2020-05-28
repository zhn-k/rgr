
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
    setlocale(LC_ALL, "Russian");
int i,x,k,j, date1, pay1=0, pay2=0, account1, account2, balance=0,n = 0;
string purpose1, purpose2, title1,title2;
ofstream fout;
fout.open("information.txt", ios::app);
cout<<"������� ���������� ���������"<<endl;
cin>>x;

kontragent kin[x];
kontragent kout[x];
cashIN in[x];
cashOUT out[x];
cout<<"\n������� �������� ���������� ������\n\n"<<endl;
fout<<"�������� ���������� ������\n";
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
fout<<"�������� ���������� ������\n";
cout<<"\n������� �������� ���������� ������\n\n";

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
cout<<"\n ������� 1 ��� ��������� ���������� �� ���������(����������)\n"<<"\n ������� 2 ��� ��������� ���������� �� ���������(����)\n"<<"\n ������� 3 ��� ��������� ���������� �� ��������� (�������� ������������)\n"<<"\n ������� 4 , ����� ������ ������ �� ������������ ����\n";
cin>>k;
switch(k){
/////////////////////////////////////////////////
case 1:
cout <<"�������� ���������� ������� ��� ������ �  ��������� ������"<<endl;
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
    fout<<"���������� �� ��������� (����������)\n";
    fout<<in[n];
 }
 else
 {
    cout << " ������� � ��������� ���������� ���" << endl;
    fout<<"���������� �� ��������� (����������)\n";
    fout<<  " \n������� � ��������� ���������� ���\n";
 }

cout <<"�������� ���������� ������� ��� ������ � ��������� ������"<<endl;
cin>>purpose2;

n=-1;
for ( j = 0; j < x; j++)
{
if (out[j].getPurpose() == purpose2)
n= j;

}
if (n!= -1)
{cout <<"���������� �� ��������� (����������)"<<endl;
  out[ n].print();
  fout<<"���������� �� ��������� (����������)\n";
  fout<<out[n];
}
else
{
    cout << " ������� � ��������� ���������� ���\n" ;
    fout<<"���������� �� ��������� (����������)\n";
    fout<<"������� � ��������� ���������� ���\n" ;
 }
 break;
 ///////////////////////////////////////////////////////
case 2:
    cout <<"������� ���� ������� ��� ������ � ��������� ������"<<endl;
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
    fout<<"���������� �� ��������� (����)\n";
    fout<<in[n];
 }
else
 {
    cout << " ������� � ��������� ��������� ���\n" ;
    fout<<"���������� �� ��������� (����)\n";
    fout<<"������� � ��������� ���������� ���\n" ;
 }

    cout <<"������� ���� ������� ��� ������ � ��������� ������"<<endl;
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
    fout<<"���������� �� ��������� (����)\n";
    fout<<out[n];
 }
 else
 {
    cout << " ������� � ��������� ���������� ���\n";
    fout<<"���������� �� ��������� (����)\n";
    fout<<"������� � ��������� ���������� ���\n" ;
 }
 break;
//////////////////////////////////////////////////
 case 3 :
    cout <<"������� �������� ����������� ��� ������ � ��������� ������"<<endl;
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
    fout<<"���������� �� ���������� (��������)\n";
    fout<<in[n];
}
 else
 {
    cout << " ������� � ��������� ���������� ���\n" ;
    fout<<"���������� �� ���������� (��������)\n";
    fout<<"������� � ��������� ���������� ���\n" ;
 }

    cout <<"������� �������� ����������� ��� ������ � ��������� ������"<<endl;
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
    fout<<"��������� �� ��������� ��������\n";
    fout<<out[n];
 }
 else
 {
    cout << " ������� � ��������� ���������� ���\n";
    fout<<"���������� �� ��������� ��������\n";
    fout<<"������� � ��������� ���������� ���\n" ;
 }
 break;
////////////////////////////////////////
case 4:
    cout <<"\n\t\t\t������� ���� ��� ��������� ������� �� ��� ����\n"<<endl;
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
    cout<<"������ = "<<balance<<"������ ���������� - "<<pay1<<"������ ���������� "<<pay2;

    fout<<"������ �� ��������� ���� : "<<balance;
 }
 break;
 }
fout.close();
cout<<"\n\n\n\t\t\t����� ����� �� ���������� �������  ����� ������\n\n\n\n";
    return 0;
}
