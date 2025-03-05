// Personal.cpp : Hauptprogramm
#include "PDaten.h"
#include "PKartei.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    PKartei PK ; //Die Personalkartei
    char Kommando ; // zum Einlesen von Kommandos
    int i,x ; // Zum Einlesen/Speichern von Zahlen
    char s[128]; // zum Einlesen von Zeichenketten
    do
        // Kommandoschleife
    {
        // Men ausgeben�
        cout << "\n0=Ende 1=Kartei anschauen"
        << "\n2=neuer Mitarbeiter, 3=Mitarbeiter l schen"�
        << "\n4=Urlaubsantrag, 5=Urlaub beenden"
        << "\n>>> " ; //Prompt
        cin >> Kommando ; cin.ignore(128,'\n');
        switch(Kommando)
        {
        case '0': break ;
        case '1': cout << "\nInhalt der Personalkartei: \n" ;
            PK.ausgeben() ;
            cout << '\n' ;
            break ;
        case '2': cout << "Name: " ; cin.getline(s,128) ;
            cout << "Abteilung: " ; cin >> i ; cin.ignore();
            x = PK.neuerMA(s,i);
            cout << "Personalnummer: " << x << '\n';
            break ;
        case '3': cout << "Personalnummer: " ; cin >> i ; cin.ignore();
            if(PK.loescheMA(i))
                cout << "Nr.: " << i << " gel scht!\n" ;�
                else
                    cout << "Kein Mitarbeitern mit Personalnummer "
                    << i <<"!\n";
            break ;
        case '4': cout << "Personalnummer: " ; cin >> i ; cin.ignore();
            if ( PK.UrlaubsAntrag(i) )
                cout << "O.K:!\n" ;
            else
                cout << "abgelehnt!\n";
            break ;
        case '5': cout << "Personalnummer: " ; cin >> i ; cin.ignore();
            PK.UrlaubEnde(i) ;
            break ;
        default: cout << "Unzul ssiges Kommando!" ;�
        }
    }
    while (Kommando != '0') ;
    return 0;
}
Anmerkungen
