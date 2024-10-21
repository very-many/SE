## Aufgabe 1
**a)**
``` sh
88490@in-bs:~$ touch hallo
88490@in-bs:~$ vim hallo
```

**b)**
``` sh
88490@in-bs:~$ bash hallo
Guten Morgen!

88490@in-bs:~$ chmod 777 hallo
88490@in-bs:~$ ./hallo
Guten Morgen!
```

**c)**
``` sh
88490@in-bs:~$ vim hallo
88490@in-bs:~$ ./hallo 1 2 3
Guten Morgen!
Alle Argumente: 1 2 3
Anzahl der Argumente: 3
Inhalt des Shellskripts:
#!/bin/bash
echo Guten Morgen!
echo Alle Argumente: $@
echo Anzahl der Argumente: $#
echo Inhalt des Shellskripts:
cat $0
```

**d)**
``` sh
88490@in-bs:~$ touch laenge1.sh
88490@in-bs:~$ vim laenge1.sh
88490@in-bs:~$ bash laenge1.sh hallo
Die Anzahl Woerter in hallo ist
19
Code zum einsehen:
#!/bin/bash
myfile=$1
echo "Die Anzahl Woerter in" ${myfile} "ist"
cat ${myfile}| wc -w

echo "Code zum einsehen:"
cat $0
```

**e)**
```sh
# Erstelle Variablen 1, 2, 3, ..., 15
set $(seq 1 15) 
# Gib alle Variablen aus
echo $@ 
# Gib Variable Nummer 1 und 9 aus
echo $1 $9 
# Verschiebe alle variablen um 3
shift 3 
# Gib Variable Nummer 1 und 9 aus 
echo $1 $9

# Test durchlauf:
88490@in-bs:~$ touch testtest
88490@in-bs:~$ vim testtest
88490@in-bs:~$ bash testtest
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 9
4 12
```

**f)**
```sh
88490@in-bs:~$ touch Zähler
88490@in-bs:~$ vim Zähler

88490@in-bs:~$ bash Zähler
11
Inhalt des Shellskripts:
#!/bin/bash
Verzeichnis=$1
ls ${Verzeichnis:=~} | wc -l
echo: "Skript:"
cat $0

88490@in-bs:~$ bash Zähler abc
1
Inhalt des Shellskripts:
#!/bin/bash
Verzeichnis=$1
ls ${Verzeichnis:=~} | wc -l
echo: "Skript:"
cat $0
```

**g)**
```sh
88490@in-bs:~$ touch pack-script
88490@in-bs:~$ vim pack-script
88490@in-bs:~$ bash pack-script testtest
Erfolgreich gepackt: testtest.tar
Inhalt des Shellskripts:
#!/bin/bash
# Überprüfen, ob mindestens eine Datei als Argument übergeben wurde
if [ $# -eq 0 ]; then
  echo "Keine Dateien übergeben. Bitte geben Sie mindestens eine Datei an."
  exit 1
fi

# Für jede übergebene Datei
for file in "$@"; do
  # Überprüfen, ob die Datei existiert
  if [ -f "$file" ]; then
    # Packen der Datei in ein .tar-Archiv
    tar -cf "${file}.tar" "$file"
    echo "Erfolgreich gepackt: ${file}.tar"
  else
    echo "Datei nicht gefunden: $file"
  fi
done
```

**h)**
```sh
88490@in-bs:~$ touch satz.sh
88490@in-bs:~$ vim satz.sh
88490@in-bs:~$ chmod +x satz.sh

88490@in-bs:~$ bash satz.sh
Bitte geben Sie das erste Wort ein: 1
Bitte geben Sie das zweite Wort ein: 2
Bitte geben Sie das dritte Wort ein: 3
Der Satz lautet: 1 2 3.
Inhalt des Shellskripts:
#!/bin/bash

# Frage den Benutzer nach drei Wörtern
read -p "Bitte geben Sie das erste Wort ein: " wort1
read -p "Bitte geben Sie das zweite Wort ein: " wort2
read -p "Bitte geben Sie das dritte Wort ein: " wort3

# Ausgabe der Wörter in einem Satz
echo "Der Satz lautet: $wort1 $wort2 $wort3."

88490@in-bs:~$ touch auto-satz.sh
88490@in-bs:~$ vim auto-satz.sh
88490@in-bs:~$ chmod +x auto-satz.sh

88490@in-bs:~$ bash auto-satz.sh
Der Satz lautet: Hallo Welt !.
Inhalt des Shellskripts:
#!/bin/bash
./satz.sh <<EOF
Hallo
Welt
!
EOF
```

