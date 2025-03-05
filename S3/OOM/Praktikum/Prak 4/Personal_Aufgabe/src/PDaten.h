#ifndef PDATEN_H
#define PDATEN_H

#include <string>

using namespace std;

class PDaten {
public:

    /**
     * Konstruktor: Initialisert Name mid name und Abteilung mit abtl. - Die Personalnummer ist die tzuletzt vergeben Personalnummer + 1. 
     */
    PDaten(string n, int abtl);

    int gibPNr(){return pNr; }

    void inUrlaubGehen(){ urlaub = true; }

    void vomUrlaubKommen(){ urlaub = false; }

	bool hatUrlaub() { return urlaub; }

    /**
     * Die Personaldaten werden auf dem Bidlschirm ausgegeben. 
     */
    void ausgeben();

private:

    int pNr; // Personalnummer
    string name;
    int abteilung;

    /**
     * True, falls der Mitarbeiter in Urlaub ist, sonst false. 
     */
    bool urlaub;

    /**
     * Die zuletzt vergeben Personalnummer. 
     */
    static int letztePNr;
};
#endif //PDATEN_H
