//Oblig_2   Job Nestor Bahner 18.09.2017
// Programmet spor om og regner ut temperaturer (min, max) og
//hvor mye det regner. Deretter gir det en maaneds gjennomsnittstemp (min, max)
//og gjennomsnittlig regnmengde, etterfulgt av valgmulighet for ny maaneds
//vaerdata og gir en koselig melding om brukern ikke har mer data.
#include <iostream>
using namespace std;
const int MINTEMP = -70, MAXTEMP = 70, MAXRAIN = 200,
MINRAIN = 0, MINDAY = 27, MAXDAY = 32;                    //Mye brukte variabler

int main()  {
        char ans;                         //Svarvariabel
        int MinTempVar, MaxTempVar, TotMinTemp, //lager samlingsvariabler
            TotMaxTemp, TotRain, rainfall, days = 0, i;
        do  {                             //løkke for hele programmet og restart
                TotMinTemp = 0; TotMaxTemp = 0; //nullstiller variabler
                TotRain = 0; i = 1;

                do  {                     //spør om dager
                        cout << "Days in your month??\n";
                        cin >> days;
                } while(days <= MINDAY || days >= MAXDAY);

                for (i; days <= i; i++)  {   //sikrer rett intervall
                        cout << "Dag " << i << '\n'; //forteller hvilken dag det er

                        do  {
                                cout << "Minimum temperature? (" << MINTEMP << ")\n";
                                cin >> MinTempVar; //for min temp
                        } while(MinTempVar < MINTEMP || MinTempVar > MAXTEMP);
                        TotMinTemp += MinTempVar; //sikrerer tempintervall og matte

                        do  {
                                cout << "Maximum temperature? (Higher than " << MinTempVar << ")\n";
                                cin >> MaxTempVar;
                        } while(MaxTempVar > MAXTEMP || MaxTempVar < MinTempVar);
                        TotMaxTemp += MaxTempVar; //sikrer intervall og adderer til tot

                        do  {
                                cout << "How much rain today? "
                                     << MINRAIN << " - " << MAXRAIN <<  " mm\n";
                                cin >> rainfall;
                        } while(rainfall >= MAXRAIN || rainfall <= MINRAIN);
                        TotRain += rainfall; //sikrer regnintervall og adderer tot

                }

                cout << "Average minimum temperature: "
                     << float(TotMinTemp) / i << '\n'
                     << "Average maximum temperature: "
                     << float(TotMaxTemp) / i << '\n'
                     << "Average rainfall: "
                     << float(TotRain) / i << '\n'
                     << "total rainfall: "
                     << float(TotRain) << '\n'
                     << "Another month?\n";
                cin >> ans;

        } while ( ans == 'j' || ans == 'J');
        cout << "Ha en fin dag!" << '\n'; //koselig melding
        return 0;
}
