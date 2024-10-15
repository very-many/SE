``` Cpp
#include <iostream>
#include <string>
using namespace std;

using uint = unsigned int;

template <typename T>
//Verkettete Liste von Zeicheketten
struct List
{
    struct Node
    {
        T elem;
        Node* next;

        Node (T e, Node* n) : elem(e), next(n) {}
    };

    Node* head;

    List () : head(nullptr) {}

    void add (T x)
    {
        head = new Node(x, head);
    }

    // I-tes Element aus einer Liste finden
    bool get (uint i, T &x)
    {
        Node* p = head;
        while (i > 0 && p != nullptr)
        {
            p = p->next;
            i--;
        }
        if (p == nullptr) return false;
        x = p->elem;
        return true;;
    }

    // Das erste Element x aus der Liste entfernen, falls vorhanden
    bool remove (T x)
    {
        Node* q = nullptr;
        for (Node* p = head; p != nullptr; q = p, p = p->next)
        {
            if (p->elem == x)
            {
                if (q != nullptr) q->next = p->next;
                else head = p->next;
                delete p;
                return true;
            }
        }
        return false;
    }
};

// ---------------------------------

int main ()
{
    List<string> ls;
    ls.add("eins");
    ls.add("zwei");
    ls.add("drei");

    string s;
    if (ls.get(0, s)) cout << s << endl;
    else cout << "Element nicht vorhanden"<< endl;

    ls.remove("zwei");
};
```
