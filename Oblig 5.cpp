//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S12_2.TPL

//  Skjellettet/template for kontinuasjonseksamen i C++, 18.august 2012, oppgave 2.
//  Laget av Frode Haug, HiG, juni 2012.

//  Program som holder orden p† ulike fjelloverganger som inng†r i et sykkell›p,
//  l›pets fjelletapper, og hvilke av dem som g†r oppom hvilke fjelloverganger.

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

                        //  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <iomanip>               //  setw
#include <cstring>               //  strcpy, strcmp, strlen
#include <cctype>                //  toupper
using namespace std;

                        //  CONST:
const int STRLEN     =     40;   //  Max. tekstlengde.
const int MAXETAPPER =     10;   //  Max. antall etapper.
const int MAXTOPPER  =     50;   //  Max. antall topper.
const int MAXOPPOM   =     10;   //  Max. topper p† EN etappe.


class Topp {            //  KLASSE:
  private:
    char  navn[STRLEN];      //  Toppens navn.
    int   moh,               //  Toppens meter over havet.
          hoyde;             //  Toppens meter fra dalbunnen/stigningsstart.
    float lengde;            //  Veilengde (i km) fra dalbunnen/stigningsstart.

  public:                    //  Deklarasjon av medlemsfunksjoner:
    void skriv();                         //  Oppgave 2A
    void skrivNavn();                     //  Oppgave 2B
    void lesData(char nvn[]);             //  Oppgave 2C
    bool heter(char nvn[]);               //  (Ferdigkodet)
    void lesFraFil(ifstream & inn);       //  Oppgave 2G
    void skrivTilFil(ofstream & ut);      //  Extra
};


class Etappe  {
  private:
    char  startsted[STRLEN];  //  Etappens startsted/-by.
    char  sluttsted[STRLEN];  //  Etappens sluttsted/-by.
    float lengde;             //  Etappens fulle lengde (i km).
    int   antTopper;          //  Totalt antall topper oppom p† etappen.
    int   topper[MAXOPPOM+1]; //  Toppenes numre i 'toppene'-arrayen.

  public:                     //  Deklarasjon av medlemsfunksjoner:
    void skriv();                         //  Oppgave 2B
    void lesData();                       //  Oppgave 2D
    bool gaarOppom(int n);                //  Oppgave 2E
    bool startSlutt(char nvn[]);          //  Oppgave 2F
    void lesFraFil(ifstream & inn);       //  Oppgave 2G
    void skrivTilFil(ofstream & ut);      //  Extra
};

                    //  DEKLARASJON AV FUNKSJONER:
void  skrivMeny();
char  les(char t[]);
float les(const char t[], const int min, const int max);
void  les(const char t[], char s[], const int LEN);
int   finnTopp(char nvn[]);
void  skrivTopper();           //  Oppgave 2A
void  skrivEtappe();           //  Oppgave 2B
void  nyTopp();                //  Oppgave 2C
void  nyEtappe();              //  (Ferdigkodet - men kallende skal kodes)
void  oppom();                 //  Oppgave 2E
void  starterSlutter();        //  Oppgave 2F
void  lesFraFil();             //  Oppgave 2G
void  skrivTilFil();           //  Extra


                        //  GLOBALE VARIABLE:
Topp   toppene[MAXTOPPER+1];    //  Array med Topp-objekter.
Etappe etappene[MAXETAPPER+1];  //  Array med Etappe-objekter.
int    sisteTopp;               //  Indeks for siste Topp hittil brukt.
int    sisteEtappe;             //  Indeks for siste Etappe hittil brukt.


int main()  {           //  HOVEDPROGRAM:
   char kommando;
   lesFraFil();                               //  Oppgave 2G
   skrivMeny();

   kommando = les("Onske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'P':  skrivTopper();      break;   //  Oppgave 2A
       case 'A':  skrivEtappe();      break;   //  Oppgave 2B
       case 'T':  nyTopp();           break;   //  Oppgave 2C
       case 'E':  nyEtappe();         break;   //
       case 'O':  oppom();            break;   //  Oppgave 2E
       case 'S':  starterSlutter();   break;   //  Oppgave 2F
       case 'F':  skrivTilFil();      break;   //  Extra
       default:   skrivMeny();        break;
     }
     kommando = les("Onske");
   }
   skrivTilFil();
   cout << "\n\n";
   return 0;
}

//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Topp::skriv()  {                    //  Skriver ALLE data:
    int nr;
        ifstream inn("TOPPER.DTA");

        if(inn)  {
          cout << "leser fra fil.... \n";
          inn >> nr; inn.ignore();

          for(int i = 0; i < nr; i++) {
            inn.getline(navn, STRLEN);
            inn >> moh >> lengde >> hoyde; inn.ignore();

            cout <<  /*"topp nr." << i + 1 << '\n' << navn << '\n'
                 << */ moh << ' ' << lengde << ' ' << hoyde << '\n';

          }
      } else {
          cout << "fant ikke filen TOPPPER.DTA";
      }
}

void Topp::skrivNavn()  {               //  Skriver KUN navnet:
        //  Oppgave 2B:  Lag innmaten
}

void Topp::lesData(char nvn[])  {       //  Leser alle egne data:
        //  Oppgave 2C:  Lag innmaten
}

bool Topp::heter(char nvn[])  {          //  Returnerer 'true/false' til om
  return (!strcmp(navn, nvn));           //    toppen heter 'nvn' eller ei.
}

void Topp::lesFraFil(ifstream & inn)  {  //  Leser ALT fra fil:

}

void Topp::skrivTilFil(ofstream & ut) {  // Skriver ALT til fil:
        //  Extra:  Lag frivillig innmaten
}

void Etappe::skriv()  {                  //  Skriver ALLE data:
        //  Oppgave 2B:  Lag innmaten
}

void Etappe::lesData()  {               //  Leser ALLE data:
        //  Oppgave 2D:  Lag innmaten
}
                                         //  Etappe g†r oppom (true)
bool Etappe::gaarOppom(int n)   {        //    topp nr.'n' eller ei (false):
        //  Oppgave 2E:  Lag innmaten
        return 0;
}
                                         //  Etappe starter eller slutter
bool Etappe::startSlutt(char nvn[])  {   //    i gitt by ('nvn') eller ei.
        //  Oppgave 2F:  Lag innmaten
        return 1;
}

void Etappe::lesFraFil(ifstream & inn)  {   //  Leser ALT fra fil:
        //  Oppgave 2G:  Lag innmaten
}

void Etappe::skrivTilFil(ofstream & ut) {  // Skriver ALT til fil:
        //  Extra:  Lag frivillig innmaten
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tP   = skriv alle topper\n";
  cout << "\tA   = skriv en etappe\n";
  cout << "\tT   = ny Topp\n";
  cout << "\tE   = ny Etappe\n";
  cout << "\tO   = etapper som gaar oppom en gitt topp\n";
  cout << "\tS   = etappe som Starter eller Slutter et gitt sted/by\n";
  cout << "\tF   = skriv til Fil\n";
  cout << "\tQ   = Quit/avslutt\n";
}


char les(char t[])  {        //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << '\n' << t << ":  ";   //  Skriver medsendt ledetekst.
  cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
  return (toupper(ch));         //  Upcaser og returnerer.
}

                             //  Leser et tall i et visst intervall:
float les(const char t[], const int min, const int max)  {
  float n;
  do  {                               // Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;   cin.ignore();         // Leser inn ett tall.
  } while(n < min  ||  n > max);      // Sjekker at i lovlig intervall.
  return n;                           // Returnerer innlest tall.
}

                             //  Leser en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {
  do  {
    cout << '\t' << t << ": ";	cin.getline(s, LEN); //  Ledetekst og leser.
  } while (strlen(s) == 0);           //  Sjekker at tekstlengden er ulik 0.
}


int finnTopp(char nvn[])  {          //  Returnerer (om mulig) indeksen for
  for (int i = 1;  i <= sisteTopp;  i++)    //  toppen med navn lik 'nvn'.
          if (toppene[i].heter(nvn))  return i;
  return 0;                           //  Ingen match - returnerer '0'.
}


void skrivTopper()  {       //  Skriver ALLE toppene:
  char toppNavn[STRLEN];
  ifstream inn("TOPPER.DTA");

  inn.ignore(2);
  cout << "topp nummer 1 ";
  inn.getline(toppNavn, STRLEN);
  cout << toppNavn << '\n';
  toppene[1].skriv();
  inn.ignore(15);
  cout << "topp nummer 2 ";
  inn.getline(toppNavn, STRLEN);
  cout << toppNavn << '\n';
  toppene[2].skriv();
  inn.ignore(17);
  cout << "topp nummer 3 ";
  inn.getline(toppNavn, STRLEN);
  cout << toppNavn << '\n';
  toppene[3].skriv();
  inn.ignore(16);
  cout << "topp nummer 4 ";
  inn.getline(toppNavn, STRLEN);
  cout << toppNavn << '\n';
  toppene[4].skriv();
}


void skrivEtappe()  {       //  Skriver EN gitt etappe:

}


void nyTopp()  {            //  Legger inn en ny topp:
        //  Oppgave 2C:  Lag innmaten
}


void nyEtappe()  {          //  Legger inn en ny etappe:
  if (sisteEtappe < MAXETAPPER)  {         //  Plass til flere:
     etappene[++sisteEtappe].lesData();    //  Ny etappe leser ALLE data selv.
  } else                                   //  Fullt med etapper:
    cout << "\n\n\tFullt med etapper i datastrukturen!\n\n";
}


void oppom()  {              //  Etapper som g†r oppom EN gitt topp:
        //  Oppgave 2E:  Lag innmaten
}


void starterSlutter()  {    //  Etappe som starter/slutter et gitt sted/by:
        //  Oppgave 2F:  Lag innmaten
}


void lesFraFil() {        //  Leser inn HELE datastrukturen:
        //  Oppgave 2G:  Lag innmaten
}


void skrivTilFil() {        //  Skriver ut HELE datastrukturen:
        //  Extra:  Lag frivillig innmaten
}
