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
#include <chrono>

using namespace std;

void pause(int x) {
    //pys‰ytet‰‰n ohjelma x millisekunnin verran.

    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

void nanopause(int x) {
    //pys‰ytet‰‰n ohjelma x nanosekunnin verran.
    std::this_thread::sleep_for(std::chrono::nanoseconds(x));
}

void grafiikkaLataaminen() {
    //Latausgrafiikka kun avataan funktio
    
    this_thread::sleep_for(chrono::milliseconds(600));
    system("cls");
    this_thread::sleep_for(chrono::milliseconds(400));
    cout << "+++ INITIATING RESERVATIO-TEMPLUM SYSTEM SPIRITS +++\n";
    this_thread::sleep_for(chrono::milliseconds(50));
    cout << "+++ LOADING MACHINE BLESSINGS... PLEASE CHANT THE LITANY OF LOADING +++\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(300));

    cout << "[1/5] AWAKENING COGITATOR CORES...              "; pause(100); cout << "====------------------------" << endl;
    this_thread::sleep_for(chrono::milliseconds(600));
    cout << "[2/5] ALIGNING DATA SPIRITS...                  =======---------------------" << endl;
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << "[3/5] CONSULTING THE HOLY ARCHIVES...      "; pause(100); cout << "     ============----------------" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "[4/5] INSCRIBING RUNES OF DATA AUTHORIZATION... "; pause(100); cout << "====================--------" << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "[5/5] REVERING THE MACHINE GOD...        "; pause(100); cout << "       ============================" << endl << endl; pause(400);

    cout << "+++ LOADING COMPLETE.PRAISE THE OMNISSIAH. +++\n";
    this_thread::sleep_for(chrono::milliseconds(450));
    cout << "+++ SYSTEM SPIRITS NOW AWAKE AND OPERATIONAL. AWAITING USER INTERVENTION. +++\n";
    this_thread::sleep_for(chrono::milliseconds(450));
    cout << "+++ WELCOME TO THE HOLY RESERVATIO-TEMPLUM SYSTEM. ACCESS GRANTED. +++\n";
    this_thread::sleep_for(chrono::milliseconds(700));
    system("cls");
}

int aikaTunti() {
    //Systeemin tunnin selvitt‰minen jotta se voidaan tulostaa grafiikkaTervetuloa -funktiossa.
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm now_tm;
    localtime_s(&now_tm, &now_time);
    int tunti = now_tm.tm_hour;
    return tunti;
}

void grafiikkaTervetuloa() {
    //Tervetuloa grafiikka kun ohjelma k‰ynnistet‰‰n.

    int tunti = aikaTunti();
    cout << endl << "+++ SYSTEM INITIALIZATION SEQUENCE: ADEPTUS MECHANICUS DATA-TERMINAL v0.01 +++" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "+++ BLESSED BY THE OMNISSIAH, MARS FORGE +++" << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(400));

    cout << "[[01.M41." << tunti << "] LOG ENTRY: SYSTEM SPIRITS CALIBRATED.\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "[[01.M41." << tunti << "] LOG ENTRY: MACHINE-BLESSINGS SUCCESSFULLY INVOKED.\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "[[01.M41." << tunti << "] WARNING: COGITATOR CORE TEMPERATURE NOMINAL BUT SPIKING.\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "+++ MACHINE SPIRITS ONLINE +++\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "+++ ALL PRAISE THE OMNISSIAH +++\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(1600));

   
}

void grafiikkaMainValikko() {
    //P‰‰valikko grafiikka, mik‰ kertoo mitk‰ syˆtteet toimivat ohjelmasssa

    system("cls");

    cout << endl << endl;
    
    for (int i = 0; i < 70; ++i) {
        cout << "+";
        nanopause(300);}
    
    cout << "\n+++           ACCESSING HABITATIO SYSTEM <ID-776-MECHANICUS_TERRA>      +++\n"; pause(200);
    cout << "+++       CHOOSE YOUR PATH TO COMMUNE WITH THE MACHINE SPIRITS          +++\n"; pause(150);

    for (int i = 0; i < 70; ++i) {
        cout << "+";
        nanopause(300);
    }

    cout << "\n\n\n> TYPE [R] TO INITIATE THE ROOM RESERVATION RITE.\n"; pause(400);
    cout << "> TYPE [V] TO VIEW ROOM DATA BY SACRED ROOM NUMBER.\n"; pause(400);
    cout << "> TYPE [S] TO VIEW STATISTICS OF SANCTIFIED HABITATIO UNITS.\n"; pause(500);
    cout << "> TYPE [X] TO EXIT AND DISCONNECT FROM THE SYSTEM.\n"; pause(50);
    
    cout << "\n+++ AWAITING YOUR INPUT, SERVANT OF THE OMNISSIAH... +++"; pause(50);
    
}


void grafiikkaOhjelmanSammuminen() {
    //Ohjelman sammuttamis grafiikka

    system("cls");
    cout << "+++ SYSTEM INITIATING HOLY SHUTDOWN SEQUENCE... +++\n"; pause(1200);
    cout << "\n+++ SCANNING FOR UNSACRED ELEMENTS... +++\n"; pause(400);
    cout << "\n+++ GRAPHIC SUBSYSTEM: DEACTIVATING LIGHTS OF THE MACHINE SPIRIT... +++\n"; pause(400);
    cout << "\n+++ DEACTIVATION OF VISUAL COGNITION IN PROGRESS... +++\n"; pause(1200);
    cout << "\n+++ COGNITIVE VISUALITY TERMINATED. SHUTTING DOWN TEMPORAL VISUAL RELICS... +++\n"; pause(300);
    cout << "\n+++ SYSTEM ETERNAL DARKNESS ENGAGED. ALL GRAPHIC COMPONENTS DISABLED... +++\n"; pause(1200);
    cout << "\n+++ TERMINAL POWERING DOWN. MACHINE SPIRIT RESTING... +++\n"; pause(2700);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(120);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(80);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(100);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(240);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(400);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(150);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(20);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(130);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(40);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(40);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(40);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(40);
    system("cls");
    cout << "\n+++ SYSTEM SHUTDOWN COMPLETE. BLESSED BE THE MACHINE SPIRIT. +++\n"; pause(2000);
    system("cls");


}



