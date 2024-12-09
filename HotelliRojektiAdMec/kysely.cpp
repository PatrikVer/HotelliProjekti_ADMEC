#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>
#include <random>
#include "grafiikka.h"
#include "kysely.h"
using namespace std;

string paaValikko_kysely() {
	
    
    string syote;
    do {
        grafiikkaMainValikko();
        getline(cin, syote);
        if (syote.length() == 1) {
            syote = toupper(syote[0]); // Muutetaan vastaanotettu kirjain suureksi kirjaimeksi
        pause(300);
        if (syote.length() == 1 && (syote[0] == 'V' || syote[0] == 'S' || syote[0] == 'X')){
            
            return syote[0];

        }
        cout << "\n+++ ERROR: INVALID INPUT DETECTED. +++" << endl;
        pause(100);
        cout << "+++ MACHINE SPIRITS REQUIRE CLARITY. TYPE 'Y' FOR *YES* OR 'N' FOR *NO*. +++\n";
        pause(100);
        cout << "+++ AWAITING PURIFIED INPUT... +++\n\n";
        pause(500);
    } while (true);
}