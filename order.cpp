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

    cout<<"������� ����� �������\t";
    cin>>pay;
    this->setPay(pay);
    cout<<"������� ���� ������\t";
    cin>>date;
    this->setDate(date);
    cout<<"������� ���������� �������\t";
    cin>>purpose;
    this->setPurpose(purpose);
    this->P=P;
}
void order:: print()
{    setlocale(LC_ALL, "Russian");

    cout<<endl<<"���� ������ "<<this->getDate()<<" �������� ����������� "<<this->P->getTitle()<<" ����� ����� "<<this->P->getAccount()<<" ���������� ������� "<<this->getPurpose()<<" ����� ������ "<<this->getPay()<<endl;
}
order::~order(){}
ofstream& operator<<(ofstream& fout, const order& P)
{
        setlocale(LC_ALL, "Russian");

    fout <<"\t���� ������\t"<< P.getDate() ;
    fout <<"\t����� ������\t"<< P.getPay() ;
    fout <<"\t���������� �������\t"<<P.getPurpose();
    fout<<"\n" ;
    return fout;


}


