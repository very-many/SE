## %%07.10%%
```C++
#include <iostream>
#include <string>

using namespace std;
int main () {
    cout << "Bitte einene Wert x eingeben: ";
    int x;
    cin >> x;
    cout << "der Wert lautet"
}
```

``` C++
#include <iostream>
#include <string>

using namespace std;
int main () {
    string s;
    while (getline(cin, s)) {
        cout << "Eingegebene Zeichenkette: " << s << endl;
    }

    cout << "Programmende" << endl;
}
```

# Old vs New
## Pointer wie in C
```C++
#include <iostream>
#include <string>

using namespace std;
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    cout << a << " " << b << endl;

}

int main () {
    int a = 1, b = 2;

    cout << a << " " << b << endl;

    //Swap mit Funktion
    swap(&a, &b);

    cout << a << " " << b << endl;
}
```

## Referenzen
``` C++
#include <iostream>
#include <string>

using namespace std;
//Hier die Referenz
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
    cout << a << " " << b << endl;

}

int main () {
    int a = 1, b = 2;

    cout << a << " " << b << endl;

    //Swap mit Funktion
    swap(a, b);

    cout << a << " " << b << endl;
}
```

```C++
//C (geht au in C++)
typedef int* IntPtr;
typedef unsigned long int ulong;

//C++ (Benutzt man üblich)
using IntPtr = int*;
using ulong = unsigned long int;
```
