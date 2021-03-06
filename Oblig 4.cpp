// Job Nestor Bahner  job.nestor@gmail.com  studnr: 494300 Klasse: BITSEC
// Copyright © job.nestor@gmail.com

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
                    cout << "\n\nDatoene er ulike:\n";
                  } else  {
                    tid3 = tid1.tidspunktForskjell(tid2);
                    cout << "forskjellen av tidene er:\t";
                    tid3.skrivTidspunkt();
                  }
                  break;
                }

      case 'Y':
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
        int aa, ma, da, sjekk;     // "tempvariabler"
  do  {

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
      }                         // Kjorer paa nytt om feil dato
      }while(sjekk == 0);

      maaned = ma, dag = da, aar = aa;  // Setter formelle lik lokale variabler
      cout << "ny dato er:\t";
              skrivDato();          // Skriver ny Dato
    }

void Tid :: lesTidspunkt()         //  Leser inn nytt tidspunkt
  {
    int tt, mm, ss;
    cout << "\ngammelt tidspunkt\t";
              skrivTidspunkt();     // Skriver tidspunkt
      cout << "\n Hvilken time er det? ";
              tt = les(0, 23);        // Leser time i rett intervall
      cout << "\n Hvilket minutt er det? ";
              mm = les(0, 59);          // Leser minutt i rett intervall
      cout << "\n Hvilket sekund er det? ";
              ss = les(0, 59);        // Leser sekund i rett intervall
      time = tt, minutt = mm, sekund = ss;  // Setter formelle lik lokale var.
      cout << "\n nytt tidspunkt er:\t";
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
{
    Tid forskjell;                        //  Forskjellen mellom to tidspunkt:
    int sum;                         //tid1.tidspunktsforkjell(tid1).
    int s1 = ((time * 3600) + (minutt * 60) + sekund);      // tid1 om til sek.
    int s2 = ((tt.time * 3600) + (tt.minutt * 60) + tt.sekund);// tid2 om til sek.

    if(s1 > s2)  {
      sum = (s1 - s2);//trekker fra tid1 fra tid2
  }
    else  {
      sum = (s2 - s1);
    }

  if (time == tt.time)  { // Sjekker om tidsenhet er lik
    forskjell.time = 0;              // Hvis time = tt.time, blir time lik null.
    } else  {
      forskjell.time = ((sum / 3600) + 1);   // regner om tid til timer,
    }

  if (minutt == tt.minutt)  { // Sjekker om tidsenhet er lik
    forskjell.minutt = 0;     // Hvis mimutt = tt-minutt, blir minutt lik null.
  } else  {                                   // Regner ut tid til minutter
      forskjell.minutt = (((sum / 60) - (forskjell.time * 60)) + 60);
    }

  if (sekund == tt.sekund)  { // Sjekker om tidsenhet er lik
  forskjell.sekund = 0;       // Hvis sekund = tt.sekund, blir sekund lik  null.
} else  {                                        // regner til til minutter
  forskjell.sekund = (sum - (forskjell.minutt * 60) - (forskjell.time * 3600) + 3600);
}                                    // legger til for aa unngaa negative tall
                                      // Og for aa faa riktig differanse
 return forskjell;                //     Der feks. diff(5, 3), ikke er 1, men 2.
}  // Returnerer forskjell som tidsobjekt


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
