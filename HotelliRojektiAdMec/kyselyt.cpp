#include <iostream>
#include <string>
#include <cctype> 
#include "kyselyt.h"
#include "grafiikka.h"
using namespace std;

char paaValikko_kysely() {
    /*
    Sy�tteen tarkastelu p��valikkoon
    */
    
    string syote;

    // Toistetaan niin kauan kun sy�te ei ole kelvollinen
    while (true) {

        cout << "\nINPUT: ";
        getline(cin, syote); // Otetaan sy�te rivilt�

        // Tarkistetaan, ett� sy�te on kelvollinen (vain yksi merkki ja oikea merkki)
        if (syote.length() == 1 && (toupper(syote[0]) == 'R' || toupper(syote[0]) == 'V' || toupper(syote[0]) == 'S' || toupper(syote[0]) == 'X')) {
            return toupper(syote[0]); // Palautetaan iso kirjain
        }

        // Virheilmoitus, jos sy�te on virheellinen
        cout << "\n+++ ERROR: INVALID INPUT DETECTED. +++" << endl;
        cout << "+++ MACHINE SPIRITS REQUIRE CLARITY. TYPE 'R', 'V', 'S', OR 'X'. +++\n";
        cout << "+++ AWAITING PURIFIED INPUT... +++\n\n";
    }
}

char poistutaanko() {
    /*
    Kysyt��n ja tarkistetaan sy�t, haluaako k�ytt�j� positua. 
    */
    
    string syote;

    // Toistetaan niin kauan kun sy�te ei ole kelvollinen
    while (true) {

        cout << "+++ SYSTEM QUERY: SHALL THE SCAN OF ANOTHER HABITAT COMMENCE? +++\n"; pause(400);
        cout << "+++ INPUT REQUIRED: [Y] / [N] +++\n"; pause(20);
        cout << "> INPUT: ";
        getline(cin, syote); // Otetaan sy�te rivilt�

        // Tarkistetaan, ett� sy�te on kelvollinen (vain yksi merkki ja oikea merkki)
        if (syote.length() == 1 && (toupper(syote[0]) == 'Y' || toupper(syote[0]) == 'N')) {
            return toupper(syote[0]); // Palautetaan iso kirjain
        }

        // Virheilmoitus, jos sy�te on virheellinen
        cout << "\n+++ ERROR: INVALID INPUT DETECTED. +++" << endl;
        cout << "+++ MACHINE SPIRITS REQUIRE CLARITY. TYPE 'Y' or 'N'. +++\n";
        cout << "+++ AWAITING PURIFIED INPUT... +++\n\n";
    }
}

