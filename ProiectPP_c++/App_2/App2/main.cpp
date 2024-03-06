#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <list>
#include "C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Data\\Data.h"
#include "C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Data\\Oferte.h"
#include "C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Data\\Programare.h"
#include <cstring>
using namespace std;
string inlocuire2(string a)
{
    char charToReplace = ' ';
    std::string replacement = "_";

    size_t pos = a.find(charToReplace);
    while (pos != std::string::npos) {
        a.replace(pos, 1, replacement);
        pos = a.find(charToReplace, pos + replacement.length());
    }
    return a;
}
string inlocuire(string a)
{
        char charToReplace = '_';
    string replacement = " ";

    size_t pos = a.find(charToReplace);
    while (pos != std::string::npos) {
        a.replace(pos, 1, replacement);
        pos = a.find(charToReplace, pos + replacement.length());
    }
    return a;
}
int main(int argc, char** argv)
{
     if(argc==1)
            {cout<<"Nici o comanda introdusa. Incercati una dintre variantele urmatoare:\n";
    cout<<"1. vizualizare_oferte\n";
    cout<<"2. programare_valida\n";
    cout<<"3. istoric\n";return 0;}
    vector <Oferte> o;
     if (strcmp(argv[1], "vizualizare_oferte") == 0) {
        if(argc != 2)
        {cout<<"Sintaxa invalida! Sintaxa corecta: ./App2.exe vizualizare_oferte\n";
            return 0;
        }
            ifstream fin("C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Files\\oferte.txt");
            int nr; fin>>nr;
            for (int i=0;i<nr;i++)
            {
                string oferta; fin >> oferta;
                double pret ; fin>> pret;
                int durata ; fin>>durata;
                oferta=inlocuire(oferta);
                o.push_back(Oferte(oferta,pret,durata));
            }

            for (const auto& element : o) {
                std::cout << element << " ";
                cout<<"\n";
    }
    fin.close();
    }

    else if (strcmp(argv[1], "programare_valida") == 0) {
        if(argc != 5)
        {cout<<"Sintaxa invalida! Sintaxa corecta: ./App_2.exe programare_valida <data><ora>< oferta_aleasa >\n";
            return 0;
        }
        bool programareDisponibila = true;
            string datap=argv[2];
            string orap=argv[3];
            string ofertap=argv[4];
            ofertap=inlocuire2(ofertap);
            int oraIntrodusao = stoi(orap.substr(0, 2));
            int oraIntrodusam = stoi(orap.substr(3, 5));

            //cout<<oraIntrodusam<<" ";
            if (oraIntrodusao < 10 || oraIntrodusao > 21) {
                cout << "Ora introdusa nu este in intervalul permis (10:00 - 21:00).\n";
                programareDisponibila=false;
            }

            map <string,int> ma;
            ifstream fin("C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Files\\oferte.txt");
            int nr; fin>>nr;
            int j=0;
            for (int i=0;i<nr;i++)
            {
                string oferta; fin >> oferta;
                double pret ; fin>> pret;
                int durata ; fin>>durata;
                ma[oferta]=durata;
                if(oferta==ofertap) j=1;
            }
            fin.close();

            if(j==0) {cout<<"Nu exista oferta selectata";return 0;}

            int oraIntrodusafo=oraIntrodusao;
            int oraIntrodusafm=0;
            int x=ma[ofertap];
            //cout<<x;
            oraIntrodusafm=oraIntrodusam+x;
            if(oraIntrodusafm>=60) {oraIntrodusafm=oraIntrodusafm%60; oraIntrodusafo=oraIntrodusafo+1; }
            if (oraIntrodusafo==21 && oraIntrodusafm>0) {programareDisponibila=false;}
            if (oraIntrodusafo>21) {programareDisponibila=false;}

            ifstream finy("C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Files\\programari_facute.txt");
            finy>>nr;
            map <int,string> l1;
            map <int,string> l2;
            map <int,string> l3;
            map <int,bool> l4;
            //cout<<nr;
            for (int i=0;i<nr;i++)
            {
                string data; finy >> data;
                string ora ; finy>> ora;
                string tuns ; finy>>tuns;
                bool sw; finy>>sw;
                if(sw==1){
                if (data == datap && ora == orap) {
                    programareDisponibila = false;
                }
                int orao = stoi(ora.substr(0, 2));
                int oram = stoi(ora.substr(3, 5));
                int orafm=0;
                int orafo=orao;
                int x=ma[tuns];
                orafm=oram+x;
                if(orafm>=60) {orafm=orafm%60; orafo=orafo+1; }
                if (orafo==oraIntrodusao && orafm>oraIntrodusam) {programareDisponibila=false;}
                }
                l1[i]=data;
                l2[i]=ora;
                l3[i]=tuns;
                l4[i]=sw;
                }
                finy.close();
                ofstream fout("C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Files\\programari_facute.txt");
                fout<<nr+1<<"\n";
                for (int i=0;i<nr;i++)
                {
                    fout<<l1[i]<<" "<<l2[i]<<" "<<l3[i]<<" "<<l4[i]<<"\n";
                }
                fout<<datap<<" "<<orap<<" "<<ofertap<<" "<<programareDisponibila<<"\n";
                fout.close();
                if (programareDisponibila==false) cout<<"Programare invalida";
                else cout<<"Programare valida";
    }
    else if (strcmp(argv[1], "istoric") == 0) {
        if(argc != 2)
        {cout<<"Sintaxa invalida! Sintaxa corecta: ./App2.exe istoric\n";
            return 0;
        }
            ifstream fin("C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Files\\programari_facute.txt");
        string data;
        string ora;
        string tuns;
        bool g;
        int nr; fin>>nr;
        for (int i=0;i<nr;i++)
        {
            fin>>data;
            fin>>ora;
            fin>>tuns;
            fin>>g;
            if(g==1){
            cout<<data<<" ";
            cout<<ora<<" ";
            cout<<inlocuire(tuns)<<"\n";}
        }
    fin.close();
    }
    else {cout<<"Comanda invalida.\nIncercati una dintre variantele urmatoare:\n";
    cout<<"1. vizualizare_oferte\n";
    cout<<"2. programare_valida\n";
    cout<<"3. istoric\n";return 0;}



    return 0;
}


/*
int main(int argc, char** argv) {
    // Print output using std::cout
    std::cout << "Hello, world!" << std::endl;
    std::cout << "This is a sample output." << std::endl;

    return 0;
}
*/
