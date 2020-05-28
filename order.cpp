#include "order.h"

using namespace std;

 order::order(){}
 void order::setPurpose(string purpose)
{
 this->purpose=purpose;

}
void order::setDate(int date)
{
    this->date=date;
}
void order::setPay(int pay)
{
    this->pay=pay;
}
 int order:: getPay()const
{
    return pay;
}
 int order::getDate()const
{
    return date;
}
 string order::getPurpose()const
{
    return purpose;
}

 void order:: CIN (kontragent *P)
{   int pay, date;
    string  purpose;

    cout<<"Enter pay\t";
    cin>>pay;
    this->setPay(pay);
    cout<<"Enter date\t";
    cin>>date;
    this->setDate(date);
    cout<<"Enter purpose\t";
    cin>>purpose;
    this->setPurpose(purpose);
    this->P=P;
}
void order:: print()
{
    cout<<endl<<"date\t"<<this->getDate()<<"\ttitle\t"<<this->P->getTitle()<<"\taccount\t"<<this->P->getAccount()<<"\tpurpose\t"<<this->getPurpose()<<"\tpay\t"<<this->getPay()<<endl;
}
order::~order(){}
void operator<<(ofstream& fout, const order& P)
{
    fout <<"\tdate\t"<< P.getDate() ;
    fout <<"\tpay\t"<< P.getPay() ;
    fout <<"\tpurpose\t"<<P.getPurpose();
    fout<<"\n" ;


}
