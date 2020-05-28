
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
cout<<"введите количество элементов"<<endl;
cin>>x;

kontragent kin[x];
kontragent kout[x];
cashIN in[x];
cashOUT out[x];
cout<<"\nВведите элементы приходного ордера\n\n"<<endl;
fout<<"Элементы приходного ордера\n";
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
fout<<"Элементы расходного ордера\n";
cout<<"\nВведите элементы расходного ордера\n\n";

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
cout<<"\n введите 1 для получения информации по параметру(назначение)\n"<<"\n введите 2 для получения информации по параметри(счет)\n"<<"\n введите 3 для получения информации по параметру (название оргианизации)\n"<<"\n введите 4 , чтобы узнать баланс на определенную дату\n";
cin>>k;
switch(k){
/////////////////////////////////////////////////
case 1:
cout <<"введитне назначение платежа для поиска в  приходном ордере"<<endl;
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
    fout<<"информация по параметру (назначение)\n";
    fout<<in[n];
 }
 else
 {
    cout << " платежа с введенным параметром нет" << endl;
    fout<<"информация по параметру (назначение)\n";
    fout<<  " \nплатежа с введенным параметром нет\n";
 }

cout <<"введитне назначение платежа для поиска в расходном ордере"<<endl;
cin>>purpose2;

n=-1;
for ( j = 0; j < x; j++)
{
if (out[j].getPurpose() == purpose2)
n= j;

}
if (n!= -1)
{cout <<"информация по параметру (назначение)"<<endl;
  out[ n].print();
  fout<<"информация по параметру (назначение)\n";
  fout<<out[n];
}
else
{
    cout << " платежа с введенным парматером нет\n" ;
    fout<<"информация по параметру (назначение)\n";
    fout<<"платежа с введенным параметром нет\n" ;
 }
 break;
 ///////////////////////////////////////////////////////
case 2:
    cout <<"введите счет платежа для поиска в приходном ордере"<<endl;
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
    fout<<"информация по параметру (счет)\n";
    fout<<in[n];
 }
else
 {
    cout << " платежа с введенным парметром нет\n" ;
    fout<<"информация по параметру (счет)\n";
    fout<<"платежа с введенным параметром нет\n" ;
 }

    cout <<"введите счет платежа для поиска в расходном ордере"<<endl;
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
    fout<<"информация по параметру (счет)\n";
    fout<<out[n];
 }
 else
 {
    cout << " платежа с введенным параметром нет\n";
    fout<<"информация по параметру (счет)\n";
    fout<<"платежа с введенным параметром нет\n" ;
 }
 break;
//////////////////////////////////////////////////
 case 3 :
    cout <<"введите название организации для поиска в приходном ордере"<<endl;
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
    fout<<"информация по пармаметру (название)\n";
    fout<<in[n];
}
 else
 {
    cout << " платежа с введенным параметром нет\n" ;
    fout<<"информация по пармаметру (название)\n";
    fout<<"платежа с введенным параметром нет\n" ;
 }

    cout <<"введите название организации для поиска в расходном ордере"<<endl;
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
    fout<<"информаия по параметру название\n";
    fout<<out[n];
 }
 else
 {
    cout << " платежа с введенным параметром нет\n";
    fout<<"информация по параметру название\n";
    fout<<"платежа с введенным параметром нет\n" ;
 }
 break;
////////////////////////////////////////
case 4:
    cout <<"\n\t\t\tвведите дату для просмотра баланса на эту дату\n"<<endl;
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
    cout<<"баланс = "<<balance<<"платеж приходного - "<<pay1<<"платеж расходного "<<pay2;

    fout<<"баланс на введенную дату : "<<balance;
 }
 break;
 }
fout.close();
cout<<"\n\n\n\t\t\tчтобы выйти из приложения нажмите  любую кнопку\n\n\n\n";
    return 0;
}
