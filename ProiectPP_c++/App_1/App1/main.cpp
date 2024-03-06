#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include "C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Data\\Data.h"
#include "C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Data\\Oferte.h"
#include "C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Data\\Programare.h"
using namespace std;
vector <Oferte> ofer;
string a,b;
double c;
int d;
int main(int argc, char *argv[])
{

    if(strcmp(argv[1],"ana")==0){
    ifstream fin("C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Files\\oferte.txt");
    int nr;
    fin>>nr;
    fin.get();
    for(int i=0;i<nr;i++)
    {
        fin>>a;
        fin>>b;
        fin>>c;
        fin>>d;
        string z=a+' ';
        z+=b;
        ofer.push_back(Oferte(z,c,d));
    }
 fin.close();
    }
  for(auto &it:ofer)
    cout<<it<<'\n';
    return 0;
}
