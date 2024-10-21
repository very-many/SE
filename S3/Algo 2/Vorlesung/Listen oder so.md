``` Cpp
// Vorzeichenlose ganze Zahl.
using uint = unsigned int;

// Verkettete Liste mit Elementen des Typs T.
template <typename T>
struct List
{
    // Knoten einer solchen Liste.
    struct Node
    {
        T elem;     // Element.
        Node *next; // Zeiger auf den nÃ¤chsten Knoten oder Nullzeiger.

        // Initialisierung mit Element e und Verkettungszeiger n.
        Node(T e, Node *n) : elem(e), next(n) {}
    };

    // Zeiger auf den ersten Knoten oder Nullzeiger.
    Node *head;

    // Initialisierung als leere Liste.
    List() : head(nullptr) {}

    // Element x zur Liste hinzufÃ¼gen (und zwar am Anfang).
    void add(T x)
    {
        head = new Node(x, head);
    }

    // i-tes Element der Liste (gezÃ¤hlt ab 0) Ã¼ber den Referenz-
    // parameter x zurÃ¼ckliefern, falls vorhanden.
    // Resultatwert true genau dann, wenn es ein i-tes Element gibt.
    bool get(uint i, T &x)
    {
        for (Node *p = head; p; p = p->next, i--)
        {
            if (i == 0)
            {
                x = p->elem;
                return true;
            }
        }
        return false;
    }

    // Das erste Element x aus der Liste entfernen, falls vorhanden.
    // Resultatwert true genau dann, wenn Element x vorhanden war.
    // Bei Verwendung dieser Funktion muss es einen Operator == zum
    // Vergleich zweier Objekte des Typs T geben. Bei Bedarf kann so
    // ein Operator passend definiert werden, vgl. Â§ 1.4.9.
    bool remove(T x)
    {
        Node *q = nullptr;
        for (Node *p = head; p; q = p, p = p->next)
        {
            if (p->elem == x)
            {
                if (q)
                    q->next = p->next;
                else
                    head = p->next;
                delete p;
                return true;
            }
        }
        return false;
    }
};

#include <iostream> // cin, cout, endl
#include <string>   // string
using namespace std;

// Interaktives Testprogramm.
int main()
{
    // Liste von Zeichenketten.
    List<string> ls;

    // Hilfsvariablen.
    string cmd, elem;

    // Befehle von der Standardeingabe lesen und verarbeiten:
    // + elem -> elem zur Liste hinzufÃ¼gen
    // ? i    -> i-tes Element der Liste ausgeben
    // - elem -> elem aus der Liste entfernen
    // q      -> Programm beenden

    while (cout << "cmd: ", cin >> cmd)
    {
        if (cmd == "+")
        {
            cin >> elem;
            ls.add(elem);
        }
        else if (cmd == "?")
        {
            uint i;
            cin >> i;
            if (ls.get(i, elem))
                cout << elem;
            cout << endl;
        }
        else if (cmd == "-")
        {
            cin >> elem;
            ls.remove(elem);
        }
        else if (cmd == "q")
        {
            break;
        }
    }
}

```
