# Prüfung wie sie dran kam
Nenne 5 Hauptsäulen der ITS und erkläre diese kurz
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

Ist die Sicherheit von den 5/3 gewährleistet? (Keine Ahnung was das heißen soll)
- 3 von 5 Säulen reichen nicht aus um Sicherheit zu gewährleisten. Es bleiben trotzdem erhebliche Sicherheitslücken offen.

Nenne 2 Beispiele zu kryptographischen Methoden 
- Symmetrisch: AES
- Asymmetrisch: RSA

Wie ist ein Kryptosystem Definiert?
- **P**: *Plaintext*
- **C**: *Ciphertext*
- **K**: *Keyspace*
- **enc**: *Verschlüsselungsalgo*
- **dec**: *Entschlüsselungsalgo*

Unterschied zwischen asymmtrischer und symmetrischer Verschlüsselung
- **Schlüssel**: Symmetrische Verschlüsselung verwendet einen einzigen Schlüssel für beide Prozesse, während asymmetrische Verschlüsselung ein Schlüsselpaar (öffentlich und privat) verwendet.
- **Sicherheit der Schlüsselverteilung**: Asymmetrische Verschlüsselung bietet eine sicherere und praktischere Methode zur Schlüsselverteilung, da der öffentliche Schlüssel offen verteilt werden kann.
- **Leistung**: Symmetrische Verschlüsselung ist schneller und effizienter, weshalb sie oft für die Verschlüsselung großer Datenmengen verwendet wird.

Erkläre Kerckhoffs Prinzip und Security by Obscurity
- Kerckhoffs Prinzip: Der Kryptoanalytiker kennt das Kryptosystem das zur Chiffrierung des Klartextes verwendet wurde. Das einzige Geheimnis ist der verwendete Schlüssel.
- Security by Obscurity: Das verwendete Verfahren wird geheimgehalten. Das Bekanntwerden des Verfahrens gefährdet die Sicherheit aller, die dieses verwenden.

Welches Mathe Problem gibts public key kryptographie. (?)
- Faktorisierungsproblem (RSA)
- Diskreter Logarithmus (Diffe-Hellmann, DSA, ECC)

Nenne 2 algorithmischen Schlüssel Tausch Methoden und skizziere 1 davon. 

Ist der Befehl rand() sicher? 
Wenn nein dann nenne Alternative. 
- rand() ist deterministisch und unsicher (wie fast alle PRNGs der Programmiersprachen)
- Stromchiffren?!

Hashing, was ist eine hash Funktion und nenne 3 Eigenschaften davon. 
- Eine hash Funktion transformiert ihre Eingabe in einen „Hash“ fester länge.
	- Deterministisch
	- Einwegsfunktion
	- Kollisionsresistent

Was ist Kollisionsresistenz?
- Es ist sehr schwer 2 Nachrichten zu finden, die den selben Hash aufweisen

Nenne 2 Anwendungsbereiche für hash Funktion. 
- Prüfsummen
- Passwort sicherung

Was für eine Grundidee steckt hinter MAC und wofür?
- Sender und Empfänger haben gemeinsamen Schlüssel.
- Nachricht wird so signiert, dass Empfänger sie validieren kann.

Skizziere encrypt then mac.
- Alice Verschlüsselt ihre Nachricht mit einem Schlüssel
- Alice erstellt den MAC mit einem anderen Schlüssel
- Sendet verschlüsselte Nachricht und MAC an Bob
- Bob errechnet mit einem Schlüssel selbst den MAC
- Wenn die MAC's übereinstimmen ist die Nachricht richtig
- Bob kann also auch noch die Nachricht entschlüsseln mit den Schlüssel

- Absender:
- M ----> (Verschlüsselung mit K_enc) ----> C
C ----> (MAC-Berechnung mit K_mac) ----> T
Send (C, T) ----> Empfänger

Empfänger:
Receive (C, T)
C ----> [MAC-Berechnung mit K_mac] ----> T'
Vergleiche T und T'
Wenn T = T' dann
   C ----> [Entschlüsselung mit K_enc] ----> M
Ende

Warum darf ein Passwort niemals als plaintext stehen?
Angreifen möglich warum? 
Nenne 2 erkennungsmerkmale dazu.
- Schutz vor Datenleks
- Unverschlüsselte Übertragung
- Klartext Passwörter in Datenbank
- Schutz vor Insider-Bedrohungen
- Fehlende Zugriffskontrollen
- Einfacher Datenbankzugriff
- Verhinderung von Passwort-Reuse-Angeiffen

Skizziere digitale Signatur 
1. Alice erstellt ein Schlüsselpaar und verteilt den öffentlichen schlüssel
2. Alice hast einen Ciphertext (oder sonstige Daten)
3. Alice verschlüsselt den Hash mit ihrem private Key
4. Alive versendet die Daten mitsamt Signatur
5. Bob entschlüsselt den Hash mit Alice public Key
6. Bob hasht die Daten und prüft den Hash


Wie kann man einen replay angriff verhindern?
- Timestamp bei übertragung von Daten


Erkläre RAID1 kurz und gib 1 Vorteil 1 Nachteil an
- Schreibe gleichzeitig auf die Festplatten
- Vorteile
- Doppelte Lesegeschwindigkeit
- Doppelte Verfügbarkeit
- Nachteile
- Doppelte Speicherkapazität notwendig
- Keine Erhöhung der Schreibgeschwindigkeit

Was ist ein DOS Angriff?
- Denial of Service
- Ziel: Schädigung der Verfügbarkeit eines Dienstes oder von Daten.

Aus einem Text lesen um was es sich für eine maleware handelt (Wurm , Virus,…) 

Dazu allgemeine Wissensfrage beantworten bsp: was muss der Mitarbeiter jetzt machen nachdem er den Virus entdeckt hat…. . 

Wieso ist es problematisch wenn man Sicherheitslücken/ backdoors absichtlich einbaut und dieses nicht veröffentlicht? 
- Entdeckung der Lücke durch Angreifer
- Vertrauensbruch

Wirtschaftsspionage wie wird das durchgeführt bei Social Engineering , 2 bsp angeben. 
- Phishing
- Pretexting

Warum muss man kleine Unternehmen besonders schützen ? 
Nenne 2 Gründe.
- Begrenzte Ressourcen und Expertise 
- Potentiell Katastrophe Folgen

---
Was deckt die ITS ab?
- Schutz von Daten vor:
	- *Zerstörung*
	- *Abhören*
	- *Manipulation*
	- etc.

Was umfasst Safety im IT Kontext?
- Die *Sicherheit* der *Verfügbarkeit* von Daten und IT bezogen auf *Hardware*

Auf welches Recht geht der Datenschutz zurück?
- "Schutz des Rechts auf informationelle Selbstbestimmung"

Nenne die 5 Säulen der IT-Sicherheit (vollziehe diese im Kopf nach)
- **Vertraulichkeit (Confidentiality)**
- **Integrität (Integrity)**
- **Verfügbarkeit (Availability)**
- **Nicht-/Abstreitbarkeit (Non-/ Repudiation)**
- **Authentizität (Authenticity)**

Erkläre die **CIA** Triade
- *Confidentiality, Integrity und Availability*
- Gibt nicht alle 3 gleichzeitig voll

Nenne eine kryptografische Maßnahme für jedes der Schutzziele der IT-Sicherheit. Welches der Schutzziele kann nicht (direkt) durch kryptografische Maßnahmen erfüllt werden?
- Vertraulichkeit: Verschlüsselung
- Integrität: Hash, MAC, Digitale Signatur
- Verfügbarkeit: X
- Nicht-/Abstreitbarkeit: Digitale Signatur
- Authentizität: MAC, Digitale Signatur

Was versteht man unter Open Source Intelligence?
- Infos durch offene Informationsquellen wie Websites, unsichere Apis, ... klauen

Was versteht man unter Ransomware?
- Daten verschlüsseln und nach Lösegeld fordern

Wofür steht DDOS? Was ist DOS?
- Distributed Denial of Service
- Verfügbarkeit eines Dienstes schädigen

Was ist Phishing?
- Opfer unter Vortäuschung falscher Umstände zu einer Tat bewegen.

Was sind die OWASP Top Ten? In welchen Bereichen sind diese relevant?
- Top 10 Schwachstellen in Mobilanwendungen (o.ä.)

Womit Befasst sich Steganographie?
- Verstecken von Infos

Womit befasst sich die Kryptographie?
- Erzeugung von Chiffren

Wie ist ein Kryptosystem Definiert?
- Ein Kryptosystem ist ein **Tupel (P, C, K, enc, dec)** mit folgenden Eigenschaften:
	- P (Plain Text Space): Die Menge der Klartexte
	- C (Cipher Text Space): Die Menge der Geheimtexte
	- K (Key Space): Die Menge der Schlüssel
	- enc (Encryption): $P x K \rightarrow C$: Eine Verschlüsselungsfunktion
	- dec (Decryption): $C x K \rightarrow P$: Eine Entschlüsselungsfunktion

Lassen sich alle Schutzziele durch kryptographische Methoden gewähren?
- Nein

Welche Typen von Kryptosystemen (symmetrisch) können unterschieden werden? Erkläre die beiden behandelten Formen.
- **Blockchiffren und Stromchiffren**
	- Blockchiffren: Ein Klartext $x \in P$ wird in Blöcke fester Länge zerlegt, welche alle mit demselben $ke \in K$ verschlüsselt werden.
	- Stromchiffren: Der bereits verschlüsselte Klartext beeinflusst den Schlüssel, mit dem die darauffolgenden Blöcke verschlüsselt werden.

Nenne und erkläre zwei Operationen, die auf Block- und Stromchiffren durchgeführt werden können.
1. Substitution: Ersetzen des Klartexts durch einen Geheimtext.
	- polyalphabetisch: Die Verschlüsselung eines Symbols ist abhängig von dessen Position im Klartext
	- monoalphabetisch: Klartextsymbol wird, unabhängig von dessen Position, immer zum selben Geheimsymbol verschlüsselt.
2. Transposition: Vertauschung der Reihenfolge des Klartextes

Erkläre wieso die allgemeine Verschiebe-Chiffre nicht Sicher ist (2 Gründe).
1. Die Verschiebe-Chiffre ist monoalphabetisch. Dies macht eine *statistische Analyse* des Geheimtextes möglich.
2. Der Geheimtext kann durch einen *Brute-Force-Angriff* mit Leichtigkeit gebrochen werden, da es nur 25 mögliche Schlüssel gibt.

Erkläre wieso die allgemeine Affine Chiffre nicht sicher ist.
- Hier kann eine *Häufigkeitsanalyse* durchgeführt werden, wobei zwei Elemente betrachtet und durch gleichsetzen der Verschlüsselungsfunktion zu einem Schlüsseltupel kombiniert werden.

Erkläre Kerckhoffs Prinzip und Security by Obscurity
- Kerckhoffs Prinzip: Der Kryptoanalytiker kennt das Kryptosystem das zur Chiffrierung des Klartextes verwendet wurde. *Das einzige Geheimnis ist der verwendete Schlüssel*.
- Security by Obscurity: Das verwendete Verfahren wird *geheimgehalten*. Das *Bekanntwerden* des Verfahrens *gefährdet die Sicherheit* aller, die dieses verwenden.

Welche Anforderungen gelten an PRNGs, wenn diese kryptographisch sicher sein sollen?
1. Unter Kenntnis der ersten k Bit eines PRNG Outputs ist es nicht möglich, unter Verwendung eines Polynomialzeitalgorithmus, das nächste Bit mit einer W'Keit signifikant größer als 50% vorherzusagen.
2. Sollte der Zustand des PRNG bekannt werden, so soll es nicht möglich sein die bis dahin generierte Folge an Zufallsbits zurückzurechnen.

Erkläre die Funktionsweise von Stromchiffren.
- Stromchiffren verschlüsseln einen Strom beliebiger Länge, wobei diese in Blöcke zerteilt wird und mit einem Teilschlüssel kodiert wird. Für den Schlüsselstrom wird initial ein PRNG genutzt, später evtl. der Klartext.

Erkläre die Begriffe Asynchron, Synchron und Periode im Kontext der Stromchiffren.
- Synchron: Der Erzeugte Schlüsselstrom ist unabhängig vom zu verschlüsselnden Klartext.
- Asynchron: Der Erzeugte Schlüsselstrom ist abhängig vom zu verschlüsselnden Klartext.
- Periode: Es existiert eine Konstante $d$, sodass $zi+d\cdot m=zi, m\geq 0$

Wie werden assymetrische Kryptosysteme genutzt?
- Zur Ver-/Entschlüsselung wird ein Schlüsselpaar verwendet:
	- Private Key: Wird vom Besitzer Geheimgehalten
	- Public Key: Wird öffentlich gemacht
- Eine Nachricht die mit dem Public Key verschlüsselt wurde kann nur mit dem Private Key wieder entschlüsselt werden und umgekehrt.

Welche Eigenschaft muss ein Kryptosystem erfüllen, um asymmetrisch zu sein? Worauf Basiert die Sicherheit bei dem Verfahren?
1. Aus public Key kann nur mit hohem Aufwand private Key berechnet werden.
2. mathematische Probleme.

Was ist eine PKI (Public Key Infrastruktur)?
Eine PKI ist die Summe an Hardware, Software, Personen, etc. die benötigt wird um digitale Zertifikate
- aufzustellen
- zu managen
- zu verteilen
- und zu widerrufen

Was ist ein digitales Zertifikat?
- Digitale nachweise einer Identität auf Basis von öffentlichen Schlüsseln.

Was ist ein Web of Trust?
- Ein Netz nicht hierarchischer, bzw. nicht in Reihe aufeinander vertrauter Zertifikate.

Was sind Hybride Kryptosysteme und wie Funktionieren diese?
1. Hybride Kryptosysteme vereinen die Vorteile symmetrischer (Geschwindigkeit) und asymmetrischer (sicherer Schlüsselaustausch) miteinander.
2. 
	- Alice möchte eine Geheime Nachricht an Bob senden, dafür holt sie sich Bobs öffentlichen Schlüssel
	- Alice generiert einen zufälligen Session Key zur symmetrischen Verschlüsselung
	- Alice verschlüsselt die zu sendende Nachricht mit dem Session Key und den Session Key selber mit dem öffentlichen Schlüssel von Bob.
	- Beides sendet sie an Bob, der den Session Key mithilfe des privaten Schlüssels entschlüsseln kann
	- Damit kann er auch die geheime Nachricht entschlüsseln.

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

Welche Schutzziele soll eine digitale Signatur gewährleisten?
- *Autenzität*
- *Integrität*
- *Nicht-/Abstreitbarkeit*

Was wird im TLS Handshake durchgeführt?
1. *Cipher Suit* (Schlüsselaustausch, Verschlüsselungsverfahren, Hashfunktion)
2. *Zertifikat* (Autentizität)
3. *Generierung eines symmetrischen Schlüssels und DH-Keyexchange* (Vertraulichkeit)
4. *MAC über bisherige Kommunikation*

Was ist Perfect Forward Secrecy? Wie wird sie gewährleistet?
- Die Garantie, dass wenn ein Schlüssel einer Verbindung öffentlich wird, die Vertraulichkeit weiterer Kommunikation nicht gefährdet ist.
- Durch ephemeral (flüchtig) Verfahren sind Schlüssel nur für einen Zeitraum gültig.

Was sind Extended Validation Zertifikate?
- Extended Validation Zertifikate sind Zertifikate, welche höherer Sicherheitsanforderung bieten. Sie erfordern z.B. Identitätsnachweis und Adresse des Antragstellers und einen Nachweis, dass der Antragsteller Alleiniger eigentümer der Domain ist.

Was sind DDOS, Spoofing, PITM/MITM, Hijacking?
- DDOS = Distributed Denial of Service. Ein DDOS ist das Überlasten eines Diensteanbieters durch Zugriffe von verschiedenen Quellen.

- Spoofing ist das Vortäuschen einer Identität, um z. B: Zugriff zu erlangen. Das ist oft eine erste Stufe für weitere Angriffe wie PITM.

- PITM/MITM = Person/Man in the Middle. Hier wird eine Kommunikation über eine/n dritte/n geleitet, um diese im Transit mitzulesen und/oder zu verändern.

- Beim Hijacking wird zusätzlich zum PITM die Identität des Gegenübers eingenommen, wobei dieses Vorher ausgeschaltet worden ist. Es werden also alle drei obigen Angriffe vereint.

Wie wird die Availability berechnet?
- $Availability = \frac{Uptime}{Uptime+Downtime}$

Was sind MTTF, MTBF, MTTR?
- *MTTF (mean time to failure)*
- *MTBF (mean time between failures)*
- *MTTR (mean time to repair)*

