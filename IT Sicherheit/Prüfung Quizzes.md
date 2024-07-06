## (Unix) Shell Quiz
 Mit welchem Befehl wird das Verzeichnis zu /home gewechselt?
- cd /home

Mit welchem Befehl wird die aktuelle Position angezeigt?
- pwd

Mit welchem Befehl wird das Verzeichnis von /home angezeigt?
- ls /home

Wie könnte eine Datei wohl bearbeitet werden?
- vim/nano/...

Wie könnte wohl eine Datei namens ~/.bashrc inspiziert werden, ohne diese zu öffnen? (Metadaten)
- file ~/.bashrc
- ls -l ~/.bashrc
- du ~/.bashrc

Wie kann eine Datei namens /var/log/boot.log ausgegeben werden?
- cat /var/log/boot.log

Wie kann der Output des Befehls "pwd" an die Datei "ls.log" angehängt werden?
- pwd >> ls.log
- pwd | tee -a ls.log

Wie kann der Wert "Lorem Ipsum" in der Variable "thesis" gespeichert und abgerufen werden?
1. thesis="lorem ipsum"
2. echo $thesis

Wie könnte der Output des Programms "ls" in die Datei "ls.log" umgeleitet werden?
- ls > ls.log
- ls 1> ls.log



## Symmetrische Verschlüsselung Quiz
Womit Befasst sich Steganographie?
- Mit dem verstecken von Informationen - kann durch Kryptographie ergänzt werden

Womit befasst sich die Kryptographie?
- Techniken zur sicheren Kommunikation in einem Unsicherem Umfeld, d.h. die Erzeugung von Chiffren

Wie ist ein Kryptosystem Definiert?
- Ein Kryptosystem ist ein Tupel (P, C, K, enc, dec) mit folgenden Eigenschaften:
	- P (Plain Text Space): Die Menge der Klartexte
	- C (Cipher Text Space): Die Menge der Geheimtexte
	- K (Key Space): Die Menge der Schlüssel
	- enc (Encryption): $P x K \rightarrow C$: Eine Verschlüsselungsfunktion
	- dec (Decryption): $C x K \rightarrow P$: Eine Entschlüsselungsfunktion

Lassen sich alle Schutzziele durch kryptographische Methoden gewähren?
- Nein

Welche Typen von Kryptosystemen (symmetrisch) können unterschieden werden? Erkläre die beiden behandelten Formen.
- Blockchiffren und Stromchiffren
	- Blockchiffren: Ein Klartext $x \in P$ wird in Blöcke fester Länge zerlegt, welche alle mit demselben $ke \in K$ verschlüsselt werden.
	- Stromchiffren: Der bereits verschlüsselte Klartext beeinflusst den Schlüssel, mit dem die darauffolgenden Blöcke verschlüsselt werden.

Nenne und erkläre zwei Operationen, die auf Block- und Stromchiffren durchgeführt werden können.
1. Substitution: Ersetzen des Klartexts durch einen Geheimtext.
	- polyalphabetisch: Die Verschlüsselung eines Symbols ist abhängig von dessen Position im Klartext
	- monoalphabetisch: Klartextsymbol wird, unabhängig von dessen Position, immer zum selben Geheimsymbol verschlüsselt.
2. Transposition: Vertauschung der Reihenfolge des Klartextes

Erkläre die allgemeine Verschiebe-Chiffre und wieso diese nicht Sicher ist (2 Gründe).
- Die Verschiebe-Chiffre ist definiert als:
	- $P = C = K = \{a, b, c, ..., z\}$
	- $enc(k, x) = x + k \mod 26, x \in P, k\in K$
	- $dec(k, x) = y - k \mod 26, y \in C, k\in K$
1. Die Verschiebe-Chiffre ist monoalphabetisch. Dies macht eine statistische Analyse des Geheimtextes möglich.
2. Der Geheimtext kann durch einen Brute-Force-Angriff mit Leichtigkeit gebrochen werden, da es nur 25 mögliche Schlüssel gibt.

Erkläre die allgemeine Affine Chiffre und wieso diese nicht sicher ist.
- Die Affine Chiffre ist definiert als :
	- $P=C=\{a,b,c, ...,z\}$
	- $k = \{(a,b)\in Z26 x Z26 \mid gcd(a,26) = 1\}$
	- $enc((a,b),x) = (ax + b) \mod 26, x\in P, (a,b)\in K$
	- $dec((a,b),y) = (a-1(y-1)) \mod 26, y\in C, (a,b)\in K$
- Auch hier kann eine Häufigkeitsanalyse durchgeführt werden, wobei zwei Elemente betrachtet und durch gleichsetzen der Verschlüsselungsfunktion zu einem Schlüsseltupel kombiniert werden.

Erkläre Kerckhoffs Prinzip und Security by Obscurity
- Kerckhoffs Prinzip: Der Kryptoanalytiker kennt das Kryptosystem das zur Chiffrierung des Klartextes verwendet wurde. Das einzige Geheimnis ist der verwendete Schlüssel.
- Security by Obscurity: Das verwendete Verfahren wird geheimgehalten. Das Bekanntwerden des Verfahrens gefährdet die Sicherheit aller, die dieses verwenden.

Random Fragen:
- Pseudo-random number generators (PRNGs) sind deterministisch.
- Die meisten PRNGs gängiger Programmiersprachen sind unsicher.

Welche Anforderungen gelten an PRNGs, wenn diese kryptographisch sicher sein sollen?
1. Unter Kenntnis der ersten k Bit eines PRNG Outputs ist es nicht möglich, unter Verwendung eines Polynomialzeitalgorithmus, das nächste Bit mit einer W'Keit signifikant größer als 50% vorherzusagen.
2. Sollte der Zustand des PRNG bekannt werden, so soll es nicht möglich sein die bis dahin generierte Folge an Zufallsbits zurückzurechnen.

Wie sind Stromchiffren definiert? Erkläre die Funktionsweise
- Eine Stromchiffre ist ein Tupel(P, C, K, L, F, enc, dec) mit folgenden Eigenschaften:
	- P (Plain Text Space): Die Menge der Klartexte
	- C (Cipher Text Space): Die Menge der Geheimtexte
	- K (Key Space): Die Menge der Schlüssel
	- L: Schlüsselstromalphabet
	- F: $K x Pi-1 \rightarrow L$: Schlüsselstromgenerator 
	- enc (Encryption): $P x L \rightarrow C$: Eine Verschlüsselungsfunktion
	- dec (Decryption): $C x L \rightarrow P$: Eine Entschlüsselungsfunktion
- Stromchiffren verschlüsseln einen Strom beliebiger Länge, wobei diese in Blöcke zerteilt wird und mit einem Teilschlüssel kodiert wird. Für den Schlüsselstrom wird initial ein PRNG genutzt, später evtl. der Klartext.

Erkläre die Begriffe Asynchron, Synchron und Periode im Kontext der Stromchiffren.
- Synchron: Der Erzeugte Schlüsselstrom ist unabhängig vom zu verschlüsselnden Klartext.
- Asynchron: Der Erzeugte Schlüsselstrom ist abhängig vom zu verschlüsselnden Klartext.
- Periode: Es existiert eine Konstante $d$, sodass $zi+d\cdot m=zi, m\geq 0$

Was für eine Art von Chiffre ist DES?
- DES ist eine Blockchiffre

Ist DES sicher und wenn nein, wieso nicht?
- DES ist aufgrund der Schlüssellänge (64 Bit) nicht mehr sicher, wenn auch der Algorithmus nicht gebrochen wurde.

Was ist ein besonderer Vorteil von DES?
- DES ist besonders gut in Hardware implementierbar.

Ist AES sicher?
- AES gilt bis heute als sicher

Von welcher Organisation wurde AES in einem Wettbewerb akzeptiert?
- Rijandel (der Advanced Encryption Standard) war der gewinner eines Wettbewerbs des National Institutes of Standards and Technology.

## Asymmetrische Verschlüsselung Quiz
Wie werden assymetrische Kryptosysteme genutzt?
- Zur Ver-/Entschlüsselung wird ein Schlüsselpar verwendet:
	- Private Key: Wird vom Besitzer Geheimgehalten
	- Public Key: Wird öffentlich gemacht
- Eine Nachricht die mit dem Public Key verschlüsselt wurde kann nur mit dem Private Key wieder entschlüsselt werden und umgekehrt.

Welche Eigenschaft muss ein Kryptosystem erfüllen, um asymmetrisch zu sein? Worauf Basiert die Sicherheit bei dem Verfahren?
1. Ein Kryptosystem ist asymetrisch, wenn aus $k_{e}\in K$ (öffentlicher Schlüssel) nur mit hohem Aufwand $k_{d}\in K$ (privater Schlüssel) berechnet werden kann, wobei $K$ den schlüsselraum des Kryptosystems darstellt. 
2. Die Sicherheit von Public Key Kryptosystemen hängt von mathematischen Problemen ab.

Was ermöglicht das Diffe-Hellmann Verfahren?
- Den sicheren Austausch von Schlüsseln (oder Zahlen allgemein) über einen unsicheren Kanal

Erkläre das Diffe-Hellmann Verfahren
1. Wählen einer großen Primzahl $p$ und einen Generator $g\in Z\cdot p$
2. Alice: Wähle eine zufällige Zahl $a\in Z\cdot p$ berechne $A=g^{a}\mod p$ und schicke A an Bob.
3. Bob: Wähle eine zufällige Zahl $b\in Z\cdot p$ berechne $B=g^{b}\mod p$ und schicke B an Alice.
4. Der Schlüssel ist nun: $B^{a}\mod p = k = A^{b}\mod p$

Was ist eine Public Key Infrastruktur (PIK)?
- Eine PIK ist die Summe an Hardware, Software, Personen, etc. die benötigt wird um digitale Zertifikate
	1. aufzustellen
	2. zu managen
	3. zu verteilen
	4. und zu widerrufen.

Was ist ein digitales Zertifikat?
- Digitale nachweise einer Identität auf Basis von öffentlichen Schlüsseln. Diese werden von einer oder mehreren anderen vertrauenswürdigen Parteien Signiert.

Was ist eina Web of Trust?
- Ein Netz nicht hierarchischer, bzw. nicht in Reihe aufeinander vertrauter Zertifikate. Ein Web of Trust wird z.B. bei PGP (Pretty Good Privacy) bzw. GPG (GNU Privacy Guard, ein FOSS PGP) eingesetzt.

Was ist RSA?
- RSA ist das erste Formal definierte Kryptosystem. Es wird bis heute eingesetzt. RSA basiert auf dem Faktorisierungsproblem.

Wie ist RSA definiert?
- Seien $p$ und $q$ zwei große Primzahlen, wobei $p \neq q$
- Sei $N = p\cdot q$
- $P = C = Zn$
- $K=\{(n,p,q,e,d)\mid ed \equiv 1 (\mod \phi(n))\}$
- Wähle $1<e<\phi(n)$, mit $gcd(3,\phi(n))=1$
	- $\phi(n)=(p-1)(q-1)$
	- $kpub=(n,e)$
	- $kpr=(p,q,d)$
- $enc((n,e),x)=xe(\mod n)$
- $dec((p,q,d),y)=yd(\mod n)$

Was sind Hybride Kryptosysteme und wie Funktionieren diese?
1. Hybride Kryptosysteme vereinen die Vorteile symmetrischer (Geschwindigkeit) und asymmetrischer (sicherer Schlüsselaustausch) miteinander.
2. 
	- Alice möchte eine Geheime Nachricht an Bob senden, dafür holt sie sich Bobs öffentlichen Schlüssel
	- Alice generiert einen zufälligen Session Key zur symmetrischen Verschlüsselung
	- Alice verschlüsselt die zu sendende Nachricht mit dem Session Key und den Session Key selber mit dem öffentlichen Schlüssel von Bob.
	- Beides sendet sie an Bob, der den Session Key mithilfe des privaten Schlüssels entschlüsseln kann
	- Damit kann er auch die geheime Nachricht entschlüsseln.

## Hashing Quiz
Welche Eigenschafen weißen kryptographische Hash Funktionen auf?
- Deterministisch
- Einwegsfunktion
- Kollisionsresistent

