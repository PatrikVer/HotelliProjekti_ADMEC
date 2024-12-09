/*
Patrik Verho 24TietoB
Hotelli projekti Adeptus Mechanicus Twisttill‰. 

Toteutetut lis‰ominaisuudet:
> satunnaiset 40 - 300 hotellihuoentta
> Alennus % 
> ilmoittaa loppusumman
> Tarkistaa onko huone vapaa
> Huomasin vasta nyt ett‰ oli ˆiden m‰‰r‰ toivottu, en sit‰ kerke‰ laittaa ;( 
> 2 olennasita aliohjelmaa

Joten mielest‰ni voisi olla arvosanan (4) arvoinen. V‰hint‰‰nkin kivusta. 
*/




#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <set>
#include <random>
#include "grafiikka.h"
#include "kyselyt.h"
using namespace std;

//Struct jota k‰ytet‰‰n vektorissa
struct hotellihuone {
    string etunimi;
    string sukunimi;
    int huoneNumero;
    bool matkustaaYksin; // true = varattava huone on yhden henkilˆn huone
    bool onkoHuoneVapaa; // true = huone on vapaa
    int varausNumero;
    float alennusProsentti;
    float huoneenHinta;

};



//Tulostaa kaikki huoneen tiedot halutulta indeksi kohdalta. 
void tulostaHuone(vector<hotellihuone>& huoneet, int index); 
//Rakennetaan ja aluestetaan vekktori, mihin on tallennettu struct hotellihuone avulla huoneiden tiedot. 
//Vektori palautetaan main -funktioon mist‰ muut funktiot voivat sit‰ k‰ytt‰‰. 
vector<hotellihuone> hotellinLuominen(); 
//Muiodostaa huone kohtaisen varausnumeron. K‰ytt‰‰ generoiSatunnaisluku() funktiota apunaan.
set<int> varausnumeroGenerointi(const int& huoneidenMaara);
//Generoi satunnaisen luvun min ja max luvun v‰lilt‰, mitk‰ m‰‰ritell‰‰n funktiota kutsuttaessa. 
int generoiSatunnaisluku(int min, int max);
//K‰ytt‰j‰ kykenee tekem‰‰n uuden huone varausken t‰m‰ ohjelman kautta. 
vector<hotellihuone> huoneenVaraaminen(vector<hotellihuone>& huoneet);
//Voidaan huone numerolla etsi‰ kyseisen huoneen tiedot.
void huoneenKatselmoiminen(vector<hotellihuone>& huoneet);
//Tulsotaa hotellin huoneiden yhteenvedon
void hotelliStats(vector<hotellihuone>& huoneet);
//Saadaan k‰sitelty‰ numerot t‰m‰n avulla. En kerennyt siirt‰m‰‰n t‰t‰ kyselyt.cpp Ohjelma heitti aina kunnon separit jos tein niin =D
int kysyNumero(const string& viesti, int maxArvo); 


int main() {
    /*
    "p‰‰funktio" miss‰ sijaitsee ohjelman valikko ja huoneiden alustaminen ja rakentaminen kutsutaan. 
    visuaaliset elementit kutsutaan grafiikka.ccpst‰ ja k‰ytt‰j‰n syˆtteet k‰sitell‰‰n kyselyt.cppss‰.
    */

    
    //Luodaan hotelli, eli hotellihuoneet.
    vector<hotellihuone> huoneet = hotellinLuominen();

    //Avaus grafiikan kutsuminen
    grafiikkaTervetuloa();
    
    //Niin kutsuttu "p‰‰valikko". 
    do {
        system("cls");
        
        //Graafinen esitys p‰‰valikkoob
        grafiikkaMainValikko(); 

        //Kysely mit‰ funktiota k‰ytt‰j‰ haluaa k‰ytt‰‰
        char saatuSyote = paaValikko_kysely();
        
        //Huoneen varaaminen.
        if (saatuSyote == 'R') {
            
            huoneenVaraaminen(huoneet);
        }
        //Valitun huoneen tietojen katsominen.
        else if (saatuSyote == 'V') {
            
            huoneenKatselmoiminen(huoneet);
        }
        //Koko hotellin statuksen katsominen.
        else if (saatuSyote == 'S') {
            
            hotelliStats(huoneet);
        }
        //Ohjelmasta poistuminen.
        else if (saatuSyote == 'X') {

            grafiikkaOhjelmanSammuminen();
            break; //Rikotaan while -looppi ja ohjelma sammuu.
        }
        
    } while (true);

}

void tulostaHuone(vector<hotellihuone>& huoneet, int index) {
    /*
    Funktioon tuodaan parametrein‰ huoneet vektori, sek‰ tulostettavan huoneen indeksi arvo. 
    */


    pause(250);
    cout << "+++ PROCESSING RESERVATIO REQUEST... +++\n"; pause(800);
    system("cls"); pause(500);
    cout << "+++ PROCESSING RESERVATIO REQUEST... +++\n"; pause(1200);
    system("cls"); pause(2000);

    cout << "+++ ACCESSING HABITATIO DATA ARCHIVE +++\n"; pause(150);
    cout << "+++ HABITATIO STATUS REPORT: BLESSINGS UPON THIS HABITATIO +++n\n\n\n"; pause(450);

    cout << "+++ RESERVATION LOG: HABITAT UNIT DESIGNATED +++\n\n"; pause(800);

    cout << "> HABITATIO NUMBER : "; pause(400); cout << huoneet[index].huoneNumero;
    cout << "\n> OCCUPANT IDENTIFICATION:"; pause(400);
    cout << "\n++ PRIMARY IDENT-CODE: "; pause(200); cout << huoneet[index].etunimi; pause(400);
    cout << "\n++ FAMILIAL IDENT-CODE: "; pause(200); cout << huoneet[index].sukunimi; pause(400);
    cout << "\n++ TRAVEL STATUS: "; pause(200);
    if (huoneet[index].matkustaaYksin == 1) { cout << "SOLO PILGRIMAGE (*ONE-PERSON ROOM*)"; }
    else { cout << "++ TRAVEL STATUS: HOLY CONGREGATION (*TWO-PERSON ROOM*) ++"; }
    pause(250);
    cout << "\n++ RESERVATION NUMBER: "; pause(200); cout << huoneet[index].varausNumero; pause(400);

    cout << "\n\n++ HABITATIO  STATUS ++"; pause(200);
    cout << "\n++ STATUS: "; pause(200);
    if (huoneet[index].onkoHuoneVapaa == 0) { cout << "OCCUPIED BY SACRED DECREE."; }
    else { cout << "++ STATUS: VACANT AND BLESSED FOR NEW OCCUPANTS. ++"; }
    pause(250);

    cout << "\n\n> PRICING DETAILS: "; pause(50);
    cout << "\n++ BASE ROOM PRICE:  ";  pause(450); cout << huoneet[index].huoneenHinta << " THRONES"; pause(800);
    cout << "\n++ DISCOUNT APPLIED: "; pause(200); cout << huoneet[index].alennusProsentti; cout << "% (BLESSED DISCOUNT). ++"; pause(400);
    cout << "\n++ FINAL PRICE: "; pause(200); cout << huoneet[index].huoneenHinta - (huoneet[index].huoneenHinta * (huoneet[index].alennusProsentti / 100)); cout << " THRONES. ++"; pause(50);

    cout << "\n\n+++ ALL DATA VERIFIED BY THE MACHINE SPIRITS. PRAISE THE OMNISSIAH. +++\n\n"; pause(2000);

    cout << "+++ PRESS THE SACRED ENTER KEY TO CONTINUE THE RITE. +++";
    cin.get(); //Annetaan k‰ytt‰j‰n katsoa niin kauan tietoja, kun haluaa. Sitten kun k‰yttt‰j‰ painaa Enteri‰- ohjelma sulkee n‰kym‰n ja palaa p‰‰valikkoon. 
    system("cls");

}

vector<hotellihuone> hotellinLuominen() {
    /*
    Rakennetaan ja aluestetaan vekktori, mihin on tallennettu struct hotellihuone avulla huoneiden tiedot. 
    Vektori palautetaan main -funktioon mist‰ muut funktiot voivat sit‰ k‰ytt‰‰. 
    */

    //Alustetaan rand() j‰rjestelm‰n ajan avulla. 
    srand(time(0)); 
    //K‰ytet‰‰n struct hotellihuoneet, vektorin huoneet alustamiseen. 
    vector<hotellihuone> huoneet;
    //Generoidaan satunnaisluku v‰lilkt‰ 40 ja 300
    int huoneidenMaara = generoiSatunnaisluku(40, 300);
    //Tehd‰‰n saadusta satunnaislukusa jaollinen kahdella
    huoneidenMaara -= huoneidenMaara % 2;
    //Jaetaan huoneiden m‰‰r‰ kahteen, toisesta puoliskosta yhden hengen huoneet ja toisesta kahden hengen huoneet. 
    int huoneYhdelle = huoneidenMaara / 2;

    //Generoidaan varausnumerot.
    set<int> varaustunnukset = varausnumeroGenerointi(huoneidenMaara);
    //Muodostetaan it muuttuja ja asetetaan "kursori" alkuun.
    auto it = varaustunnukset.begin();

    //Alustetaan aina yksi huone kerrallaan. 
    for (int i = 0; i < huoneidenMaara; ++i) {
        hotellihuone huone;
        huone.huoneNumero = i + 1;
        huone.etunimi = "<< unassigned primary ident-code >>";
        huone.sukunimi = "<< unassigned familial ident-code >>";
        huone.varausNumero = *it++;
        huone.onkoHuoneVapaa = true;
        //Alennusprosentin alustus
        int genAle = generoiSatunnaisluku(0,24); 
        //Lasketaan alennusporsentti, niin ett‰ se voi olla 0, 5, 10 tai 20 %. 
        huone.alennusProsentti = genAle - (genAle % 5); 

        //Asetetaan ensimm‰inen puolisko huoneista yhden hengen huoneiksi ja laitetaan hinnaksi 100.
        if (i < huoneYhdelle) {
            huone.huoneenHinta = 100;
            huone.matkustaaYksin = true;
        }
        //Toinen puolisko asetetaan kahden hengen huoneiksi ja hinta laitetaan 150.
        else {
            huone.huoneenHinta = 150;
            huone.matkustaaYksin = false;
        }

        //Pusketaan valmisettu huone vektorin per‰lle. 
        huoneet.push_back(huone);
    }
    
    //Palautetaan muodostettu vektori, jotta muut funktiot voivat k‰ytt‰‰ ja muokata sit‰. 
    return huoneet;
}

int generoiSatunnaisluku(int min, int max) {
    /*
    Generoidaan random arvo v‰lilt‰ min ja max, jotka ovat m‰‰ritelty kutsussa. Sitten ·rvo palautetaan.
    */
    return min + rand() % (max - min);
}

set<int> varausnumeroGenerointi(const int& huoneidenMaara) {
    /*
    Generoidaan varausnumero. Varausnumero on satunnainen mutta "tasaisin" v‰limatkoin. 
    */

    //Luodaan satunnaisien arvojen siemen ja asetetaan muuttujaan rd
    random_device rd;
    //Luodaan mersenne twisteri ja k‰ytet‰‰n rd siement‰
    mt19937 generator(rd());
    //Luodaan vekroei tasaisesti jakautuneista arvoista v‰lill‰ 10000 ja 99999
    uniform_int_distribution<int> dist(10000, 99999);
    
    //muodostetaan vektori mihin laitetaan niin monta arvoa kuin on huoneita
    set<int> varaustunnukset;
    while (varaustunnukset.size() < huoneidenMaara) {
        varaustunnukset.insert(dist(generator));
    }
    return varaustunnukset;
}

vector<hotellihuone> huoneenVaraaminen(vector<hotellihuone>& huoneet) {
    /*
    FUnktiossa varataan, eli luodaan uusi huone vektoriin huoneet. Tarkoituksena on kysy‰ k‰ytt‰j‰lt‰ etu- ja sukunimi
    sek‰ onko h‰n yksin vai ei. Jos ei ole yksin niin ohjelma asettaa h‰ˆnet klahden hengen huoneeseen. 
    Ohjelma kirjaa varatun huoneen ensimm‰iseen vapaaseen huoneeseen joka on joko yhden- tai kahden hengen huone, riippuen k‰ytt‰j‰n valinnasta.
    */
    
    //Kutsutaan grafiikka. 
    grafiikkaLataaminen();

    //Muodostetaan varausData vektori, mik‰ k‰ytt‰‰ hotellihuone structia.
    //T‰h‰n tallennetaan k‰ytt‰j‰n valinnat ja sitten siirret‰‰n tiedot huoneet vektoriin. 
    hotellihuone varausData;


    cout << "+++ RESERVATIO-TEMPLUM PROTOCOLS INITIALIZED +++\n";
    pause(500);
    cout << "+++ ENTER DATA TO COMMUNE WITH THE MACHINE SPIRITS OF HABITATIO ++\n\n";
    pause(750);

    cout << "+++ RESERVATIO-TEMPLUM SYSTEM ONLINE +++\n";
    pause(400);
    cout << "+++ ENTER DATA TO COMMUNE WITH THE MACHINE SPIRITS OF HABITATIO +++\n\n";
    pause(400);

    //Kysyt‰‰n varaajan etunimi
    cout << "> QUERY: DESIGNATE YOUR PRIMARY IDENT-CODE [FORENAME]: ";
    getline(cin, varausData.etunimi);
    pause(400);
    //Kysyt‰‰n varaajan sukunimi
    cout << "> QUERY: DESIGNATE YOUR FAMILIAL IDENT-CODE [SURNAME]: ";
    getline(cin, varausData.sukunimi);
    pause(400);

    //Kysyt‰‰n, jos matkustaa yksin. Eli bookataanko yhden- vai kehden hengen huone. 
    char matkustaaYksinCar;
    string syote;
    
    do {
        cout << "> QUERY: WILL YOU TRAVEL SOLO? (TYPE 'Y' FOR YES OR 'N' FOR NO): ";
        getline(cin, syote);
        pause(300);
        if (syote.length() == 1 && (syote[0] == 'Y' || syote[0] == 'N' || syote[0] == 'y' || syote[0] == 'n')) {
            matkustaaYksinCar = toupper(syote[0]); // Muutetaan vastaanotettu kirjain suureksi kirjaimeksi
            cout << endl;

            // Asetetaan matkustaaYksin structiin (Y -> true, N -> false)
            varausData.matkustaaYksin = (!matkustaaYksinCar == 'Y'); //Eli jos matkustaaYksinCar on yht‰ suuri kuin 'Y' niin arvo on tosi. Jos arvo on 'N', niin arvo on false. 
            break;
        }
        cout << "\n+++ ERROR: INVALID INPUT DETECTED. +++" << endl; 
        pause(100);
        cout << "+++ MACHINE SPIRITS REQUIRE CLARITY. TYPE 'Y' FOR *YES* OR 'N' FOR *NO*. +++\n"; 
        pause(100);
        cout << "+++ AWAITING PURIFIED INPUT... +++\n\n"; 
        pause(500);
    } while (true);

    bool y = varausData.matkustaaYksin;

    //Etsit‰‰n ensimm‰inen vektorin index, mik‰ on vapaa sek‰, k‰ytt‰j‰n mukaan, onko huone yhden- vai kahden henkilˆn huone. 
    auto it = find_if(huoneet.begin(), huoneet.end(), [=](const hotellihuone& huoneet) {return huoneet.matkustaaYksin == y && huoneet.onkoHuoneVapaa == true;
        });

    //Asetetaan indeksin arvo muuttujaan. 
    int loydettyIndx = distance(huoneet.begin(), it);

    //Muutetaan nyt huoneet -vektorin muuttujat varausData muuttujilla oikeaan indeksiin. 
    huoneet[loydettyIndx].etunimi = varausData.etunimi;
    huoneet[loydettyIndx].sukunimi = varausData.sukunimi;
    huoneet[loydettyIndx].matkustaaYksin = varausData.matkustaaYksin;
    huoneet[loydettyIndx].onkoHuoneVapaa = false;
    
    //Esitet‰‰n k‰ytt‰j‰lle varaamansa huoneen tiedot.
    tulostaHuone(huoneet, loydettyIndx);
     
    
    //Muokattu huoneet -vektori, sek‰ sen indeksin arvo mit‰ muokattiin. 
    return huoneet; 

}

void huoneenKatselmoiminen(vector<hotellihuone>& huoneet) {
    /*
    Etsit‰‰n huonetta huonenumeron avulla, mink‰ j‰lkeen kyseisen huoneen tiedot tulostetaan.
    */
    
    grafiikkaLataaminen();
    
    do {

        // Etsit‰‰n huonenumeron mukaan huonetta.
        string viesti =
            "+++ SEARCH INITIATED: ROOM NUMBER REQUIRED. +++\n"
            "> ENTER THE SACRED ROOM NUMBER: ";
        
        //Selvitet‰‰n viimeisen hotellihuoneen numero, virhetarkastelua varten.
        int max_arvo = huoneet.size();
        
        //Kutsutaan funktio miss‰ kysyt‰‰n etsitty huone numero k‰ytt‰j‰lt‰
        //Laitetaan samalla max arvo mik‰ hotellihuone numero voi olla mukaan.
        int numero = kysyNumero(viesti, max_arvo);
        tulostaHuone(huoneet, numero);
        
        //Kutsutaan funktio mik‰ selvitt‰‰ haluaako k‰ytt‰j‰ etsi‰ toisen huoneen vai poistuuko p‰‰valikkoon.
        char vastaus = poistutaanko();
        if (vastaus == 'N') {
            break;
        }

    } while (true);
}

void hotelliStats(vector<hotellihuone>& huoneet) {
/*
hotelliStats -funktiossa tulsotetaan "infotaulukko" hotellihuoneista. Funktiossa tehd‰‰n aluksi pient‰ "laskemista", 
mink‰ j‰lkeen tulostetaan pieni otsikko grafiikka ja tulostetaan kuinka monta huonetta hotellissa on, onko ne yksin vai kaksin 
asuttavia huoneita sek‰ mink‰laiset tulot ja mahdolliset tulot hotellilla olisi. 
*/
    
    //Laskee kuinka monta huonetta on varattu.
    int varattujenMaara = count_if(huoneet.begin(), huoneet.end(), [=](const hotellihuone& huoneet) { //laskee palautettujen arvojen summan
        return !huoneet.onkoHuoneVapaa; // Palauttaa true, jos huone ei ole vapaa (eli on varattu)
        });
    
    //Lasketaan huoneet -vektorista kuinka monta huoneista on yksin ment‰vi‰. 
    //T‰ll‰ saadaan myˆs kaksin huoneet, kun v‰hennet‰‰n t‰m‰ kokonais huone m‰‰r‰st‰.
    int yksinHuoneet = count_if(huoneet.begin(), huoneet.end(), [=](const hotellihuone& huoneet) { //laskee palautettujen arvojen summan
        return huoneet.matkustaaYksin; // Palauttaa arvot jotka on tosia kun matkustaa yksin
        });

    
    float hintaVaratutH = 0.0;
    //Lasketaan yhteishinta varatuille huoneille, ottaen huomioon alennus. 
    for (const auto& huone : huoneet) {
        if (!huone.onkoHuoneVapaa) {
            float alennusProsentti = huone.alennusProsentti / 100.0;
            hintaVaratutH += huone.huoneenHinta;
            }
    }

    float hintaVapaatH = 0.0;
    //Lasketaan potentiaalinen arvo huoneille, joita ei ole varattu. 
    for (const auto& huone : huoneet) {
        if (huone.onkoHuoneVapaa) {
            float alennusProsentti = huone.alennusProsentti / 100.0;
            hintaVapaatH += huone.huoneenHinta;
        }
    }
   
    grafiikkaLataaminen();

    system("cls");

    //Kiva pikku alku grafiikka
    for (int i = 0; i < 70; ++i) { cout << "+"; nanopause(700); }//Tulostetaan +++-merkkijono. Ja koodi on t‰ss‰ muodossa jotta olisi v‰h‰n siistimipi
    pause(200);
    cout << "\n+++                SANCTIFIED HABITATIO STATUS REPORT                 +++\n";
    for (int i = 0; i < 70; ++i) { cout << "+"; nanopause(500); }


    cout << "\n\n> TOTAL HABITATIO UNITS IN SYSTEM:               [ "; pause(300); cout << huoneet.size() << " ]\n"; pause(200);
    cout << "> UNITS CURRENTLY OCCUPIED:                      [ "; pause(350); cout << varattujenMaara << "  ]\n"; pause(200);
    cout << "    >> SINGLE-PERSON UNITS OCCUPIED:             [ "; pause(500); cout << yksinHuoneet << " ]\n"; pause(200);
    cout << "    >> TWO-PERSON UNITS OCCUPIED:                [ "; pause(250); cout << huoneet.size() - yksinHuoneet << " ]\n\n"; pause(200);
    
    cout << "> OCCUPIED UNITS YIELD:                          [ "; pause(450); cout << hintaVaratutH << " THRONES ]\n"; pause(300);
    cout << "> POTENTIAL YIELD OF UNUSED UNITS:               [ "; pause(350); cout << hintaVapaatH << " THRONES ]\n\n"; pause(400);

    cout << "+++ MACHINE SPIRITS APPROVE CURRENT EFFICIENCY. +++\n"; pause(500);
    
    cout << "+++ PRESS THE SACRED ENTER KEY TO CONTINUE THE RITE. +++";
    cin.get(); //Annetaan k‰ytt‰j‰n katsoa niin kauan tietoja, kun haluaa. Sitten kun k‰yttt‰j‰ painaa Enteri‰- ohjelma sulkee n‰kym‰n ja palaa p‰‰valikkoon. 
    system("cls");



}

int kysyNumero(const string& viesti, int maxArvo) {
    
    while (true) {
        system("cls");
        cout << viesti;
        string syote;
        getline(cin, syote); // Luetaan syˆte merkkijonona

        // Tarkistetaan, ett‰ syˆte ei ole tyhj‰ ja sis‰lt‰‰ vain numeroita
        if (syote.empty() || !all_of(syote.begin(), syote.end(), ::isdigit)) {
            system("cls");
            pause(500);
            cout << "+++ ERROR: IMPURE INPUT DETECTED. +++\n"; pause(250);
            cout << "+++ MACHINE SPIRITS DEMAND CLARITY. PLEASE TRY AGAIN. +++"; pause(1500);
            continue; // Palaa silmukan alkuun
        }

        // Muutetaan syˆte kokonaisluvuksi
        int numero = stoi(syote);

        // Tarkistetaan, ett‰ luku on sallitulla alueella
        if (numero < 1 || numero > maxArvo) {
            cout << "+++ ERROR: INPUT OUT OF RANGE. +++\n"; pause(250);
            cout << "+++ MACHINE SPIRITS DEMAND VALID INPUT. PLEASE TRY AGAIN. +++"; pause(1500);
            continue; // Palaa silmukan alkuun
        }

        return numero - 1; // Palautetaan kelvollinen numero (muutettu indeksin mukaan)
    }
}