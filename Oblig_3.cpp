// Job Nestor Bahner stud.nr: 494300 BITSEC Oblig_3
#include <iostream>
#include <cctype>
using namespace std;
void couting();

struct fraction {
        int t = 0;                // t = Teller.
        int n = 0;                // n = Nevner.
};
char ans;

int main()  {
        fraction brk1, brk2, brk3, temp, temp1, temp2;
        char op;
        // Teller opp antall structer:
        for ( int i = 1; i <= 3; i++ )  {
                cout << "gi brok " << i << " verdi \n"; // Gir brøkene verdier:
                cout << "teller: "; cin >> temp.t; // Gjør dette for 3 structer
                do  {                         //hvis nevner <= 0 loop
                        cout << "Nevner: "; cin >> temp.n;
                } while (temp.n <= 0);  // Spør bruker om tall, hvis nevner > 0

                switch (i) {
                case 1: { brk1 = temp; break; }
                case 2: { brk2 = temp; break; }
                case 3: { brk3 = temp; break; }
                default: { cout << "ERROR"; break; }
                }
        }                        // Looper Brøkvalg så lenge ugyldig alternativ:
        couting();
        while ((ans != 'Q') && (ans != 'q'))  {// Looper brøker og operasjoner:
                switch (toupper(ans))  { // Setter alternative brøker  lik temp:
                case 'A': { temp1 = brk1; temp2 = brk2; break; }
                case 'B': { temp1 = brk1; temp2 = brk3; break; }
                case 'C': { temp1 = brk2; temp2 = brk3; break; }
                }
                do  {                           //looper hvis feil operasjon:
                        cout << "Velg Operasjon (+,-,*,/): \n" << '\n';
                        cin >> op;              // Velger operasjon.

                } while (op != '+' && op != '-' && op != '*' && op != '/');
                //couter operasjon for alle brøker
                cout << '\t' << temp1.t << "/" << temp1.n << op
                     << temp2.t << "/" << temp2.n << " = ";
                //brøkmatematikk
                switch(op)  {
                case '+':  {
                        temp.t = ((temp1.t * temp2.n) + (temp1.n * temp2.t));
                        temp.n = ((temp1.n) * (temp2.n));
                }
                case '-':  {
                        temp.t = (((temp1.t) * (temp2.n)) + ((temp1.n) * (temp2.t)));
                        temp.n = ((temp1.n) * (temp2.n));
                }
                case '*':  {
                        temp.t = ((temp1.t) * (temp2.t));
                        temp.n = ((temp1.n) * (temp2.n));
                }
                case '/':  {
                        temp.t = ((temp1.t) * (temp2.n));
                        temp.n = ((temp1.n) * (temp2.t));
                }
                        cout << temp.t << "/" << temp.n << '\n'; break;
                }
                couting();
        }
        return 0;
}

//funksjon for couting av valg:
void couting()  {
        do  {
                cout << "\nvelg broker \n alt.'A'. (1, 2) \n alt."
                     << "'B'. (1, 3) \n alt.'C'. (2, 3) \n Q - quit \t";
                cin >> ans;   ans = toupper(ans);
        } while(ans != 'A' && ans != 'B' && ans != 'C' && ans != 'Q');
}
