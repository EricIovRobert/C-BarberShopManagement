#ifndef OFERTE_H_INCLUDED
#define OFERTE_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;
class Oferte{
string oferta;
double pret;
int durata;
public:
    Oferte();
    Oferte(string ,double,int);
    ~Oferte(){};
    string get_oferta(){return oferta;};
    double get_pret(){return pret;};
    int get_durata(){return durata;};
    friend ostream & operator << (ostream &, const Oferte &);
};
ostream & operator << (ostream &st, const Oferte &o){
  st <<o.oferta<<" "<<o.pret<<" "<<o.durata;
  return st;
}
Oferte::Oferte()
{
    this->oferta="";
    this->pret=0;
    this->durata=0;
}
Oferte::Oferte(string a,double p,int d)
{
    this->oferta=a;
    this->pret=p;
    this->durata=d;
}
#endif // OFERTE_H_INCLUDED
