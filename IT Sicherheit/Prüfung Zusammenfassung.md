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

-nenne 2 algorithmischen Schlüssel Tausch Methoden und skizziere 1 davon. 

-ist der Befehl rand() sicher? 
Wenn nein dann nenne Alternative. 

-hashing, was ist hash Funktion und nenne 3 Eigenschaften davon. 

-was ist kollisionsresistenz?

-nenne 2 Anwendungsbereiche für hash Funktion. 

-was für eine Grundidee steckt hinter MAC und wofür?

-skizziere encrypt then mac. 

-warum darf ein Passwort niemals als plaintext stehen?
Angreifen möglich warum? 
Nenne 2 erkennungsmerkmale dazu. 

-skizziere digitale Signatur 

-wie kann man einen replay angriff verhindern?

-erkläre raid level 1 kurz und gib 1 Vorteil 1 Nachteil an 

-was ist dos Angriff?

-aus einem Text lesen um was es sich für eine maleware handelt (Wurm , Virus,…) 

Dazu allgemeine Wissensfrage beantworten bsp: was muss der Mitarbeiter jetzt machen nachdem er den Virus entdeckt hat…. . 

-wieso ist es problematisch wenn man Sicherheitslücken/ backdoors absichtlich einbaut und dieses nicht veröffentlicht? 

-wirtschaftsspionage wie wird das durchgeführt bei Social Engineering , 2 bsp angeben. 

-warum muss man kleine Unternehmen besonders schützen ? 
Nenne 2 Gründe.