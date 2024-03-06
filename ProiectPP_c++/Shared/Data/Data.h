#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;
class Data{
int zi,luna, an, ora, minute;
public:
    Data();
    Data(int ,int ,int ,int,int);
    ~Data(){};
    int get_zi()const{return zi;};
    int get_luna()const {return luna;};
    int get_an()const {return an;};
    int get_ora()const {return ora;};
    int get_minute()const {return minute;};
    friend ostream & operator << (ostream &, const Data &);
};
ostream & operator << (ostream &st, const Data &d){
  st <<d.zi<<"."<<d.luna<<"."<<d.an<<" "<<d.ora<<":"<<d.minute;
  return st;
}
Data::Data()
{
    this->zi=0;
    this->luna=0;
    this->an=0;
    this->ora=0;
    this->minute=0;
}
Data::Data(int a,int b,int c,int d,int e)
{
    this->zi=a;
    this->luna=b;
    this->an=c;
    this->ora=d;
    this->minute=e;
}


#endif // DATA_H_INCLUDED
