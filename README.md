# Cpp-BarberShopManagement
PROIECT IN ECHIPA!  
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

-------------------------------------------------------------------------------------------------------
# Cpp-BarberShopManagement
TEAM PROJECT!  
Programming Project / C++ -= Barber Shop =-

Student 1: Iov Eric-Robert

Student 2: A colleague

## *Statement*  

Student 1 is in charge of managing the barbershop:  

- adding, modifying, deleting offers (e.g., classic haircut - 20 ron - 25 min, buzz cut - 15 ron - 15 min, wash + blow-dry - 15 ron etc. - 10 min)  
- accepting made appointments  

Student 2 is responsible for scheduling appointments:  

- viewing the catalog of offers  
- scheduling a session within a valid interval  
- viewing the history of their appointments (both past and upcoming)  

## *Data Structure* 

*used by the team* 

3. We will use the following classes:  
   1. Date: int day, int month, int year, int hour  
   2. Appointment[]: Date date, Offer[] chosen_offer, int accept  
   3. Offers[]: string offer, double price, int duration  

## *File Structure* 

We will use the following files:  

- appointments.txt  
  - file to store details about appointments in the form <nr_appointments>  

  <appointment> 

- offers.txt  
  - file to store details about offers  

  <nr_offers> <offer>  

*IV. Interaction with Executables*  

Application 1 will add, modify, delete offers, accept made appointments: ./app_1.exe add_offer <offer> <price> <duration>   

- for adding an offer  

./app_1.exe accept_offer <date>< chosen_offer >< accept > 

- to accept an appointment 

./app_1.exe modify_offer <offer> <price> <duration>   

- for modifying an offer  

./app_1.exe delete_offer <offer_number>  

- to delete an offer  

Application 2 will expose the following possibilities:  ./app_2.exe view_offers  

- to view all offers  

./app_2.exe valid_appointment <date>< chosen_offer >< accept > 

- to schedule a session within a valid interval  

./app_2.exe history  

- to view the history of appointments  

