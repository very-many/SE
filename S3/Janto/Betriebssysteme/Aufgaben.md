## Script 1
![[Assets/Pasted image 20240313154014.png]]

1. Bei Stapelverarbeitung werden alle Prozesse nacheinander in Batches abgearbeitet beim Time Sharing hingegen bekommt ein Prozess nur eine bestimmte Zeit zum Arbeiten, danach ist der nächste Prozess dran, Durch Time Sharing wurde z.B.  Multitasking möglich gemacht
2. 
	   - Programm: Sammlung von Anweisungen die von einem Computer ausgeführt werden
	   - Prozess: Eine Instanz eines laufenden Programms auf dem Computer
	   - Thread: Die kleinste ausführbare Einheit innerhalb eines Prozesses 
	     
3. Programme müssen dank Abstraktion nicht direkt auf die Hardware des Computer zugreifen. Sie können einfach System calls verwenden die dann vom Betriebssystem und den Treibern in Hardware aufrufe übersetzt werden
4. 
   1. Schwere Erreichbarkeit von Systemen
   2. Durch meist fehlendes Betriebssystem muss Code für die Hardware selbst geschrieben werden
5. LMA

## Script 2
![[Assets/Pasted image 20240313154039.png]]
1. 
   - Stapelverabeitung: FCFS (First Cum First Serve)
   - Interaktive Verarbeitung: RR,
   - Preemptive: RR
   - NON Preemptive: FCFS
2. LMA
3. 
   a)
	   - Pipes
	   - Shared memory
	   - Files
   b)
	   - Sockets
	   - MQTT
4. 
	- Prozess Kontext speichern
	- Programm Counter auf Befehlsroutine setzen
	- Kernelmode betreten
	- Ausführen des Syscalls
	- Wiederherstellen des Prozess Kontexts  
	- Wechseln in Usermode
	- Ausführung des Prozesses fortsetzen
5. fopen() ist der c stdlib call um dateien zu öffnen. Er funktioniert cross platform. open() hingegen ist der Call für die GNU/Linux implementation
	
![[Assets/Pasted image 20240313154049.png]]

## Script 3
![[Assets/Pasted image 20240313154121.png]]
1. 
   Räumliche Lokalität: Wird z.B. bei Arrays verwendet. Wenn auf ein Wert eine Arrays zugegriffen wird, dann werden benachbarte Werte direkt mit in den Cache für einen schnelleren Zugriff geladen
   
   Zeitliche Lokalität: Eine Variable die Oft in kurzer Zeit hintereinander verwendet wird, wird in den Cache geladen um das zu beschleunigen
2. Schneller Speicher -> Nah an Cpu -> Teuer -> Wenig
   Langsamer Speicher -> Weiter weg con Cpu -> Günstiger -> Mehr
3. Wenn der RAM fragmentiert liegen Teile der verketteten Liste nicht mehr nebeneinander => Sie können nicht mehr gecached werden
4. 
5. 
   Swapping:
    - Kann Prozesse aus dem Hauptspeicher in den Massenspeicher verschieben um Platz zu machen
    Paging:
    - Teilt den virtuellen Addressraum in kleine gleich große Teile ( Pages)
    - Die Pages können Dynamisch zugewiesen und freigegeben werden
6. Es wird zuerst die richtige Seitentabelle ausgelesen, aus dieser wird dann mit der Seitennummer die Basisadresse ausgelesen. Zu der Basisadresse wird noch der Offset addiert und am Ende erhält man dann die Reale Adresse
7. Der Offset wird genutzt um von der Basisadresse einer Page dorthin zu gelangen wo die Variablen o.ä. gespeichert sind 
8. Die TLB speichert die Realen Adressen der letzten x Virtuellen Adressen um diesen Zugriff zu beschleunigen
  
![[Assets/Pasted image 20240313154134.png]]
9. Mit Hilfe von Mapping werden bestimmte Werte zu anderen Werten zugeordnet.
10. Der Fehler Segmentation Fault kann erscheinen wenn man auf einen Speicherbereich zugreifen möchte welcher nicht zum aktuellen Programm gehört (Speicherschutzverletzung)
11. Wenn ein Page Fault auftritt, dann heißt dies, dass die benötigte Page nicht im RAM sonder auf dem Massenspeicher liegt. Daher muss bei einem Page Fault die benötigte Page in den Ram geladen werden
12. Da die Größe der Seitentabellen nicht von der Hardware abhängig ist, sondern nur von der verwendeten Architektur werden die Seitentabellen bei einem 64-Bit System extrem groß
## Script 4
![[Assets/Pasted image 20240313154153.png]]
1. STDIN: Wird als Datenstrom für Inputs verwendet (z.B. Tastatur)
   STDOUT: Wird als Datenstrom für Outputs verwendet (z.B. Monitor)
   STDERR: Wird als Datenstrom für Fehlernachrichten verwendet
2. ./a < ainput 2> aerrors
3. >: Wird genutzt um den Output eines Prozesses in eine Datei umzuleiten
   | : Wird genutzt um den Output eines Prozesses als Eingabe eines Prozess zu nutzen
4. Es wird eine Gerätedatei für das Gerät in /dev/ platziert
5. 
   - Geräte unabhängige Nutzung
   - Einheitliche Benennung (Festplatte /dev/sda*)
   - Hardwarenahe Fehlerbehandlung
   - Optimierung der Kommunikation
   - Schutz des Gerätezugriffs
6. 
   - Abstraktion der Geräte
   - Geräteinitialisierung und Konfiguration
   - Verarbeitung von Eingabe und Ausgaben
7. 
   - Ausgleich von Geschwindigkeitsunterschieden
   - Reduzierung von Wartezeiten
8. 
   - Gemeinsamkeiten:
     - Datentransfer zwischen Peripherie und Hauptspeicher
     - Effiziensteigerung
   - Unterschiede:
     - Interruptgesteurter EA: Hier wird von dem Peripheriegerät eine Interruptrequest and die Cpu gesendet hier muss diese sich dann darum kümmern das die Daten in den RAM kommen
       
       DMA: Bei DMA übernimmt der DMA-Controller diese Aufgabe, er nimmt die Daten der Peripherie Geräte und überträgt diese in den Hauptspeicher
![[Assets/Pasted image 20240313154203.png]]
9. Das ist wenn ein Teils des Hauptspeicher für I/O Geräte verwendet wird. Hier schreiben / lesen die Geräte in einen bestimmten teil des Hauptspeichers
10. 
    1. Die Tastatur erzeugt beim Drücken der Taste ein bestimmtes Signal
    2. Der Tastaturcontroller wandelt diese Signale in Codes um
    3. Die USB Schnittstelle des Computers erhält diese Codes
    4. Der Treiber erfasst die Codes und verarbeitet sie weiter
    5. Die Tastenanschläge werden auf den Tastaturpuffer gelegt
    6. Die Anschläge im Puffer werden von den Anwendungen / dem Betriebssystem verarbeitet
11. Die Abstraktion durch die Geräteverwaltung stellt z.B. beim Drucken ein Interface bereit durch das einfach Dokumente gedruckt werden können, ohne das man die spezifische Drucker- Hardware kennen muss
12. 
    - GUI
    - TUI
    - CLI
    - VUI
13. 
    - Display Server
    - Windowmanager
    - Widget Toolkit
    - Desktop Environment
## Script 5
![[Assets/Pasted image 20240313154222.png]]
1. 
   - Textdateien
   - Videodateien
   - Bilddateien
   - Binärdateien
2. 
   Dateien:
   - Öffnen
   - Schließen
   - Lesen
   - Schreiben
   - Positionieren
   - Erzeugen
   - Löschen
   Verzeichnisse:
   - Erzeugen
   - Löschen
   - Einträge lesen
   - Wechseln
3. 
   1. Festplatte anschließen
   2. Festplatte auf ein kompatibles Dateisystem prüfen und ggf. formatieren
   3. Festplatte in einem Ordner mounten
4. Bei nutzung von fopen wird die fopen funtion aus der Standard Bibliothek verwendet um eine Datei zu öffnen. Die fopen funktion gibt einen Zeiger auf einen Dateistream zurück in dem die Datei ist
5. fopen() ist aus der Standard Bibliothek von C, diese funktion funktioniert Systemunabhängig
   open() ist die Unix implementation dieser Funktion
6. Die Datei-Handle ist eine Art Referenz der einer geöffneten Datei gehört. Er ermöglicht es einem Programm auf eine Datei zuzugreifen und Operationen wie Lesen Schreiben verschieben usw. durchzuführen
7. Benutzer a hat Read Write Execute Rechte auf diese Datei und darf deshalb alles mit ihr machen
   Damit nutzer c den Inhalt lesen kann muss er der Gruppe b beitreten
   Andere Benutzer die nicht in der Gruppe B sind dürfen gar nichts mit dieser Datei machen
8. Weil der Datenträger in Cluster aufgeteilt ist und Dateien die kleiner als ein Cluster sind genau so viel Platz brauchen wie der gesamte Cluster in dem sie sind
![[Assets/Pasted image 20240313154232.png]]
9. Linux: lsof
   Windows: Ressourcenmonitor
10. Ein Inode ist eine Datenstruktur die genutzt wird um Metadaten über ein Verzeichnis oder eine Datei zu speichern. Inodes werden in den meisten UNIX basierten Dateisystemen verwendet
11. In ext4 wird der Dateiname nicht im Inode gespeichert. Die Dateinamen werden in Verzeichnissen gespeichert in denen Dateinamen auf Inode nummern abgebildet werden
12. FAT32: Maximale Dateigröße von 4GB, Keine Zugriffskontrolle, File Allocation Table, Kein Journaling, Namenlänge 8.3
    NTFS: Maximale Dateigröße mehrere TB, Zugriffskontrolle, MFT, Journaling, Compression, Namenlänge 255
13.  Fat und MFT unterscheiden sich durch die Art wie sie speichern in welchen Clustern Dateien liegen. Des weiteren speichert MFT auch noch deutlich mehr Metadaten über jede Datei
14. WebDAV wird als Dateiserver verwendet um Dateien mit anderen Geräten zu teilen
15. Mit Samba kann man Windows Datei Freigaben managen
## Script 7
![[Assets/Pasted image 20240313154318.png]]
1. Das Remote Desktop Protokoll ist ein von Microsoft entwickeltes Protokoll zur Fernsteuerung von Computern
2. Ein Thin Client ist ein sehr schwacher PC welcher beispielsweise RDP oder ssh verwendet um auf ein Leistungsstärkeren Computer oder Server zuzugreifen, damit auf diesem dann gearbeitet werden kann
3. 
   - SSH
   - AnyDesk
   - Teamviewer
   - Parsec
   - RDP
4. Typ1: Microsoft Hyper V, KVM
   Typ2: Virtualbox
5. 
   Gemeinsamkeiten:
   - Isolierung
   Unterschiede:
   - Emulation: Emuliert gesamte Hardware eine Geräts
   - Container Virtualisierung: Die Container sind alle Isoliert zueinander teilen sich aber gleiche Systemkomponenten
   - Voll Virtualisierung: Isoliert das Guest-System vollständig, emuliert aber keine Hardware
6. 
```bash
docker run --env MARIADB_ROOT_PASSWORD=hallo mariadb:latest
```
7. Die Vorteile eine benannten Volumes sind zum einen dass die Dateien in diesen persistieren. Ein Vorteil von Volumes gegenüber von Bind Mounts ist außerdem dass diese sehr Portabel sind