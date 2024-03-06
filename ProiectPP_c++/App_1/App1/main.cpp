#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Data\\Data.h"
#include "C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Data\\Oferte.h"
#include "C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Data\\Programare.h"
using namespace std;
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
vector <Oferte> ofer;
string a,b;
double c;
int d;
int main(int argc, char *argv[])
{
    ifstream fin("C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Files\\oferte.txt");
    int nr;
    fin>>nr;
    fin.get();
    for(int i=0;i<nr;i++)
    {
        fin>>a;
        fin>>c;
        fin>>d;
        a=inlocuire(a);
        ofer.push_back(Oferte(a,c,d));
    }
    fin.close();
    if(argc==1)
            {cout<<"Nicio comanda introdusa. Incercati una dintre variantele urmatoare:\n";
    cout<<"1. adaugare_oferta\n";
    cout<<"2. modificare_oferta\n";
    cout<<"3. stergere_oferta\n";
    cout<<"4. acceptare_programare\n";return 0;}
      if(strcmp(argv[1],"adaugare_oferta")==0){
            if(argc != 5)
            {cout<<"Sintaxa invalida! Sintaxa corecta: \\App1.exe adaugare_oferta <oferta> <pret> <durata>\n";
            return 0;
            }
      int sw=0;
      string nume=argv[2];
      //nume=inlocuire(nume);
      double pret=stod(argv[3]);
      int durata=stoi(argv[4]);
      for(auto& it:ofer)
      {
          if(it.get_oferta()==nume)
            {cout<<"Oferta: "<<it.get_oferta()<<" a fost deja adaugata in sistem\n";
            cout<<"Puteti modifica oferta cu ajutorul comenzii modificare_oferta\n";
            sw=1;
          break;
            }
      }
      if(sw==0){nr++;
      ofer.push_back(Oferte(nume,pret,durata));
      cout<<"Oferta: "<<ofer[nr-1]<<" a fost adaugata cu succes\n";}
    }
    else if(strcmp(argv[1],"modificare_oferta")==0)
    {
        if(argc!=5)
        {
            cout<<"Sintaxa invalida! Sintaxa corecta: \\App1.exe modificare_oferta <oferta> <pret_nou> <durata_noua>\n";
            return 0;
        }
        string nume2=argv[2];
        //nume2=inlocuire(nume2);
        double pret=stod(argv[3]);
        int durata=stoi(argv[4]);
        for (auto& it : ofer)
        {
        if(it.get_oferta()==nume2)
            {
                if(pret==it.get_pret()&&durata==it.get_durata())
                {
                    cout<<"Nu se poate modifica folosind aceleasi valori pentru pret si durata\nIntroduceti valori diferite de cele vechi pentru a modifica\n";
                    break;
                }
            else{
                cout<<"Oferta "<<it<<" a fost modificata ";
                it.modif_durata(durata);
                it.modif_pret(pret);
                cout<<"in oferta: "<<it<<'\n';
                break;
            }
            }

        }


    }
    else if(strcmp(argv[1],"stergere_oferta")==0)
    {
        if(argc!=3)
        {
            cout<<"Sintaxa invalida! Sintaxa corecta: \\App1.exe stergere_oferta <nume_oferta>\n";
            return 0;
        }

        string nume_oferta = argv[2];
        nume_oferta = inlocuire(nume_oferta);
        auto it = std::find_if(ofer.begin(), ofer.end(), [&](Oferte& oferta) {
        return oferta.get_oferta() == nume_oferta;
    });

    if (it != ofer.end()) {
        nr--;
        ofer.erase(it);
        cout << "Oferta " << nume_oferta << " a fost stearsa cu succes.\n";
    } else {
        cout << "Oferta " << nume_oferta << " nu a fost gasita.\n";
    }
    }
     else if(strcmp(argv[1],"acceptare_programari")==0)
     {
         if(argc!=2)
         {
            cout<<"Sintaxa invalida! Sintaxa corecta: \\App1.exe acceptare_programari\n";
            return 0;
         }

         ifstream fin("C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Files\\programari_facute.txt");
         int nr_programari;
         fin>>nr_programari;
         int i;
         ofstream fout("C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Files\\programari.txt");
         for(i=0;i<nr_programari;i++)
         {
             string data;
             string ora;
             string oferta;
             bool x;
             fin>>data>>ora>>oferta>>x;
             oferta=inlocuire(oferta);
               if (x==true) {
        if (fout.is_open()) {
            data+=" ";
            data+=ora;
            data+=" ";
            data+=oferta;
            fout<<data<<'\n';

        }
        }


        }
        cout<<"Programarile valide au fost acceptate si afisate in fisierul corespunzator\n";
        fin.close();
        fout.close();
    }
    else {cout<<"Comanda invalida. Incercati una dintre variantele urmatoare:\n";
    cout<<"1. adaugare_oferta\n";
    cout<<"2. modificare_oferta\n";
    cout<<"3. stergere_oferta\n";
    cout<<"4. acceptare_programari\n";}
    ofstream fout("C:\\Users\\ThinkBook\\Desktop\\ProiectPP_c++\\Shared\\Files\\oferte.txt");
    fout<<nr<<'\n';
    for(auto& it:ofer)
        {
            string a=it.get_oferta();
            a=inlocuire2(a);
            fout<<a<<" "<<it.get_pret()<<" "<<it.get_durata()<<'\n';


        }
    fout.close();

    return 0;
}
