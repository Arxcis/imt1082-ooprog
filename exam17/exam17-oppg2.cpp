
//  Fil:  FRODEH \ OO \ EXTRAMEN \ EX_V17_2.TPL

//  Hovedrisset til eksamen i OOP, 22.mai 2017, oppgave 2.
//  Laget av Frode Haug, NTNU

//  Programmet holder orden på et sykkelløps ulike topper/fjellpassasjer
//  og tilskuere som har registrert at de vil være på denne toppen
//  (med eller uten bil), og deres reisefølge (kun navn).

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

                        //  INCLUDE:
#include <iostream>              //  cin, cout
#include <fstream>               //  ifstream
#include <cstring>               //  strcpy, strlen, strstr
#include <cctype>                //  toupper
#include "../listtool.h"
using namespace std;
                        //  CONST:
const int STRLEN    =   80;      //  Max. lengde for en tekststreng.
const int MAXBILER  = 1000;      //  Max. antall (bo)biler oppe på EN topp.
const int MAXTOPP   =    5;      //  Max. antall topper på EN etappe.
const int MAXIFOLGE =   10;      //  Max. antall i reisefølget til 
                                 //       registrert tilskuer.

                        //  KLASSER:
class Topp  {
  private:
    char* navn;                         //  Toppens navn.
    int   maxAntallBiler,               //  Max.antall tillatte biler 
          antallBiler;                  //    og det nåværende antallet.
    List* tilskuere;                    //  Liste med tilskuerne.

  public:
    Topp();                                            //  Oppgave 2A
    Topp(ifstream & inn);                              //  Oppgave 2G
    ~Topp() {  delete [] navn;  delete tilskuere;  }   //  (Ferdiglaget)
    void skrivStatus();                                //  Oppgave 2B
    void skrivAlt();                                   //  Oppgave 2C
    void nyTilskuer();                                 //  Oppgave 2D
    bool skrivTilskuer(int ID);                        //  Oppgave 2E
};


class Tilskuer : public NumElement  {private:                             //  number = ID
     char* navn,                        //  Tilskuerens:  navn
         * mail;                        //                mail
     int   telefon,                     //                telefonnummer
           antIFolge;                   //  Antall personer i reisefølget.
     bool  harBil;                      //  Har med seg (bo)bil eller ei.
     char* folget[MAXIFOLGE+1];         //  Navnene på personene i reisefølget.

   public:
     Tilskuer(int ID, bool harB);                    //  Oppgave 2D
     Tilskuer(ifstream & inn, int nr);               //  Oppgave 2G
     ~Tilskuer();                                    //  (Ferdiglaget nedenfor)
     void display();                                 //  Oppgave 2C
};

                        //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();                                       //
char les();                                             //   Ferdiglaget
int  les(const char* t, const int MIN, const int MAX);  //  
void les(const char* t, char* s, const int LEN);        //

void lagTopperEllerLesFraFil();            //  (Ferdiglaget - Oppgave 2A og 2G)
void lagTopper();                          //  Oppgave 2A
void skrivAlleToppenesStatus();            //  Oppgave 2B
void skrivTilskuer();                      //  Oppgave 2E
void finnTilskuer();                       //  Oppgave 2F
void lesFraFil();                          //  Oppgave 2G

                        //  GLOBALE VARIABLE:
Topp* toppene[MAXTOPP+1];                  //  Array med toppene
int   antallTopper = 0, sisteID = 0;       //  Aktuelt antall topper og 
                                           //   siste tilskuer-ID brukt hittil.

int main()   {          //  HOVEDPROGRAM:
    char valg;                          //  Brukerens valg/kommando.

    lagTopperEllerLesFraFil();                          //  Oppgave 2A og 2G

    skrivMeny();
    cout << "\n\n\nKommando: ";   valg = les();
    while (valg != 'Q')  {
      switch (valg)  {
        case 'A': skrivAlleToppenesStatus();    break;  //  Oppgave 2B
        case 'T': toppene[les("ALT om topp nr", 1, antallTopper)]->skrivAlt();
                                                break;  //  Oppgave 2C
        case 'N': toppene[les("Ny på topp nr", 1, antallTopper)]->nyTilskuer();
                                                break;  //  Oppgave 2D
        case 'S': skrivTilskuer();              break;  //  Oppgave 2E
        case 'F': finnTilskuer();               break;  //  Oppgave 2F
        default:  skrivMeny();                  break;
      }
      cout << "\n\n\nKommando: ";   valg = les();
    }
//  skrivTilFil();
    cout << "\n\n";
    return 0;
}


// *************************************************************************
// ******************  DEFINISJON AV MEDLEMS-FUNKSJONER:  ******************
// *************************************************************************

Topp::Topp()
{
    les("Navn", this->navn, STRLEN);
    this->maxAntallBiler = les("MaxAntallBiler", 1, MAXBILER);

    this->antallBiler = 0;
    this->tilskuere = new List(Sorted);
}


Topp::Topp(ifstream & inn)  
{    
    //  Oppgave 2G - Leser ALT om en topp fra fil:

    //   Lag innmaten
}


void Topp::skrivStatus()  {  //  Oppgave 2B - Skriver alle HOVEDdata om toppen:

    std::cout << "Navn: " << navn << '\n'
              << "MaxAntallBiler: " << maxAntallBiler << '\n'
              << "AntallBiler: " << antallBiler << '\n'
              << "AntallTilskuere: " << tilskuere->noOfElements() << '\n'; 
}

                                //  Oppgave 2C - Skriver ALT om toppen
void Topp::skrivAlt()  
{

}


void Topp::nyTilskuer()  
{                       
    int bobilValg = les("Har du bobil? (0 = har ikke, 1 = har)", 0, 1);

    if (bobilValg == 1 && this->antallBiler == MaxAntallBiler) 
    {
        std::cout << "Beklager! Toppen har ikke plass til flere biler";
        return;
    }
    
}

                //  Oppgave 2E - Skriver/displayer (om mulig) EN gitt tilskuer:
bool Topp::skrivTilskuer(int ID)  {          

    //   Lag innmaten
}

                                     //  Oppgave 2D - Leser ALT om en tilskuer:
Tilskuer::Tilskuer(int ID, bool harB) : NumElement(ID)  {

    //   Lag innmaten
}

                                //  Oppgave 2G - Leser ALT om tilskuer fra fil:
Tilskuer::Tilskuer(ifstream & inn, int nr) : NumElement(nr)  {

    //   Lag innmaten
}


Tilskuer::~Tilskuer()  {                       // Destructor (ferdiglaget):
  delete [] navn;  delete []  mail;
  for (int i = 1;  i <= antIFolge;  i++)  delete [] folget[i];
}


void Tilskuer::display()  {         //  Oppgave 2C - Skriver ALT om tilskueren:

    //   Lag innmaten
}


// ****************************************************************************
// ******************   DEFINISJON AV (GLOBALE) FUNKSJONER:  ******************
// ****************************************************************************

void skrivMeny() {                  //  Skriver alle mulige menyvalg:
    cout << "\n\nFØLGENDE KOMMANDOER ER TILGJENGELIGE:"
         << "\n   A  - skriv Alle toppenes status"
         << "\n   T  - skriv ALT om EN Topp"
         << "\n   N  - Ny(e) tilskuer(e) med eller uten bil"
         << "\n   S  - Skriv ALT om en tilskuer med et gitt nr/ID"
         << "\n   F  - Finn tilskuer(e) med et gitt (del)navn"
         << "\n   Q  - Quit / avslutt";
}


char les() 
{                    //  Leser og upcaser ett tegn:
    char ch;   
    cin >> ch;   
    cin.ignore();   
    return (toupper(ch));
}

                                //  Leser et heltall mellom MIN og MAX:
int les(const char* t, const int MIN, const int MAX) {
    int n;
    do {
        cout << '\t' << t << " (" << MIN << '-' << MAX << "): ";
        cin >> n;  cin.ignore();
    } while (n < MIN || n > MAX);
    return n;
}

                                //  Leser inn en tekst:
void les(const char* t, char* s, const int LEN) {
    do {
        cout << '\t' << t << ": ";  //  Skriver ledetekst.
        cin.getline(s, LEN);        //  Leser inn tekst.
    } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}


void lagTopperEllerLesFraFil()  {    //  (Ferdiglaget - Oppgave 2A og 2G)
  ifstream innfil("TOPPSKUERE.DTA");     //  Aktuell fil forsøkes åpnet.
  if (innfil) {                          //  Filen finnes:
     innfil.close();                     //  Lukker filen.
     lesFraFil();                        //  Datatrukturen leses inn fra fil.
  } else
     lagTopper();                        //  Topper lages/legges inn.
}


void lagTopper()  {        //  Oppgave 2A - Lager/legger initielt inn topp(er):

    int valgtAntallTopper = les("Antall topper", 0, MAXTOPP);

    for(int i = 1; i <= valgtAntallTopper; ++i)
    {
        toppene[++antallTopper] = new Topp();        
    }
}

                             //  Oppgave 2B - Skriver HOVEDdata om ALLE topper:
void skrivAlleToppenesStatus() {

    //   Lag innmaten
}

                             //  Oppgave 2E - Skriver (om mulig) hvilken topp
void skrivTilskuer()  {      //          en gitt tilskuer (ut fra nr/ID) er på:

    //   Lag innmaten
}

                                //  Oppgave 2F - Skriver antall med et visst
void finnTilskuer() {           //               (del)navn på hver toppene:

    //   Lag innmaten
}



void lesFraFil() {               //  Oppgave 2G - Topper og tilskuere fra fil:

    //   Lag innmaten
}