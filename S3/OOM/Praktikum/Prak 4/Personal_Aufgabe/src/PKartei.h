#ifndef PKARTEI_H
#define PKARTEI_H
#include "PDaten.h"
#include <list>
using namespace std;
class PKartei {
public:
    PKartei(); // Konstruktor
    ~PKartei(); // Destruktor
    /**
    * Einen neuen Mitarbetier mit Namen name in der Abteilung abtl einstellen.
    * Resultat ist die Personalnummer des neuen Mitarbeiters.
    */
    int neuerMA(string name, int abtl);
    /**
    * Den Mitarbeiter mit Personalnummer pnr aus der kartei entfernen. Resultat
    ist false, falls es den Mitarbeiter in der Kartei gibt, sonst false.
    */
    bool loescheMA(int pnr);
    /**
    * Falls m glich, d.h. wenn mehr als 75% der Mitarbeiter anwesend sind, wir der�
    Mitarbeiter mit Personalnummer pnr beurlaubt
    * (d.h. als in Urlaub eingetragen). Das Resultat ist dann true.
    * Falls weniger als 75% der Mitarbeiter anwesend sind, ist das Resultat false.
    */
    bool UrlaubsAntrag(int pnr);
    /**
    * Der Urlaub des Mitarbeiters mit Personalnummer pnr wird wieder ausgetragen
    (falls er tats chlich in urlaub war).�
    */
    void UrlaubEnde(int pnr);
    /**
    * Der Inhalt der Personalkartei wir auf dem Bildschirm ausgegeben.
    */
    void ausgeben();
private:
    /**
    * Liefert einen Zeiger auf das PDaten-Objekt mit Personalnummer i, falls
    vorhanden, sonst null.
    */
    PDaten* gibDaten(int i);
    /**
    * Anzahl der Mitarbeiter
    */
    int anzahl;
    /**
    * Anzahl der anwesenden Mitarbeiter (nicht in Urlaub).
    */
    int anwesend;
    /**
    * Eingebette Objektliste zur implementierung der Komposition
    */
    list <PDaten *> kartei;
};
#endif //PKARTEI_H
Anmerkungen
