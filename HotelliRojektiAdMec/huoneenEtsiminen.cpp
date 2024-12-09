/*
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
using namespace std;

vector<hotellihuone> huoneenVaraaminen(vector<hotellihuone>& huoneet) {
    // grafiikkaLataaminen();

    hotellihuone varausData;

    for (int i = 0; i < huoneet.size(); i++) {
        cout << "T‰m‰p‰ t‰‰ll‰" << endl << endl;
        cout << huoneet[i].huoneNumero << " \n";
        cout << huoneet[i].etunimi << " \n";
        cout << huoneet[i].sukunimi << " \n";
        cout << huoneet[i].varausNumero << " \n";
        cout << huoneet[i].onkoHuoneVapaa << " onko vapaa??\n";
        cout << huoneet[i].alennusProsentti << " \n";
        cout << huoneet[i].huoneenHinta << " \n";
        cout << huoneet[i].matkustaaYksin << "matkusta yksin \n";
    }


    cout << "+++ RESERVATIO-TEMPLUM PROTOCOLS INITIALIZED +++\n";
    this_thread::sleep_for(chrono::milliseconds(50));
    cout << "+++ ENTER DATA TO COMMUNE WITH THE MACHINE SPIRITS OF HABITATIO ++\n\n";
    this_thread::sleep_for(chrono::milliseconds(50));

    cout << "+++ RESERVATIO-TEMPLUM SYSTEM ONLINE +++\n";
    cout << "+++ ENTER DATA TO COMMUNE WITH THE MACHINE SPIRITS OF HABITATIO +++\n\n";

    //Kysyt‰‰n varaajan etunimi
    cout << "> QUERY: DESIGNATE YOUR PRIMARY IDENT-CODE [FORENAME]: ";
    getline(cin, varausData.etunimi);

    //Kysyt‰‰n varaajan sukunimi
    cout << "> QUERY: DESIGNATE YOUR FAMILIAL IDENT-CODE [SURENAME]: ";
    getline(cin, varausData.sukunimi);

    //Kysyt‰‰n, jos matkustaa yksin. Eli bookataanko yhden- vai kehden hengen huone.
    char matkustaaYksinCar;
    string syote;
    do {
        cout << "> QUERY: WILL YOU TRAVEL SOLO? (TYPE 'Y' FOR YES OR 'N' FOR NO): ";
        getline(cin, syote);


        if (syote.length() == 1 && (syote[0] == 'Y' || syote[0] == 'N' || syote[0] == 'y' || syote[0] == 'n')) {
            matkustaaYksinCar = toupper(syote[0]); // Muutetaan vastaanotettu kirjain suureksi kirjaimeksi
            cout << endl;

            //Asetetaan matkustaaYksincar structuriin.
            varausData.matkustaaYksin = matkustaaYksinCar;
            break;
        }
        cout << "\n+++ ERROR: INVALID INPUT DETECTED. +++" << endl;
        cout << "+++ MACHINE SPIRITS REQUIRE CLARITY. TYPE 'Y' FOR *YES* OR 'N' FOR *NO*. +++\n";
        cout << "+++ AWAITING PURIFIED INPUT... +++\n\n";
    } while (true);

    cout << varausData.matkustaaYksin << "matkustaako yksin?";
    bool y = varausData.matkustaaYksin;

    //Etsit‰‰n ensimm‰inen vektorin index, mik‰ on vapaa sek‰, k‰ytt‰j‰n mukaan, onko huone yhden- vai kahden henkilˆn huone.
    auto it = find_if(huoneet.begin(), huoneet.end(), [=](const hotellihuone& element) {return element.matkustaaYksin == y && element.onkoHuoneVapaa == true;
        });


    int loydettyIndx = distance(huoneet.begin(), it);

    if (it != huoneet.end()) {

        huoneet[loydettyIndx].etunimi = varausData.etunimi;
        huoneet[loydettyIndx].sukunimi= varausData.sukunimi;



        cout << "Lˆydetty elementti indeksist‰: " << loydettyIndx << "\n";
        cout << "matkustaa yksin: " << it->matkustaaYksin << ", onkoHuonevapaa: " << it->onkoHuoneVapaa << ", luku: " << "\n";
    }

    cout << "+++ PROCESSING RESERVATIO REQUEST... +++\n";

    this_thread::sleep_for(chrono::milliseconds(1000));



    this_thread::sleep_for(chrono::milliseconds(500));


    return huoneet;

}

vector<hotellihuone> valikko_huoneenEtsiminen(vector<hotellihuone>& huoneet) {
    string vas;
    do {
        cout << "\nINPUT: ";
        getline(cin, vas);
        //[R]oom number, reservation [N]umber, [S]urename  
        if (vas == "R" || vas == "r" || vas == "N" || vas == "n" || vas == "S" || vas == "s") {
            break;

        }
        else {
            cout << "\n+++ ERROR: INVALID INPUT DETECTED. +++" << endl;
            cout << "+++ MACHINE SPIRITS REQUIRE CLARITY. TYPE 'Y' FOR *YES* OR 'N' FOR *NO*. +++\n";
            cout << "+++ AWAITING PURIFIED INPUT... +++\n\n";
        }
    } while (true);

    //Muunnetaan kirjain isoksi, jos se ei ole sit‰ viel‰. 
    transform(vas.begin(), vas.end(), vas.begin(), ::toupper);

    if (vas == "R") {

    }
    else if (vas == "N") {

    }
    else if (vas == "S") {

    }
    */