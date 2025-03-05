---

---
In den Codeblöcken steht jeweils Heinleins Rückmeldung zu den Testaten. Darüber steht eine Bemerkung von mir, falls vorhanden.

**Falls sich das wer über Obsidian anschaut:** In dem eigentlichen Ordner sind auch noch meine zip Files für die Abgaben. 
(Feel free to look - Passt auf, wegen Plagiat und so - Namensgebung von ihm beachten)

**Mehr als die aufgelisteten hab ich nicht, aber feel free to send me if u got, then I include**

---
# Testat 0
- 100%
# Testat 1
```
Unzulässige Kontoüberziehung!  
Unzulässige Kontoüberziehung!  
Gewichtete Summe: 100 %
```

# Testat 2
```
print (1 Punkt): 6 von 6 Tests richtig (100 %)  
mirror (2 Punkte): 6 von 6 Tests richtig (100 %)  
rotate (3 Punkte): 81 von 81 Tests richtig (100 %)  
zip (4 Punkte): 36 von 36 Tests richtig (100 %)  
Gewichtete Summe: 100 %
```

# Testat 3
**Bemerkung dazu:**
Heinleins Testprogramm hat fett versagt weil es meine Überladung (bei `reverse`) nicht handeln kann (er meinte es fixt es, aber idk ob er es gemacht hat)

Meine Fehler (Die man noch korrigieren sollte):
- Bei `pascal` müssen die 0er entfernt werden, mit denen ich gefüllt hab
- Bei `isPalindrome` meinte er, dass `""` (also nichts) auch ein Palindrom ist und somit `true` zurückgegeben werden muss.
```
Fehler in Methode pascal:  
Aufruf:   (2)  
Ergebnis: (2) -> [[1, 0], [1, 1]]  
Aufruf:   (3)  
Ergebnis: (3) -> [[1, 0, 0], [1, 1, 0], [1, 2, 1]]  
Aufruf:   (4)  
Ergebnis: (4) -> [[1, 0, 0, 0], [1, 1, 0, 0], [1, 2, 1, 0], [1, 3, 3, 1]]  
Aufruf:   (5)  
Ergebnis: (5) -> [[1, 0, 0, 0, 0], [1, 1, 0, 0, 0], [1, 2, 1, 0, 0], [1, 3, 3, 1, 0], [1, 4, 6, 4, 1]]  
Fehler in Methode isPalindrome:  
Aufruf:   ("")  
Ergebnis: ("") -> false  
Fehler in Methode reverse:  
Aufruf:   ("")  
Ergebnis: java.lang.IllegalArgumentException: wrong number of arguments  
Aufruf:   ("X")  
Ergebnis: java.lang.IllegalArgumentException: wrong number of arguments  
Aufruf:   ("XX")  
Ergebnis: java.lang.IllegalArgumentException: wrong number of arguments  
Aufruf:   ("Xx")  
Ergebnis: java.lang.IllegalArgumentException: wrong number of arguments  
Aufruf:   ("XxX")  
Ergebnis: java.lang.IllegalArgumentException: wrong number of arguments  
Aufruf:   ("Xxx")  
Ergebnis: java.lang.IllegalArgumentException: wrong number of arguments  
Aufruf:   ("XxxX")  
Ergebnis: java.lang.IllegalArgumentException: wrong number of arguments  
Aufruf:   ("Xxxx")  
Ergebnis: java.lang.IllegalArgumentException: wrong number of arguments  
print (1 Punkt): 5 von 5 Tests richtig (100 %)  
pascal (3 Punkte): 1 von 5 Tests richtig (20 %)  
isPalindrome (2 Punkte): 7 von 8 Tests richtig (88 %)  
toLower (3 Punkte): 8 von 8 Tests richtig (100 %)  
reverse (1 Punkt): 0 von 8 Tests richtig (0 %)  
Gewichtete Summe: 64 %
```

# Testat 4
```
new Point (1 Punkt): 11 von 11 Tests richtig (100 %)  
getX/getY (1 Punkt): 20 von 20 Tests richtig (100 %)  
print (1 Punkt): 10 von 10 Tests richtig (100 %)  
move (1 Punkt): 10 von 10 Tests richtig (100 %)  
Effekt von move (1 Punkt): 20 von 20 Tests richtig (100 %)  
new Line (1 Punkt): 20 von 20 Tests richtig (100 %)  
getBegin/getEnd -> getX/getY (1 Punkt): 80 von 80 Tests richtig (100 %)  
length (1 Punkt): 20 von 20 Tests richtig (100 %)  
Gewichtete Summe: 100 %
```

# Testat 5
**Bemerkung:**
Weiß nicht mehr was ich hier falsch gemacht hab tbh. ist zu lang her, wills mir jz au nicht anschauen.
```
Fehler bei insert: Resultatwert falsch  
Fehler bei card: Resultatwert falsch  
Fehler bei print: Ausgabe falsch  
Fehler bei card: Resultatwert falsch  
Fehler bei print: Ausgabe falsch  
Fehler bei card: Resultatwert falsch  
Fehler bei print: Ausgabe falsch  
Fehler bei card: Resultatwert falsch  
Fehler bei print: Ausgabe falsch  
Fehler bei card: Resultatwert falsch  
Fehler bei print: Ausgabe falsch  
Fehler bei insert: Resultatwert falsch  
Fehler bei print: Ausgabe falsch  
new StringSet (1 Punkt): 35 von 35 Tests richtig (100 %)  
capacity (1 Punkt): 3 von 3 Tests richtig (100 %)  
insert (2 Punkte): 115 von 117 Tests richtig (98 %)  
card (1 Punkt): 46 von 51 Tests richtig (90 %)  
print (1 Punkt): 37 von 51 Tests richtig (73 %)  
remove (1 Punkt): 9 von 9 Tests richtig (100 %)  
insert null (2 Punkte): 3 von 3 Tests richtig (100 %)  
contains (1 Punkt): 12 von 12 Tests richtig (100 %)  
contains null (2 Punkte): 3 von 3 Tests richtig (100 %)  
remove null (2 Punkte): 3 von 3 Tests richtig (100 %)  
intersection (1 Punkt): 16 von 16 Tests richtig (100 %)  
intersection -> contains (2 Punkte): 64 von 64 Tests richtig (100 %)  
Gewichtete Summe: 98 %
```

# Testat 6
**Bemerkung:**
Weiß nicht mehr was ich hier falsch gemacht hab tbh. ist zu lang her, wills mir jz au nicht anschauen.
```
Fehler bei add: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei add: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei count: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei add: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei count: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei add: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei count: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei toString: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
Fehler bei equals: Resultatwert falsch  
Fehler bei count: Resultatwert falsch  
Fehler bei hashCode: Resultatwert falsch  
new MultiSet (1 Punkt): 6 von 6 Tests richtig (100 %)  
add (2 Punkte): 32 von 36 Tests richtig (89 %)  
toString (2 Punkte): 22 von 48 Tests richtig (46 %)  
hashCode (1 Punkt): 22 von 49 Tests richtig (45 %)  
count (1 Punkt): 18 von 27 Tests richtig (67 %)  
equals (3 Punkte): 88 von 108 Tests richtig (81 %)  
equals bei gleichem toString (1 Punkt): 1 von 1 Tests richtig (100 %)  
Gewichtete Summe: 75 %
```

# Testat 7
**Bemerkung:**
Weiß nicht mehr was ich hier falsch gemacht hab tbh. ist zu lang her, wills mir jz au nicht anschauen.
```
Bei Bin.equals fehlt der Vergleich der Operatorsymbole.  
Gewichtete Summe: 95 %
```