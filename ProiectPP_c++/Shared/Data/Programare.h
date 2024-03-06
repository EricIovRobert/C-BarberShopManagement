#ifndef PROGRAMARE_H_INCLUDED
#define PROGRAMARE_H_INCLUDED
#include <iostream>
#include <vector>
#include "C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Data\\Data.h"
#include "C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Data\\Oferte.h"
using namespace std;
class Programare{
Data data;
vector <Oferte> oferte_alese;
bool accept;
public:
    Programare();
    Programare(Data, vector<Oferte>,bool);
    ~Programare(){};
    Data get_data() const{return data;};
    vector<Oferte> get_oferte_alese()const {return oferte_alese;};
    bool get_accept()const {return accept;};
    friend ostream & operator << (ostream &, const Programare &);

};
ostream & operator << (ostream &st, const Programare &p){
    st << p.data << " ";
    for(const Oferte& oferte : p.oferte_alese)
        st << oferte << " ";
    st << p.accept;
    return st;
}
Programare::Programare()
{
    this->data=Data();
    this->oferte_alese=vector<Oferte>();
    this->accept=false;
}
Programare::Programare(Data a,vector <Oferte> b,bool c)
{
    this->data=a;
    this->oferte_alese=b;
    this->accept=c;
}

#endif // PROGRAMARE_H_INCLUDED
