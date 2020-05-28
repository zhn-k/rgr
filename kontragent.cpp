#include "kontragent.h"
using namespace std;


kontragent::kontragent(){}

void kontragent::setAccount(int account)
{
    this->account=account;
}

void kontragent::setTitle(string title)
{
   this->title=title;
}
void kontragent::CIN()
{     setlocale(LC_ALL, "Russian");

    cout<<"введите номер счета\t";
    cin>>account;
    this->setAccount(account);
    cout<<"введите название организации\t";
    cin>>title;
    this->setTitle(title);
}
int kontragent:: getAccount()const
{
    return account;
}

string kontragent::getTitle()const
{
    return title;
}

kontragent::~kontragent(){}
ofstream& operator<<(ofstream& fout, const kontragent& P)
{
    fout <<"\tномер счета \t"<< P.getAccount() ;
    fout << "\tназвание организации\t"<<P.getTitle() ;
    fout<<"\n";
 return fout;
}

