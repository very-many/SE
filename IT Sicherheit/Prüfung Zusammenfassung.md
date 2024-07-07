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
- P: Plaintext
- C: Ciphertext
- K: Keyspace
- enc: Verschlüsselungsalgo
- dec: Entschlüsselungsalgo

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

Was ist DOS Angriff?
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