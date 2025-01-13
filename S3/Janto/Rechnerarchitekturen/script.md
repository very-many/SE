# Script 1
## Von Neumann/Eckert/Mauchly-Architektur
![[assets/Pasted image 20240316180708.png]]
### Komponenten
- CPU = Datenpfad + Steuerwerk
	- Datenpfad: ALU, Register
	- Steuerwerk: steuert sequenzielle Befehlsausführung auf Systembus
- Speicher: Programme und Daten (binary coded)
- Ein- und Ausgabeeinheit: Schnittstellen nach außen; Peripherie

- Architektur ist unabhängig von einem konkreten Problem, speicherprogrammierbar 
- Anweisungen und Daten werden in einem gemeinsamen Speicher gehalten 
- Speicher ist in Zellen gleicher Größe eingeteilt, adressierbar 
- Programm wird in Reihenfolge der Speicherung abgearbeitet, es gibt Sprungbefehle 
- Bedeutung von Speicherwerten ist kontextabhängig

### Steuerbus
- Steuerbus: überträgt Steuersignale
- (Steuerwerk schreibt auf Steuerbus)
- Unidirektional: CPU->RAM; CPU->I/O
- CPU-Status:
	- eine reservierte Steuerlinie bestimmt, ob CPU gerade Daten liest/schreibt
- Datensteuerung:
	- bestimmt Richtung des Datentransports
	- Auswahl der Systemfunktionen
- Systemsteuerung: Steuerung und Synchronisierung der Komponenten
	- bestimmte Systemtakte oder Reset-Signal
	- unterscheidet zwischen Speicher- und Peripheriezugriffen
	- zeigt an, ob Adresse auf Adressbis gültig ist
	- Meldesignale: Peripherie meldet sich
		- Fehlermeldung
		- Busnutzung: Unterbrechungssignal der Peripherie (Interrupt)

### Adressbus
- Adressbus: überträgt Adress-Signale
- Kontrolle: durch das Steuerwerk
- Unidirektional: CPU->RAM
- Eigenschaften
	- bestimmt Quell-/Zieladresse eines Datentramsports
	- Beispiel: 36 Adresslinien können $2^{36}$ = 64 GB RAM adressieren

### Datenbus
- Datenbus: überträgt Datensignale
- Bidirektional: CPU<->RAM; RAM<->I/O
- Eigenschaften:
	- Befehle vom Speicher kopieren
	- Operanden zwischen CPU und den verschiedenen Komponenten kopieren
	- Je breiter der Bus, desto mehr simultaner Datentransport, desto schneller

### von Neumann/Eckert/Mauchly-Architektur: Komponenten
![[assets/Pasted image 20240316183323.png]]

## Havard-Architecture
- Logische und physische Daten- und Befehlsspeicher sind getrennt
- Kann gleichzeitig Laden oder Schreiben von Befehelen und Daten
- Heutige Architekturen sind meistens gemoddete Havard-Architekturen, nur Logische Trennung
- ![[assets/Pasted image 20240316183911.png]]
## Havard vs Neumann
![[assets/Pasted image 20240316184114.png]]
## Aufbau des Prozessors
- Zentrale Rechen- und Steuereinheit
- Führt Programme (inkl. Betriebssystem) aus
- Enthält kleine, schnelle Speichereinheiten (Register)
- Spezielle Register
	- Stack Pointer
	- Program Counter
- Arithmetisch-Logische Einheit (ALU)
- Integer-Arithmetik (+ - * / )
- Logische Operationen (AND, OR, XOR, …)
- Bit-Shifting ( 0110 -> 1100, …)
- Heute: viele ALUs pro CPU
- Floating-Point-Operationen: werden von spezialisierten Rechenwerken (FPUs) durchgeführt; früher: Co-Prozessor
- Verarbeitet Instruktionen
- Verteilt Arbeit an Rechenwerk(e)
- Verwaltet aktuelle Programmposition (program counter, instruction counter)
- Liest und schreibt Daten vom/in den Speicher
-> Fetch-Decode-Execute-Zyklus
### Fetch-Decode-Execute
1. Hole Instruktion aus Speicher; inkrementiere Instruction-Pointer
2. Dekodiere Instruktion
3. Hole zugehörige Daten aus Speicher
4. Führt die Instruktion aus
5. Screibt das Ergebnis wieder zurück in den Speicher/Register
6. Repeat
![[assets/Pasted image 20240316184948.png]]
### Register
#### Datenregister
generell nutzbar für Operationen 
Früher: spezielle Datenregister wie Akkumulator als Ziel von Rechenoperationen
#### Adressregister
zur Adressierung (z.B. in Array, etc.)
8086: Index / Offset-Adressierung
#### Steuer-Register
Stack-Pointer, Instruction-Pointer
Statusregister (Carry, Overflow, Zero, Condition, ...)

## Instruction Set Architecture
- Binärkodiert, Maschinensprache, prozessorabhängig
- Assemblersprache ist menschenledbare Form, Abkürzungen ("Mnemonics") anstatt Binärzahlen
- Oft: Speicher <-> Register,
- Register <-> Register
### Einführung 
- ISA ist die Schnittstelle zwischen Hardware und unterster Softwareschicht
- ISA ist der Befehlssatz des Prozessors, also alle Instruktionen, die der Prozessor "kennt" und "versteht"
### Instruktionen
- teilen dem Prozessor schrittweise mit, welche Teilaufgaben er abzuarbeiten hat

### Maschinensprache (Assemblersprache)
- basiert auf Hardware, die dieselben Prinzipien hat (Neumann, Havard)
- ist deswegen sehr ähnlich für veerschiedene Prozessoren
- Assembler wird immer seltener zum Entwurf eingesetzt



## Mips Prozessorarchitektur
- MIPS: Microprocessor without Interlocked Pipeline Stages
	- 1985: Erster Multi-Prozessor mit unabhängigen Pipeline-Phasen
	- RISC-Architektur: moderne Prozessoren
	- Pipeline-Phasen
![[assets/Pasted image 20240316190449.png]]

- Pipeline: paralleles abarbeiten von Befehlsstatus
	- 4 Status: fetch; decode; execute; write-back
	- 5 Status: fetch; decode; execute; memory access; write-back
- Multi-core: unabhängige Kerne
![[assets/Pasted image 20240316190934.png]]
![[assets/Pasted image 20240316191307.png]]

## Aufbau eines Befehls in MIPS
- Die Operanden werden in Registern gespeichert
- Moderne RISC Architekturen haben typischerweise 32, 64 oder 128 Register je 32/64 Bit
- Alle arithmetischen Instruktionen haben den gleichen Aufbau
- Insgesamt gibt es bei MIPS 3 versch. Formen (R, I, J -Typ)
- pro Instruktion nur eine Operation
- längere sog. "mehrwertige" Operationen werden sequenzialisiert
	- BSP a=b+c+d+e -> 
		- add a,b,c
		- add a,a,d
		- add a,a,e
## Verwendung von Registern
- Je weniger Register desto besser
	- höhere Zugriffsgeschwindigkeit und weniger Bits zur Adressierung nötig
	- viele Register führen zu langen Signalwegen und großen clock cycle times
=> Design Prinzip: Kleiner ist schneller
- MIPS: 32 32-Bit Register im Inneren des Prozessors (32 Bit == 1 Wort)
## Registerkonventionen
- Bei MIPS müssen die 3 Operanfen in einem der 32 Register stehen. Die Position ist festgelegt.
- s0-s7 für variablen
- t0-t9 für zwischenergebnisse
![[assets/Pasted image 20240316194522.png]]
## Befehlstypen
![[assets/Pasted image 20240316194555.png]]
### R-type instructions
- only work on registers
- CPU-intern
(= memory in the inner CPU)
### I-Type instructions
- Bearbeitung von Registerinhalten im Prozessor
- Da 32 Register nicht ausreichen muss auch der RAM verwendet werden
	- Daten vom Speicher in ein CPU-Register laden
	- => Load word (lw)
	- Daten von einem Register in den Arbeitsspeicher schreiben
	- => Store word (sw)
- Load word und store word sind die einzigen MIPS-Befehle, mit denen man auf den Speicher zugreifen kann
- Mit Load word und store word kann MIPS auch auf I/O-Geräte zugreifen 
	- Speicheradressen zeigen dann auf I/O anstatt auf den Speicher 
		- Vorteil : keine extra Befehle nötig 
		- =>MEMORY MAPPED I/O
- Alternative ist: ISOLATED I/O
	- Prozessor hat dann extra Signal /MIO, zur Auswahl von Memory oder I/O
		- sämtliche andere Module müssen dieses Signal auch auswerten
### I-Type instructions
- I-Type Instruktionen (immediately) haben eine Konstante direkt im Befehl -> spart Speicherzugriffe
-> Make the common case fast
- da I-Type-Befehle dieselbe Struktur haben => 16 Bit (wie Offset bei lw/sw)

### Zero register
- Dem Register ist der Wert 0 zugeordnet
- Name: $zero

### Kontrollstrukturen
- Bei MIPS erhöht sich der Program Counter nicht um 1, sondern immer um 4
- Bei MIPS ist der Program Counter für den Programmierer nicht direkt zugänglich !
### 4-bit Befehlssatz
#### jump
jump - damit springt man um einen offset
maximale Sprungweite 2^28
![[assets/Pasted image 20240316204107.png]]
laut bild ist es anscheinend doch kein offset

#### beq/bne
branch equals - Inhalte von 2 Registern gleich
branch not equals - Inhalte von 2 registern ungleich
![[assets/Pasted image 20240316204334.png]]

#### if/else
![[assets/Pasted image 20240316204428.png]]

#### while/loop
![[assets/Pasted image 20240316204708.png]]

#### bedingte Sprünge
- a\<b oder a\>b gibts nicht als compare befehl
- man muss selbst erst evaluieren und dann kann man beq oder bne benutzen
![[assets/Pasted image 20240316204959.png]]

#### makros
wenn man faul ist kann auch ein makro erstellt werden welche die beiden/mehrere befehle zu einem bündelt
![[assets/Pasted image 20240316205248.png]]
oder move
![[assets/Pasted image 20240316205322.png]]

## Funktionsaufrufe

MIPS Konventionen
- Übergabeparameter an Prozedur (Callee) 
	- Register \$a0,…,\$a3
- Rückgabeparameter an aufrufendes Programm (Caller) 
	- Register $v0, $v1
- Rückkehradresse => Return Address Register $ra

- jal Prozeduradresse -> springt zum Label "Prozeduradresse" und sichert Adresse der nächsten Instruktion (PC+4) in $ra
- jr $ra springt zur adresse die in $ra gespeichert ist 
- wird zum rückkehren von einer Prozedur verwendet

### Vorgangsweise
- Aufrufendes Programm "Caller" schreibt Übergabeparameter in $a0 bis $a3
- Caller springt mit "jal Callee" ins Unterprogramm "Callee"
- Callee führt Prozedur aus
- Callee schreibt Prozedurergebnisse on $v0, $v1
- Callee überstellt an Caller mit dem Befehl jr $ra

### Probleme
Wenn die 4 Parameter und 2 Rückgaberegister nicht ausreichen:
-> Stack verwenden, $sp zeigt auf den Beginn des Stacks
![[assets/Pasted image 20240316210347.png]]

### MIPS jump register konventionen
- \$t0-\$t9: 
	- Dies sind temporäre Register und können von Callees beliebig verändert werden
- \$s0-$s7: 
	- sog. “saved registers”, Inhalte dieser Register müssen vom Callee (mittels Operationen auf dem Stack) wiederhergestellt werden

### syscalls
zuerst wird das register $v0 festgelegt

danach "syscall" ausführen

![[assets/Pasted image 20240316211005.png]]
## Script 3
### Endiannes
![[assets/Pasted image 20240317132628.png]]

### Halbaddierer
![[assets/Pasted image 20240317133043.png]]
![[assets/Pasted image 20240317133050.png]]
### Volladdierer
![[assets/material-qywaax3p.png]]

Dieses Volladdierer module lässt sich für mehrstellige Zahlen auch mit anderen verknüpfen:
![[assets/Pasted image 20240317133445.png]]
### Aufbau einer ALU(Arithmetic Logical Unit)
- ein paar einfach logische Gatter: and / or / nand / nor, xor ...
- ein paar Volladdierer
- ein paar Multiplexer und Demultiplexer
- um Alu in einen MIPS-Light Prozessor zu integrieren benötigt man dann zusätzlich noch ein paar in Reihe geschaltete Flipflops = "Register"
- 1 Bit Alu für and und or:
  ![[assets/Pasted image 20240317134439.png]]
  - Erweiterung um einen Volladdierer:
    ![[assets/Pasted image 20240317134544.png]]
### Erweiterung um den SUB-Befehl
![[assets/Pasted image 20240317134700.png]]
Für den Sub befehl wird das Binvert modul hinzugefügt, es kann Bit flippen. Die 1 für das 2 komplementär wird dann noch über das Carry in signal addiert

### Erweiterung um  NOR funktion
![[assets/Pasted image 20240317154151.png]]
Die Schaltung wird um eine NOR-Funktion für a erweitert
### 32-Bit Alu
![[assets/Pasted image 20240317154325.png]]
32 dieser ALUs werden miteinander verbunden
### Implementierung von SLT (SET LESS THEN)
![[assets/Pasted image 20240317155433.png]]
Für
```assembly
slt $t0, $s1, $s2
```
 Muss zuerst \$s1-\$s2 berechnet werden
Wenn es Negativ ist dann setzte LSB von $t0 auf 1 und alle anderen bits auf 0
ansonsten setzte alle bits von $t0 auf 0

=> Wie werden diese Bits gesetzt ?
	=> Neues less Signal wird verwendet

Das  Vorzeichenbit von an ALU31 wird mit dem Less signal von ALU0 verbunden, alle anderen Less signale werden mit 0 verbunden

### Overflow detection
Auswertung von a,b, Carry an ALU 31

### Implementierung von BEQ BNE
MIPS Befehl:
```
beq $s1, $s2, label
```
Alle bits von $s1 und $s2 werden über den Volladdierer verglichen und dann über ein OR ausgewertet damit wird dann eine Zero flag gesetzt
![[assets/Pasted image 20240317161113.png]]
### Fertige MIPS Light ALU
Operationen: and, or, nor, add, sub, slt, beq, bne
ALU Steuersignale: 2 Leitungen für and, or, add und slt
			     2 Leitungen für sub, nor und slt


### Multiplikation
![[assets/Pasted image 20240317161755.png]]
Einfache Multiplikationslogik

![[assets/Pasted image 20240317162423.png]]

Schnellere Multiplikation durch mehr Hardware:
![[assets/Pasted image 20240317162628.png]]

- Das Produkt wird in zwei speziellen 32-Bit Registern gespeichert:
	- HI: MSB (obere 32-Bit)
	- LO: LSB (untere 32-Bit)
- Instruktionen:
	- Zuerst Multiplikation
	- `mult t0, t1`
	- HI nach t3 kopieren, LO nach t2
	- `mfhi t3`
	- `mflo t2`
	- Der Assembler unterstützt Makro mul für t2 = LSB(t0\*t1)
	- `mul t2, t0, t1`

### Division
![[assets/Pasted image 20240317163251.png]]
- Das Ergebnis wird in zwei speziellen 32-Bit Registern gespeichert
	- HI: 32bit Restwert
	- LO: 32bit Quotient
- Instruktionen:
	- Division t0 / t1 -> HI = t0 mod t1, LO = t0 / t1
	- `div t0,t1`
	- Kein Overflow-Check oder Check auf Division durch 0!
# Script 4
### Grundlegende Schritte der Befehlsausführung (NEUMANN-ZYKLUS)
1. IF Instruction Fetch: Addressieren des Instruktionsspeichers mit dem Wert des Befehlszählers und Laden der nächsten Instruktion
2. ID Instruction decode, Register Fetch: lesen eins (z.b. bei l-typ) oder zweier ( z.B. bei R-Typ) Register, um Operanden bereit zu stellen
3. EX Execute, Memory Address Computation, Branch Completion: Operationsausführung oder Addressberechnung unter  Verwendung der ALU
4. MEM Memory Access, R-Type Instruction Completion
   - Speicherzugriff (bei lw,sw)
   - ALU-Ausgang in Register schreiben (bei arithm./log. Instruktionen)
   - Neuen Wert in den Befehlszähler schreiben (branch/jump)
5. WB Memory Read Completion: (bei lw) Memorywert in Register schreiben

![[assets/Pasted image 20240317165356.png]]
### Cycle und Multi Cycle CPU
Die Leistungsfähigkeit eines Computer hängt u.a. ab von
=> Takt-Zykluszeit (Taktfrequenz)
=> Anzahl der Taktzyklen pro Befehlt (CPI)

### Übersicht zu Single Cycle und Multi Cycle CPU
**Single Cycle**
- jede Instruktion wird in einem (langen) Taktzyklus ausgeführt
- während eines Instruktionszyklus kann ein Datenpfadsegment nur einmal benutzt werden 
  => aufwändigere Hardware
- verschiedene Instruktionsklassen sollen dieselben Datenpfadelemente nutzen, hierzu bedarf es mehrere Multiplexer
- sehr einfache Steuerung (rein kombinatorisch)
- der am längsten dauernde Befehl (Load Word) definiert die Taktperiode
**Multi Cycle**
- Aufteilung der Instruktionsabarbeitung in mehrere Teilschritte
- Jeder Teilschritt benötigt einen Taktzyklus
- Taktperiode kann kürzer werden
- je nach Instruktion kann die Anzahl der Schritte unterschiedlich sein
- Datenpfadelemente können mehrfach verwendet werden => Hardwarereduktion!
- zusätzliche Register zur Speicherung der Signale zwischen Taktschritten nötig
- Steuerung ist komplexer im Vergleich zum Single Cycle

### Bausteine des Datenpfads
Die Analyse des Befehlssatzes legt die Verwendung von folgender Hardware nahe:
- externer Speicher (Befehle & Daten)
- 32 x 32 Registersatz mit 32 Wörtern a 32 Bit
	- 5 Bit-Adresseingang für RS: Lesen von rs
	- 5 Bit-Adresseingang für RT: Lesen oder Schreiben von rd
	- 5 Bit-Adresseingang für RD; Schreiben von rd
- Befehlszähler (Programm counter) PC (ebenfalls ein Register)
- 16-32 Bit-Extender (für Sign-Extension)
- ALU (für add, sub, and, or, nor
![[assets/Pasted image 20240317171058.png]]

### Kombinatorische und sequentielle Logik im Datenpfad
- Ein sequentielles Element wird mit der steigenden oder fallenden Flanke eines systemweiten Taktsignals (Clock) gesteuert
- Sämtliche Register sind flankengesteuert und können in einer Taktperiode nur 1x (z.B. mit der steigenden Flanke) beschrieben werden
- Rein kombinatorische Logik enthält keine Speicher, bei Änderung der Eingangssignale erreicht der Ausgang nach einem Delay einen dauerhaften Endzustand
- Die CPU enthält sowohl kombinatorische als auch sequentielle Elemente

### Rein kombinatorische Elemente des Datenpfads
![[assets/Pasted image 20240317171610.png]]


### Sequentielle (speichernde) Elemente des Datenpfades
![[assets/Pasted image 20240317171841.png]]

**Externes Memory**
32-Bit-Adresse selektiert Wort im Speicher
- bei MemWrite = 1 wird das 32-Bit-Wort am Eingang "Write data" ins Memory geschrieben
- bei MemRead = 1 wird das 31-Bit-Wort an den Ausgang "Read data" gestellt
![[assets/Pasted image 20240317172330.png]]
**Befehlsspeicher**
- Adresse selektiert Wort im Speicher
- 32-Befehlt-Bit-Code liegt dann an "Instruction" an
- für Befehlsausführung quasi-kombinatorisch (da nur gelesen wird)
![[assets/Pasted image 20240317172341.png]]
**Programm Counter**
- Zähler für die Adresse des Befehlsspeichers

# Script 6
### Datenrate oder Bandbreite
SRRAM mit 256K\*4 Zugriffszeit 12ns:
Datenrate = 4-Bit * 83Mhz = 333333333.3 Bit/s / 8 = 41666666.66 Byte/s /1000 = 41666.6 KB/sec / 1000 = 41.6 MB/sec
##### Speicherzugriffszeit
Die Zeit die das Speicherelement braucht um den an der Adresse liegenden Wert auszugeben
![[assets/Pasted image 20240317174839.png]]
##### Speicherzykluszeit
ist die minimale Zeit die zwischen 2 aufeinanderfolgenden Anlegen von Adressen an den Speicher vergeht
![[assets/Pasted image 20240317174952.png]]

### Speichermatrix
Die Speicherelemente sind matrizenartig angebracht

Jedes Speicherelement liegt im Schnittpunkt einer Zeilen-Auswahlleitung und eine Spalte-Auswahlleitung

Um die Anzahl der Auswahlleitung zu minimieren versucht man die Speichermatrix möglichst quadratisch aufzubauen

Spalten-Auswahlleitungen (MSBs) nennt man Daten- oder Bitleitungen. Zeilen-Auswahlleitungen (LSBs) werden als Wortleitungen bezeichnet.

### Adressierung der Speichermatrix
![[assets/Pasted image 20240317175826.png]]
- die Adressierung erfolgt über die Adresspins
- **Es sind of zusätzliche speicherinterne Schnittstellen nötig**
	- damit man Treiberleistung zu Verfügung stellen kann
	- um Pegelanpassungen sicherzustellen
Bei DRAMs wird dem Baustein die Speicheradresse oft in mehreren Teilen sequentiell zugeführt, um die Anzahl der Anschlusspins klein zu halten. Dann müssen die Teiladressen in den Interfaces zwischengespeichert werden.

### Synchrone Speicherbausteine
- Speicherzugriffe werden per Taktsignal mit Vorgängen auf dem Bus synchronisiert
- Adressen Daten und Steuersignal werden in Registern zwischengespeichert und durch Triggerung des Bustakts CLK speicherintern zu Verfügung gestellt
- oft ist (De-)Aktivierung des CLK-Eingangs mit CLock Enable Signal möglich


### Steuerlogik von Speicherbausteinen
- Chips Select / Chip Enable
- Read / Write
- Output Enable

### Klassifizierung von Halbleiterspeichern
![[assets/Pasted image 20240317180845.png]]
- (M)Rom: Read only Memory: kann nur vom Hersteller beschrieben werden
- Prom : Programmable Read only Memory: kann einmalig beschrieben werden
- EPROM: Erasable Programmable Read only Memory: Kann mittels UV-Licht gelöscht und dann neu beschrieben werden
- EEPROM: Electrically Erasable Programmable Read only Memory: Kann durch ein elektrisches Signal gelöscht und dann neu beschrieben werden

**SRAMs**: Statische RAMs
- Informationen wird in Zellen gespeichert die aus Flip-Flops bestehen
- SRAMs halten eine einmal eingeschriebene Information so lange, bis sie durch einen erneuten Speichervorgang verändert wird
- Bipolar oder MOS-Technologie
- schnell und teuer, daher in Cachehierarchie eher prozessornah

**DRAMs**: Dynamische RAMs
- Information wird als elektrische Ladung in einem Kondensator gespeichert
- Lesen bedingt in der Regel das Entladen des Kondensators, so dass danach der gelesene Wert wieder eingeschrieben werden muss
- Ladung geht durch unvermeidbare Leckströme kontinuierlich verloren, so dass in regelmäßigen Abständen aufgefrischt werden muss
- MOS Transistoren
- langsam aber billig, Verwendung eher im prozessorfernen Hauptspeicher
![[assets/Pasted image 20240317182658.png]]

### Synchron vs Asynchron
Synchron gibt nur daten durch ein externes Clock signal zurück
Asynchron gibt daten zurück sobald sie ausgelesen sind

### DRAM
![[assets/Pasted image 20240317183344.png]]
Speicherzelle besteht nur aus einem Transistor und einem Kondensator (C $\approx$ 50...100fF)

**Schreiben:**
Aktivieren der Wortleitung -> T leitet -> Datum wird auf Bitleitung gelegt
1 -> C wird auf $U_{DD}$ aufgeladen
0 -> C wird auf 0V entladen

Deaktivieren der Wortleitung -> T hochohmig -> C speichert Info

**Lesen**
Aktivieren der Wortleitung
C geladen: Entladung über Bitleitung
C ungeladen: Keine Entladung über Bitleitung

**Refresh**
- beim Lesen wird C entladen, d.h. nach dem Lesen muss das ursprüngliche Datum in die Zelle zurückgeschrieben werden
- Auch bei Nichtaktivierung der Zelle entladen sich die Kondensatoren durch Leckströme
- Ein regelmäßiger Refresh (im ms-Bereich) des gesamten Speichers ist notwendig

**Precharge-Technik und Leseverstärker**
- Durch Miniaturisierung wird es immer schwieriger den Ladezustand des Kondensators sicher zu erkennen und auszuwerten
- Einsatz von differentiellen Leseverfahren mit Precharge-Vergleichstechnik

### DRAM Bausteine
 Integrationsdichte am Beispiel der Infineon 0,20$\mu m$ Technologie
 - 1 SRAM-Zelle: ca 10 - 11$\mu m^2$  
 - 1 DRAM-Zelle: ca 0,7 - 1$\mu m^2$ 

**Reine DRAMs sind quasi vom Markt verschwunden**
alternativen:
- FPM
- EDO Mode
- SDRAM
- DDR (Deutsche Demokratische Republik)
- Rambus

### DRAM Controller 
<<<<<<< HEAD
![[assets/Pasted image 20240317190132 1 1.png]]
=======
![[assets/Pasted image 20240317190132.png]]
>>>>>>> origin/main
- DRAM Bausteine benötigen aufwendige Ansteuerung
- Es gibt daher DRAM-Controller fertig zu kaufen
- In machen Bridges ist solch einer meist enthalten z.B. PCI Host-Bridge
- viele moderne Mikroprozessoren und Mikrocontroller haben DRAM Controller-on-Chip
- Fehlerkorrektur mit redundanten Zusatzprüfbits ist of On-Chip integriert ECC
- DRAM Controller enthalten selbst Speicher sowie Steuer und Statusregister
- **DRAM Controller sind meist programmierbar und können unterschiedliche Typen von DRAMs unterstützen**

### Organisation des Arbeitsspeichers
- dem Prozessor erscheint der Arbeitsspeicher wie eine lineare Liste von Einträgen, von denen jeder durch Angabe einer Adresse wahlfrei (Random Access) selektiert werden kann

### Memory Map
<<<<<<< HEAD
![[assets/Pasted image 20240317190636 1 1.png]]
=======
![[assets/Pasted image 20240317190636.png]]
>>>>>>> origin/main

## Die Speicher-Hierachie
- Moderne Rechnerarchitekturen besitzen mehrere Cache-Level zwischen Cpu und dem Hauptspeicher
- Je schneller der Zugriff, desto teurer

### Direct Mapped Caches
Für jede Speicher-Adresse gibt es genau einen Platz im Cache

Aber: Cache ist kleiner als Hauptspeicher!
- Mit modulo von der Speicherblock-Adresse die "höheren Bit abschneiden"
- Restliche Bits mappen auf den Block
- wir müssen die oberen Bits aber zusätzlich ablegen
![[assets/Pasted image 20240317191659.png]]
### Assoziative Caches
Bei neuem Cache eintrag:
- Speicheradresse modulo
- Freien Eintrag finden

Cache-Lookup
- Adresse bestimmen (mod)
- Alle belegten Einträge suchen, Tag vergleichen

# Script 7