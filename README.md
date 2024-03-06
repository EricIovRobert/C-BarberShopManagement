# Cpp-BarberShopManagement
TEAM PROJECT!  
Proiect de Programare / C++ -= Frizerie =-

Student 1: Iov Eric-Robert

Student 2: Un coleg

1. *Enunț*  

Studentul 1 se ocupa de managementul frizeriei:  

- adauga, modifica, sterge oferte (de ex. tuns clasic - 20 ron - 25 min, tuns 0 - 15 ron - 15 min, spalat + uscat - 15 ron etc. - 10 min)  
- accepta programarile facute  

Studentul 2 se ocupa de efectuarea programarilor:  

- vizualizeaza catalogul cu oferte  
- programeaza o sedinta intr-un interval valid  
- vede istoricul programarilor sale (atat cele ce au trecut cat si cele ce urmeaza)  
2. *Structura datelor* 

*folosite de echipă* 

3. Vom folosi clasele:  
   1. Data: int zi, int luna, int an, int ora  
   1. Programare[]: Data data, Oferta[] oferta\_aleasa, int accept  
   1. Oferte[]: string oferta, double pret, int durata  
3. *Structura fișierelor* 

Vom folosi următoarele fișiere:  

- programari.txt  
- fișier în care vom stoca detalii despre programari sub forma   <nr\_programari>  

  <programare> 

- oferte.txt  
- fișier în care vom stoca detalii despre oferte  

<nr\_oferte>  < oferta>  

*IV. Interacționarea cu executabilele*  

Aplicația 1 va adauga, modifica, sterge oferte, accepta programarile facute: ./app\_1.exe adaugare\_oferta <oferta> <pret> <durata>   

- pentru adăugarea unui oferte  

./app\_1.exe acceptare oferta<data>< oferta\_aleasa >< accept > 

- pentru a accepta o programare 

./app\_1.exe modificare\_oferta <oferta> <pret> <durata>   

- pentru modificarea unui oferte  

./app\_1.exe stergere\_oferta <nr\_ofertei>  

- pentru ștergerea unei oferte  

Aplicația 2 va expune următoarele posibilități:  ./app\_2.exe vizualizare\_oferte  

- pentru vizualizarea tuturor ofertelor  

./app\_2.exe Programare\_valida <data>< oferta\_aleasa >< accept > 

- programeaza o sedinta intr-un interval valid  

./app\_2.exe istoric  

- vede istoricul programarilor sale  
