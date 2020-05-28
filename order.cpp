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
    setlocale(LC_ALL, "Russian");

    cout<<"введите сумму платежа\t";
    cin>>pay;
    this->setPay(pay);
    cout<<"введите дату оплаты\t";
    cin>>date;
    this->setDate(date);
    cout<<"введите назначение платежа\t";
    cin>>purpose;
    this->setPurpose(purpose);
    this->P=P;
}
void order:: print()
{    setlocale(LC_ALL, "Russian");

    cout<<endl<<"дата оплаты "<<this->getDate()<<" название организации "<<this->P->getTitle()<<" номер счета "<<this->P->getAccount()<<" назначение платежа "<<this->getPurpose()<<" сумма оплаты "<<this->getPay()<<endl;
}
order::~order(){}
ofstream& operator<<(ofstream& fout, const order& P)
{
        setlocale(LC_ALL, "Russian");

    fout <<"\tдата оплаты\t"<< P.getDate() ;
    fout <<"\tсумма оплаты\t"<< P.getPay() ;
    fout <<"\tназначение платежа\t"<<P.getPurpose();
    fout<<"\n" ;
    return fout;


}


