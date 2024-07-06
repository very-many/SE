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

## Generelles Quiz
Was deckt die IT-Security ab?
-  Schutz von Daten vor Zerstörung, Abhören, Manipulation, etc.

Was umfasst Safety im IT Kontext?
- Die Sicherheit der Verfügbarkeit vin Daten und IT bezogen auf Hardware

Auf welches Recht geht der Datenschutz zurück?
- Auf das informelle "Schutz des Rechts auf informationelle Selbstbestimmung".

Nenne die 5 Säulen der IT-Sicherheit (vollziehe diese im Kopf nach)
- **Vertraulichkeit (Confidentiality)**
	- Daten bleiben geheim, auch wenn eine nicht autorisierte Person darauf zugreifen kann.
- **Integrität (Integrity)**
	- Daten können nicht unbemerkt manipuliert werden.
- **Verfügbarkeit (Availability)**
	- Daten sind immer dann verfügbar, wenn sie benötigt werden
- **Nicht-/Abstreitbarkeit (Non-/ Repudiation)**
	- Es kann entweder nicht oder sicher festgestellt werden, um wessen Daten es sich handelt.
- **Authentizität (Authenticity)**
	- Daten wurden wirklich vom angegebenen Urheber erstellt und nicht von jemand anderem.

Erkläre die **CIA** Triade
- *Confidentiality, Integrity und Availability*
- Alle drei stehen in einem stetigen Spannungsverhältnis zueinander, d.h. sie können nicht alle gleichzeitig, vollständig erreicht werden.

Nenne eine kryptografische Maßnahme für jedes der Schutzziele der IT-Sicherheit. Welches der Schutzziele kann nicht (direkt) durch kryptografische Maßnahmen erfüllt werden?
- Vertraulichkeit: Verschlüsselung
- Integrität: Hash, MAC, Digitale Signatur
- Verfügbarkeit: X
- Nicht-/Abstreitbarkeit: Digitale Signatur
- Authentizität: MAC, Digitale Signatur

Was versteht man unter Open Source Intelligence?
- Sammeln von Informationen über Unternehmen und Personen durch (halb-)offene Informationsquellen wie Websites, unsichere APIs, etc.

Was versteht man unter Ransomware?
- Ransomware ist Malware, welche Daten (exfiltriert und) verschlüsselt.
- Die Daten "sollen nach einer Zahlung wieder entschlüsselt werden".

Angenommen das Unternehmen für das sie Arbeiten wird Ziel einer Ransomware Attacke.
- Nein

Wofür steht DDOS? Was ist DOS?
- Distributed Denial of Service ist ein Angriff der nicht wie ein Denial of Service von einer Partei, sondern von mehreren (verteilt) ausgeht. Das Ziel ist es, die Verfügbarkeit eines Dienstes, oder von Daten zu schädigen.

Was ist Phishing?
- Der Prozess, ein Opfer unter Vortäuschung falscher Umstände zu einer Tat zu bewegen.

Was sind die OWASP Top Ten? In welchen Bereichen sind diese relevant?
- Die 10 häufigsten Schwachstellen in Web- oder Mobilanwendungen (je nach Liste).

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

Erkläre die Begriffe pre-image Resistance, Second pre-image resistance und Kollisionsresistenz.
- pre-image Resistance:
	- Es muss schwierig sein, eine Nachricht zu finden, die einen bestimmten Hash h ergibt.
- Second pre-image resistance:
	- Es muss schwierig sein, eine Nachricht zu finden, die denselben Hash ergibt wie eine Nachicht m.
- Kollisionsresistenz:
	- Es muss schwierig sein zwei Nachrichten zu finden, die denselben Hash ergeben.

Welches der Schutzziele gewährleistet der richtige Einsatz eines Hashes?
- Integrität

Welche Anwendungsfälle gibt es für Hashes?
- Verifizierung der Integrität von Daten
- Digitale Signaturen
- Passwort Verifikation

Was unterscheidet einen MAC von einem Hash?
- Ein MAC kann zur Authentisierung einer Nachricht verwendet werden. Dafür wird ein geteiltes Geheimnis genutzt.
- Er ermöglicht genau wie ein Hash die Überprüfung der Integrität einer Nachricht.

Welcher Modus ist für MACs einzusetzen?
- encrypt-**then**-mac

Wie sollten Passwörter in Datenbanken gespeichert werden?
- Es sollte ein Passwort Hash gespeichert werden, um die Vertraulichkeit des Passworts zu gewährleisten.
- Um vor Rainbow Tables zu schützen, sollte ein Salt für die Erzeugung des Hashes genutzt werden.
- Es sollte ein langsames Hashing Verfahren genutzt werden, welches mehrere Runden durchläuft. Die Anzahl der Runden muss ebenfalls gespeichert werden.
- Für besonders schützenswerte Ziele kann ein Pepper genutzt werden, welcher an einer anderen Stelle gespeichert wird (nicht zwingend erforderlich).

- **Hashing and salting** (ypselon.com)

Welche Algorithmen werden für das Hashing von Passwörtern empfohlen?
- Argon2id
- bcrypt
- PBKDF2

Erkläre hybride Angriffe auf Passwörter
- Hybride Passwortangriffe setzen sich aus Brute Force und Dictionary Angriffen zusammen.
	- Brute Force (rohe Gewalt) iteriert über mögliche Zeichenkombinationen (oft ohne Regeln).
	- Dictionary Attacks nutzen Wörterlisten, um Passwörter zu erraten.
- Hybride Angriffe vereinen beide Verfahren (listenbasierte und regelbasierte Ansätze).

## Signaturen Quiz
Welche Schutzziele soll eine digitale Signatur gewährleisten?
- Autenzität
- Integrität
- Nicht-/Abstreitbarkeit

Wie verläuft der Prozess der Erstellung und Prüfung einer digitalen Signatur?
1. Alice erstellt ein Schlüsselpaar und verteilt den öffentlichen schlüssel
2. Alice hast einen Ciphertext (oder sonstige Daten)
3. Alice verschlüsselt den Hash mit ihrem private Key
4. Alive versendet die Daten mitsamt Signatur
5. Bob entschlüsselt den Hash mit Alice public Key
6. Bob hasht die Daten und prüft den Hash

Welchen Zweck erfüllt ein Zeitstempel bei der Übertragung von Daten? Wie wird er eingesetzt?
- Ein Zeitstempel schützt vor Replay-Attacks.
- Der Timestamp wird an die Nachricht angehängt. Das Paket wird gehashed, signiert und verschlüsselt. Pakete mit wiederverwendeten Zeitstempeln werden verworfen.

## TLS Quiz
Welche Schutzziele können über TLS durchgesetzt werden?
- Vertraulichkeit
- Integrität
- Authenzität

Was ist SSL?
- TLS<1.0

Wofür steht TLS und SSL
- Transport Layer Security
- Secure Socket Layer

Was wird im TLS Handshake durchgeführt?
1. Cipher Suit (Schlüsselaustausch, Verschlüsselungsverfahren, Hashfunktion)
2. Zertifikat (Autentizität)
3. Generierung eines symmetrischen Schlüssels und DH-Keyexchange (Vertraulichkeit)
4. MAC über bisherige Kommunikation

Was ist Perfect Forward Secrecy? Wie wird sie gewährleistet?
- Die Garantie, dass wenn ein Schlüssel einer Verbindung öffentlich wird, die Vertraulichkeit weiterer Kommunikation nicht gefährdet ist.
- Durch ephemeral (flüchtig) Verfahren sind Schlüssel nur für einen Zeitraum gültig. Seit TLS1.3 ist nur noch ephemeral möglich.

Was ist eine Public-Key-Infrastructure?
- Eine PKI soll die Überprüfung von Identitäten im Internet ermöglichen. Dafür wird eine baumförmige Chain of Trust gebildet, in welcher von einer Stelle ultimativen Vertrauens (Root-Certificate Authority) ausgehend nacheinander Zertifikate signiert werden, um Vertrauen in Identitäten zuzusprechen.

Was sind Extended Validation Zertifikate?
- Extended Validation Zertifikate sind Zertifikate, welche höherer Sicherheitsanforderung bieten. Sie erfordern z.B. Identitätsnachweis und Adresse des Antragstellers und einen Nachweis, dass der Antragsteller Alleiniger eigentümer der Domain ist.

Was kann Kryptographie nicht abwenden?
- Lesen unverschlüsselter Dokumente
- Diebstahl von Schlüsselmaterial
- Datenverlust
- Unehrliche Empfänger, der geheime Informationen weitergibt
- Modifizierte Verschlüsselungssoftware, die unbeabsichtigt Schlüssel oder Klartext weitergibt

Was sind DDOS, Spoofing, PITM/MITM, Hijacking?
- DDOS = Distributed Denial of Service. Ein DDOS ist das Überlasten eines Diensteanbieters durch Zugriffe von verschiedenen Quellen.

- Spoofing ist das Vortäuschen einer Identität, um z. B: Zugriff zu erlangen. Das ist oft eine erste Stufe für weitere Angriffe wie PITM.

- PITM/MITM = Person/Man in the Middle. Hier wird eine Kommunikation über eine/n dritte/n geleitet, um diese im Transit mitzulesen und/oder zu verändern.

- Beim Hijacking wird zusätzlich zum PITM die Identität des Gegenübers eingenommen, wobei dieses Vorher ausgeschaltet worden ist. Es werden also alle drei obigen Angriffe vereint.

## Availability Quiz
Wie wird die Availability berechnet?
- $Availability = \frac{Uptime}{Uptime+Downtime}$

Was sind MTTF, MTBF, MTTR?
- MTTF (mean time to failure)
- MTBF (mean time between failures)
- MTTR (mean time to repair)

Was ist die inhärente Verfügbarkeit?
- $A_{i}= \frac{MTBF}{MTBF+MTTR}$
- Die Wahrscheinlichkeit dass ein System zu einem bestimmten Zeitpunkt unter idealen Supportbedingungen funktioniert.

Erkläre die Badewannenkurve
- Viele Fehler (Produktionsfehler) -> Länger kaum Fehler -> nach zu erwartenden Lebenszeit viele Fehler (Hardwareversagen)
- Entgegenwirken:
	- Erste Ausfälle provozieren (burn-in) 
	- Redundante Systeme und Backups
	- Hardware ausfälle durch proactive Maintenance reduzieren

Erkläre RAIDs
- Redundant Array of independent disks
	- Erhöht Verfügbarkeit, Leistung und das wiederherstellen von Daten

Erkläre RAID0
- Datenblöcke werden abwechselnd auf die Platten geschrieben.
- Vorteile
	- n Festplatten = n-mal Speicherplatz
	- n-mal mehr Leistung
- Nachteile
	- Fällt eine aus, sind alle Daten unbrauchbar (1n Verfügbarkeit)

Erkläre RAID1
- Datenblöcke werden gleichzeitig auf die Platten geschrieben.
- Vorteile
	- Doppelte Lesegeschwindigkeit
	- Doppelte Verfügbarkeit
- Nachteile
	- Doppelter Speicherplatz erforderlich
	- Keine Erhöhung der Schreibgeschwindigkeit

Erkläre RAID2-4
- Datenblöcke werden gleichzeitig auf die Platten geschrieben.
- Vorteile
	- Doppelte Lesegeschwindigkeit
	- mehr als doppelte Verfügbarkeit (dank Prüfsummen)
- Nachteile
	- Dritte Festplatte erhöht nicht die Speicherkapazität

Erkläre RAID5
- Wie Level 4, jedoch werden die Prüfsummen auf die Festplatten verteilt.
- Vorteile
	- Dreifache Lese- und Schreibgeschwindigkeit
	- mehr als doppelte Verfügbarkeit (dank Prüfsummen)
	- Nur eine zusätzliche Festplatte erforderlich
- Nachteile
	- Keine Rekonstruktion Möglich wenn 2 Festplatten gleichzeitig ausfallen

Erkläre RAID6
- Es werden zwei unabhängige Prüfsummen berechnet.
- Vorteile
	- Rekonstruktion möglich, auch wenn 2 Festplatten gleichzeitig ausfallen
	- 4-Fache Lesegeschwindigkeit
- Nachteile
	- Doppelter Speicherplatz erforderlich und nur 2-fache Schreibleistung

## Internetsicherheit Quiz
Welche Maßnahmen gibt es, um bestimmte Schutzziele zu erfüllen?
-  Vertraulichkeit (Confidentiality)
	- Verschlüsselung von Daten
	- Verwendung von AE (Authenticated Encryption)
- Integrität (Integrity)
	- Verwendung von AE (Authenticated Encryption)
- Verfügbarkeit (Availability)
	- Kein Versand Zeitkritischer Informationen
- Authentizität (Authenticity)
	- Verwendung digitaler Signaturen

Welche Arten von Malware nach Zweck sind ihnen bekannt?
- Spyware
	- Ausspionieren von Daten
- Adware
	- Blendet unerwünschte Werbung ein
- Scareware
	- Verängstigung/Einschüchterung von Usern
- Ransomware
	- Verschlüsselt Daten und erpresst Lösegeld für Schlüssel

## Überwachung Quiz
Erklären Sie, inwiefern Unternehmen an (staatlicher) Überwachung beteiligt sind.
- Können verpflichtet werden Daten preis zu geben
- Können verpflichtet werden Spyware einzubauen
- Infrastruktur von Unternehmen kann abgehört werden

Nennen Sie zwei Geheimdienste aus verschiedenen Ländern.
- USA - CIA (Central Intelligence Agency)
- Deutschland - BND (Bundesnachrichtendienst)

Nennen sie drei Gründe für den Erhalt der Privatsphäre / des Datenschutzes
1. Gespeicherte Daten können durchsickern und so das Leben von unschuldigen Personen beeinträchtigen oder gefährden.
2. Jemand der etwas versteckt, muss nichts falsches getan haben. Das Nothing-To-Hide Argument impliziert aber: Wer etwas verheimlicht, hat etwas falsch gemacht. Dadurch werden auch Menschen mit gesetzlich legitimen Geheimnissen in einen Topf mit Kriminellen geworfen.
3. Etwas das heute gesellschaftlich akzeptiert ist, könnte schon morgen illegal sein.
4. Geheimnisse sind wichtig für die Identitätsfindung. Um den unterschiedlichen Rollen des Alltags gerecht zu werden, muss jeder selbst entscheiden können, wer was über ihn erfährt.
5. Wird die Privatsphäre in legaler Weise eingeschränkt, kann diese Rechtsgrundlage später unter anderen Umständen ausgenutzt werden.

Welches Problem könnte durch das Geheimhalten von Schwachstellen durch z. B. einen Staat auftreten?
- Ein Szenario wie WannaCry: Durch das Geheimhalten der Schwachstelle wurden weltweit Geräte infiziert und somit der Betrieb von Verkehr, Krankenhäusern, Regierungseinrichrungen, etc temporär blockiert.

Welche Schutzmaßnahmen fallen ihnen ein, um sich vor Überwachung zu schützen?
- Sorgfältige Auswahl von Anbietern
- Verschlüsselung von Daten und Mails
- Vorsicht vor Metadaten
- Anonymisierung
- Geräte verantwortungsvoll einsetzen