## Zu Bearbeiten
```C++
// Vorzeichenlose ganze Zahl.
using uint = unsigned int;

// Als Binomial-Halde implementierte Minimum-Vorrangwarteschlange
// mit PrioritÃ¤ten des Typs P und zusÃ¤tzlichen Daten des Typs D.
// An der Stelle, an der BinHeap fÃ¼r einen bestimmten Typ P verwendet
// wird, muss ein Kleiner-Operator (<) fÃ¼r den Typ P bekannt sein.
// Werte des Typs P dÃ¼rfen nur mit diesem Operator verglichen werden;
// die Ã¼brigen Vergleichsoperatoren (<=, >, >=, ==, !=) dÃ¼rfen nicht
// verwendet werden.
template <typename P, typename D>
struct BinHeap {
    // Notwendige Vorabdeklaration.
    struct Node;

    // Eintrag einer solchen Warteschlange bzw. Halde, bestehend aus
    // einer PrioritÃ¤t prio mit Typ P und zusÃ¤tzlichen Daten data mit
    // Typ D.
    // Wenn der Eintrag momentan tatsÃ¤chlich zu einer Halde gehÃ¶rt,
    // verweist node auf den zugehÃ¶rigen Knoten eines Binomialbaums
    // dieser Halde; andernfalls ist node ein Nullzeiger.
    struct Entry {
	// PrioritÃ¤t, zusÃ¤tzliche Daten und zugehÃ¶riger Knoten.
	P prio;
	D data;
	Node* node;

	// Initialisierung mit PrioritÃ¤t p und zusÃ¤tzlichen Daten d.
	Entry (P p, D d) : prio(p), data(d), node(nullptr) {}
    };

    // Knoten eines Binomialbaums innerhalb einer solchen Halde.
    // Neben den eigentlichen Knotendaten (degree, parent, child,
    // sibling), enthÃ¤lt der Knoten einen Verweis auf den zugehÃ¶rigen
    // Eintrag.
    struct Node {
	// ZugehÃ¶riger Eintrag.
	Entry* entry;

	// Grad des Knotens.
	uint degree;

	// VorgÃ¤nger (falls vorhanden; Nullzeiger bei einem Wurzelknoten).
	Node* parent;

	// Nachfolger mit dem grÃ¶ÃŸten Grad
	// (falls vorhanden; Nullzeiger bei einem Blattknoten).
	Node* child;

	// ZirkulÃ¤re Verkettung aller Nachfolger eines Knotens
	// bzw. einfache Verkettung aller Wurzelknoten einer Halde,
	// jeweils sortiert nach aufsteigendem Grad.
	Node* sibling;

	// Initialisierung als Wurzelknoten mit Grad 0 und Eintrag e,
	// der dann auf diesen Knoten zurÃ¼ckverweist.
	Node (Entry* e) : entry(e), degree(0),
		parent(nullptr), child(nullptr), sibling(nullptr) {
	    e->node = this;
	}
    };

    // Anfang der Wurzelliste (Nullzeiger bei einer leeren Halde).
    Node* head;

    // Initialisierung als leere Halde.
    BinHeap ()

    // Ist die Halde momentan leer?
    bool isEmpty ()

    // GrÃ¶ÃŸe der Halde, d. h. Anzahl momentan gespeicherter EintrÃ¤ge
    // liefern.
    uint size ()

    // Neuen Eintrag mit PrioritÃ¤t p und zusÃ¤tzlichen Daten d erzeugen,
    // zur Halde hinzufÃ¼gen und zurÃ¼ckliefern.
    Entry* insert (P p, D d) {
		Entry* e = new Entry(p, d);
		Node* tmp = new Node(e);
		merge ...
		return e;   
    }
    // Eintrag mit minimaler PrioritÃ¤t liefern.
    // (Nullzeiger bei einer leeren Halde.)
    Entry* minimum () { 
	    
    }
	
    // Eintrag mit minimaler PrioritÃ¤t liefern
    // und aus der Halde entfernen (aber nicht freigeben).
    // (Bei einer leeren Halde wirkungslos mit Nullzeiger als Resultatwert.)
    Entry* extractMin () {
	    
    }

    // EnthÃ¤lt die Halde den Eintrag e?
    // (Resultatwert false, wenn e ein Nullzeiger ist.)
    bool contains (Entry* e)

    // PrioritÃ¤t des Eintrags e auf p Ã¤ndern.
    // Hierbei darf auf keinen Fall ein neues Entry-Objekt entstehen,
    // selbst wenn die Operation intern als Entfernen und Neu-EinfÃ¼gen
    // implementiert wird.
    // (Wirkungslos mit Resultatwert false, wenn e ein Nullzeiger ist
    // oder e nicht zur aktuellen Halde gehÃ¶rt; sonst Resultatwert true.)
    bool changePrio (Entry* e, P p) {
	    if (contains(e)) return false; //oder so
    }

    // Eintrag e aus der Halde entfernen (aber nicht freigeben).
    // (Wirkungslos mit Resultatwert false, wenn e ein Nullzeiger ist
    // oder e nicht zur aktuellen Halde gehÃ¶rt; sonst Resultatwert true.)
    bool remove (Entry* e)

    // Inhalt der Halde zu Testzwecken ausgeben.
    void dump ()
};
```

## Testprogramm
```C++
#include <iostream>
#include <string>
using namespace std;

#include "binheap.h"

// Interaktives Testprogramm fÃ¼r die Klasse BinHeap.
int main (int argc, char** argv) {
    // Wenn ein beliebiges Kommandozeilenargument angegeben ist,
    // werden die eingegeben Befehle auch ausgegeben.
    bool echo = argc > 1;

    // Halde mit PrioritÃ¤ten des Typs string und zugehÃ¶rigen Daten des
    // Typs int.
    // (Die Implementierung muss aber natÃ¼rlich auch mit anderen
    // Typen funktionieren.)
    // Der Kleiner-Operator fÃ¼r string implementiert einen
    // lexikographischen Vergleich.
    BinHeap<string, int> heap;

    // Reihe mit allen eingefÃ¼gten EintrÃ¤gen, damit sie spÃ¤ter
    // fÃ¼r remove und changePrio verwendet werden kÃ¶nnen.
    BinHeap<string, int>::Entry* entrys [100];

    // Anzahl der bis jetzt eingefÃ¼gten EintrÃ¤ge.
    uint n = 0;

    // Endlosschleife.
    while (true) {
	// Inhalt und GrÃ¶ÃŸe der Halde ausgeben.
	heap.dump();
	cout << heap.size() << " entry(s)" << endl;

	// Befehl von der Standardeingabe lesen
	// und die entsprechende Operation auf der Halde ausfÃ¼hren.
	string cmd, prio;
	uint entry;
	BinHeap<string, int>::Entry* e;

	cout << "cmd: ";
	cin >> cmd;
	if (echo) cout << cmd;

	switch (cmd[0]) {
	case '+': // insert prio
	    // Die laufende Nummer n wird als zusÃ¤tzliche Daten
	    // verwendet.
	    cin >> prio;
	    if (echo) cout << " " << prio << endl;
	    entrys[n] = heap.insert(prio, n);
	    n++;
	    break;
	case '-': // remove entry
	    cin >> entry;
	    if (echo) cout << " " << entry << endl;
	    heap.remove(entrys[entry]);
	    break;
	case '?': // minimum
	    e = heap.minimum();
	    if (echo) cout << endl;
	    cout << "minimum: " << e->prio << " " << e->data << endl;
	    break;
	case '!': // extractMin
	    e = heap.extractMin();
	    if (echo) cout << endl;
	    cout << "minimum: " << e->prio << " " << e->data << endl;
	    break;
	case '=': // changePrio entry prio
	    cin >> entry >> prio;
	    if (echo) cout << " " << entry << " " << prio << endl;
	    heap.changePrio(entrys[entry], prio);
	    break;
	case 'q': // quit
	    if (echo) cout << endl;
	    return 0;
	}
    }
}

```