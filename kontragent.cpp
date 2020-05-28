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
{
    cout<<"Enter account\t";
    cin>>account;
    this->setAccount(account);
    cout<<"Enter title\t";
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
void operator<<(ofstream& fout, const kontragent& P)
{
    fout <<"\taccount\t"<< P.getAccount() ;
    fout << "\ttitle"<<P.getTitle() ;
    fout<<"\n";

}

