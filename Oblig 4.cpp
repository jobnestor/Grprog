//  Fil:  FRODEH \ CPP \ OBLIGER \ OBLIG_4.TPL
//
//  Skjellettet/template for obligatorisk oppgave nr.4 i  C++ -programmering.
//  Omhandler/"dekker" kap.2-6 i læreboka.


                             //  INCLUDE:
#include <iostream>          //  cout, cin
#include <cctype>            //  toupper

using namespace std;

                             //  KLASSE:
class Tid {                  //  Klasse inneholdende data om:
  private:
    int dag, maaned, aar;     //    - en gitt dato  og
    int time, minutt, sekund; //    - et gitt tidspunkt (klokkeslett).

    bool  skuddaar(int aa);                    //  Hentet/kopiert RETT
    int   dagnummer(int da, int ma, int aa);   //     fra OPPG_20.

  public:
    Tid();                    //  2x constructorer:
    Tid(int tt, int mm, int ss);
    void skrivDato();         //  På formen:  dd/mm-aaaa
    void skrivTidspunkt();    //  På formen:  tt:mm:ss
    void skrivTid();          //  På formen:  dd/mm-aaaa   tt:mm:ss
    void lesDato();           //  Leser inn ny dato.
    void lesTidspunkt();      //  Leser inn nytt tidspunkt.
    void lesTid();            //  Leser inn ny dato og nytt tidspunkt.
    bool likDato(const Tid t);             // Er datoene like eller ei.
    Tid  tidspunktForskjell(const Tid tt); // Tiden mellom to tidspkt samme dag
    int  datoForskjell(const Tid tt);  //  Antall dager mellom to datoer.
};

                             //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char lesKommando();
int  les(const int min, const int max);



//  ********************  H O V E D P R O G R A M M E T:  *******************
int main()  {
  Tid tid1, tid2, tid3;  //  Tre tid-objekter.

  char valg;             //  Brukerens valg/ønske/kommando.
  int nr;                //  Hvilken av tid1 og tid2 det skal endres på.

  skrivMeny();           //  Skriver/viser bruker-menyen.
  valg = lesKommando();  //  Leser brukerens valg/ønske/kommando.

  while (valg != 'Q'  &&  valg != 'A')  {  //  Så lenge ikke avslutte:
    switch (valg)  {
      case 'S':   tid1.skrivTid(); tid2.skrivTid(); break;

      case 'D':  { cout << "Vil du endre tid1 eller tid2? \n";
                   nr = les(1, 2);
                   nr == 1 ? (tid1.lesDato()) : (tid2.lesDato());
                   break;
                 }

      case 'P':  { cout << "Vil du endre tid1 eller tid2? \n";
                   nr = les(1, 2);
                   nr == 1 ? (tid1.lesTidspunkt()) : (tid2.lesTidspunkt());
                   break;
                 }

      case 'T':  { cout << "Vil du endre tid1 eller tid2? \n";
                   les(1, 2);
                   nr == 1 ? (tid1.lesTid()) : (tid2.lesTid());
                   break;
                 }

      case 'X': {
                  tid1.likDato(tid2);
                  if(tid1.likDato(tid2) == false)  {
                    tid3 = tid1.tidspunktForskjell(tid2);
                    cout << "forskjellen av tidene er:\t";
                    tid3.skrivTidspunkt();
                  } else  {
                    cout << "\n\nDatoene er like:\n";
                  }
                  break;
                }

      case 'Y':    tid1.datoForskjell(tid2);
                   cout << tid1.datoForskjell(tid2); break;

      default:   skrivMeny();   break;
    }
    valg = lesKommando(); //  Leser igjen brukerens valg/ønske/kommando.
  }
  cout << "\n\n";
  return 0;
}


//  *******************  DEFINISJON AV KLASSE-FUNKSJONER:  ********************

                                   //  IDENTISK TIL OPPG_20:
bool Tid :: skuddaar(int aa)  {    //  Sjekker om et visst år er skuddår:
                                   //  Skuddår dersom: (delelig med 400) ELLER
                                   //    (delelig med 4 OG ikke med 100)
  return ((aa % 400 == 0)  || ((aa % 4 == 0) && (aa % 100) != 0));
}
                                   //  IDENTISK TIL OPPG_20:
                     //  Ut fra datoens input, så returneres (om mulig)
                     //    denne datoens dagnummer i året, ellers returneres 0.
int Tid :: dagnummer(int da, int ma, int aa)  {
                                   //  Setter opp antall dager i månedene.
                                   //   Verdien for februar settes senere.
  int dagerPrMaaned[12] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int totalDagnr, i;

  if (aa < 1600  ||  aa > 2100) return 0;    //  Ulovlig år.
  if (ma < 1     ||  ma > 12)   return 0;    //  Ulovlig måned.
                                   //  Ut fra om året er skuddår eller ei,
                                   //    så settes verdien for februar:
  dagerPrMaaned[1] = (skuddaar(aa))  ?  29 : 28;
  if (da < 1 ||  da > dagerPrMaaned[ma-1])  return 0;  // Ulovlig dag:
                                   //  Garantert at er en lovlig dato !!
  totalDagnr = da;
  for (i = 0;  i < ma-1;  i++)             // Regner ut datoens dagnummer.
     totalDagnr += dagerPrMaaned[i];

  return totalDagnr;                       // Returnerer dagnummeret.
}

Tid :: Tid()                       //  2x constructorer, som setter verdier:
  {                                // Setter default verdier for dato og tid
   maaned = 1, aar = 2000, dag = 1, time = 0, minutt = 0, sekund = 0;
  }

Tid :: Tid(int tt, int mm, int ss)
  {
    aar = 2000, maaned = 1, dag = 1, time = tt, minutt = mm, sekund = ss;
  }

void Tid :: skrivDato()            //  På formen:  dd/mm-aaaa
  {
    cout << '\n' << dag << "/" << maaned << "-" << aar << '\t';
  }

void Tid :: skrivTidspunkt()       //  På formen:  tt:mm:ss
  {                                   // Hentet fra eks. 44.
    cout << ((time < 10) ? "0" : "") << time << ':'   //  Legger evt. til
         << ((minutt  < 10) ? "0" : "") << minutt  << ':'   //    innledende
         << ((sekund  < 10) ? "0" : "") << sekund;        //    null ('0'):
  }

void Tid :: skrivTid()             //  På formen:  dd/mm-aaaa   tt:mm:ss
  {
      skrivDato();                  // Kaller skrivDato og skriver dato
      skrivTidspunkt();             // Skriver ut tidspunktet
  }

void Tid :: lesDato()              //  Leser inn ny dato:
  {
    int aa, ma, da, sjekk;          // "tempvariabler"
      cout << "gammel dato;\t";   // Skriver ut gammel dato
              skrivDato();
      cout << "\ndag:\t";
              da = les(1, 31);    // Leser inn dag i riktig intervall
      cout << "maaned:\t";
              ma = les(1, 12);    // Leser inn maaned i riktig intervall
      cout << "aar:\t";
              aa = les(1600, 2100); // Leser inn aar i riktig intervall
      sjekk = dagnummer(da, ma, aa);

      if (sjekk == 0)  {
        cout << "feil dato:\t";   //Hvis dagnummer returner 0 er det feil dato
                lesDato();        // Kjorer paa nytt om feil dato
      }
      maaned = ma, dag = da, aar = aa;  // Setter formelle lik lokale variabler
      cout << "ny dato er:\t";
              skrivDato();          // Skriver ny Dato
    }

void Tid :: lesTidspunkt()         //  Leser inn nytt tidspunkt
  {
    int tt, mm, ss;
    cout << "\ngammelt tidspunkt\t";
              skrivTidspunkt();     // Skriver tidspunkt
      cout << "Hvilken time er det? ";
              tt = les(0, 24);        // Leser time i rett intervall
      cout << "Hvilket minutt er det? ";
              mm = les(0, 60);          // Leser minutt i rett intervall
      cout << "Hvilket sekund er det? ";
              ss = les(0, 60);        // Leser sekund i rett intervall
      cout << "nytt tidspunkt";
      time = tt, minutt = mm, sekund = ss;  // Setter formelle lik lokale var.
      cout << "nytt tidspunkt er:\t";
              skrivTidspunkt();       // Skriver ut nytt tidspunkt
    }

void Tid :: lesTid()               //  Leser inn ny dato og nytt tidspunkt:
  {
      lesDato();                  // Kjoorer lesDato og LesTidspunkt
      lesTidspunkt();
  }

bool Tid :: likDato(const Tid t)   //  Er to datoer like eller ei:
{                           // Returnerer true hvis like datoer
                            // Returneres false hvis ulike
 return((maaned == t.maaned && dag == t.dag && aar == t.aar) ? true : false);
}

Tid Tid :: tidspunktForskjell(const Tid tt)  // Forskjellen mellom to tidspkt:
{   Tid forskjell;
    if (time > tt.time)  {          // Hvis tid1 time er stoore en tid2 time
      forskjell.time = (time - tt.time);     // settes forskell lik differansen
      forskjell.minutt = (minutt - tt.minutt);    // Mellom tid1 og tid2
      forskjell.sekund = (sekund - tt.sekund);
    } else if(tt.time > time)  {        // Hvis tid2 er stoore enn tid1
      forskjell.time = (tt.time - time);    // settes forskjell lik diff mellom
      forskjell.time = (tt.minutt - minutt);  // tid2 og tid1
      forskjell.sekund = (tt.sekund - sekund);
    }
    return forskjell;             // Returnerer tidsobjekt med differanse
  }                                           // Mellom begge tidene

int Tid :: datoForskjell(const Tid tt)      //  Antall dager mellom to datoer:
  {
    int t1, t2;               // Lager lokale inter for dagnummer i tidsobjekt
    int dagForskjell;         // Lager returneringsvariabel
    t1 = dagnummer(dag, maaned, aar); // Definerer t1 sitt dagnummer
    t2 = dagnummer(tt.dag, tt.maaned, tt.aar);  // Definerer t2 sitt dagnummer

    for (int i = 1600; i < aar; i++)  {   // begynner for loop som teller dager
        (skuddaar(i)) ? t1 += 366  : t1 += 365; // Legger til 366 hvis skuddaar
    }                                          // Legger til 365 hvis ikke.

    for (int i = 1600; i < tt.aar; i++)  {    // ----------- || --------------
        (skuddaar(i)) ?  t2 += 366 : t2 += 365;
    }
    (t2 > t1) ? dagForskjell = (t2 - t1) : dagForskjell = (t1 - t2);
                                    // Summerer differansen mellom t1 og t2
  return dagForskjell;                  // returnerer forskjellen
    }

//  ***********************  DEFINISJON AV FUNKSJONER:  ***********************

void skrivMeny()  {          //  Skriver brukerens valg/muligheter/meny:
  cout << "\n\nFølgende kommandoer er aktuelle:\n";
  cout << "\tS   - Skriv begge tidene\n";
  cout << "\tD   - Dato-innlesning\n";
  cout << "\tP   - Tidspunkt-innlesning\n";
  cout << "\tT   - Tid-innlesning (= Dato + Tidspunkt)\n";
  cout << "\tX   - Tidspunkt-forskjell (når samme dato)\n";
  cout << "\tY   - Dato-forskjell\n";
  cout << "\tQ/A - Quit / Avslutt\n";
}


char lesKommando()  {        //  Leser brukerens valg/ønske/kommando:
  char ch;                   //  Innskrevet tegn.
  cout << "\n\nGi kommando (S, D, P, T, X, Y, Q/A):  ";  //  Ber om ett tegn.
  cin >> ch;    ch = toupper(ch);        //  Leser og upcaser tegn.
  return ch;                 //  Returnerer tegn/kommando.
}

                             //  Leser inn og returnerer verdi i [MIN, MAX]:
int les(const int min, const int max)  {
  int tall;                  //  Innskrevet tallverdi.
  cin >> tall;               //  Leser tall.
  while (tall < min  ||  tall > max)  {    //  Utenfor gyldig intervall:
     cout << "\ti intervallet (" << min << '-' << max << "):  ";
     cin >> tall;
  }
  return tall;               //  Returnerer akseptert (gyldig) tall
}
