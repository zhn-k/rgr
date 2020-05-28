#ifndef KONTRAGENT_H_INCLUDED
#define KONTRAGENT_H_INCLUDED
using namespace std;
#include<iostream>
#include<string.h>
#include <fstream>
class kontragent {

protected:

    int account;
    string title;
  public:
    kontragent();
    void setAccount(int);
    void setTitle(string );
    int getAccount()const;
    string getTitle() const;
    void CIN();
    ~kontragent();
   friend void operator<<(ofstream& fout, const kontragent& obj);
};

#endif // KONTRAGENT_H_INCLUDED
