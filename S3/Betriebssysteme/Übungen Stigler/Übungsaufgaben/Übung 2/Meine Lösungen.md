## Aufgabe 1
a) (unsicher ob alle oder nur ~/Uebungen mit chmod)
``` sh
88490@in-bs:~$ mkdir -p Uebungen/Uebung2/Programme
88490@in-bs:~$ chmod 700 Uebungen/Uebung2/Programme
```
b)
``` sh
88490@in-bs:~$ ln -s /usr/bin bin
```
c)
``` sh
88490@in-bs:~$ find bin/ -name "l*" -exec cp {} ~/Uebungen/Uebung2/Programme \;
88490@in-bs:~$ find bin/ -name "z*" -exec cp {} ~/Uebungen/Uebung2/Programme \;

88490@in-bs:~$ ls Uebungen/Uebung2/Programme/ | wc -l

88490@in-bs:~$ find bin/ -executable -name "l*" -exec cp {} ~/Uebungen/Uebung2/Programme \;
88490@in-bs:~$ find bin/ -executable -name "z*" -exec cp {} ~/Uebungen/Uebung2/Programme \;
```
d)
``` sh
88490@in-bs:~$ ls Uebungen/Uebung2/Programme/ >> Uebungen/Uebung2/index.txt
88490@in-bs:~$ ls bin >> Uebungen/Uebung2/index2.txt
```
e)
``` sh
88490@in-bs:~$ cat Uebungen/Uebung2/index2.txt >> Uebungen/Uebung2/index.txt
88490@in-bs:~$ sort Uebungen/Uebung2/index.txt | uniq >> index.sortiert.txt
```
f)
``` sh
88490@in-bs:~$ grep "ch" Uebungen/Uebung2/index2.txt
```

## Aufgabe 2
a)
``` sh
88490@in-bs:~$ umask 000
```
b)
``` sh
88490@in-bs:~$ mkdir abc
88490@in-bs:~$ touch abc/x

88490@in-bs:~$ ln -s abc/x sym
88490@in-bs:~$ ln abc/x hard

```
c)
``` sh
88490@in-bs:~$ chmod +t abc/
```
d)
``` sh
88490@in-bs:~$ chmod 700 hard

# Vorher
-rw-rw-rw-
# Nachher
-rwx------
```
e)
``` sh
88490@in-bs:~$ echo "hello world" >> abc/x
88490@in-bs:~$ rm abc/x

88490@in-bs:~$ cat hard
hello world

88490@in-bs:~$ cat soft
cat: soft: Datei oder Verzeichnis nicht gefunden
```
