## Aufgabe 1.1

**Entitys:**
Kette = ({**KID: Zahl**, Name: Text})
Filiale = ({**FID: Zahl**, Straße: Text})
Stadt = ({**SID: Zahl**, Kategorie: {Kleinstadt, Mittelstadt, Großstadt, Metropole}})

Produkt = ({**PID: Zahl**, Bezeichnung: Text, Preis: FKZ})
Lebensmittel = ({MHD: Datum}) IS-A-Produkt
Elektroartikel = ({CE: Boolean, Prüfer: Text}) IS-A-Produkt

Kunde = ({**Code: Text**, Name: Text, Adresse: (plz: Text, str: Text, hnr: Text)})

Einkauf = ({**EID: Zahl**, Zeitpunkt: Datum})

**Beziehungen:**
gehört_zu = (Filiale x Kette)
ist_in = (Filiale x Stadt)
bietet = (Kette x Produkt)
kauft = (Einkauf x Produkt, {Anzahl: Zahl})
macht = (Kunde x Einkauf)
in = (Einkauf x Filiale)

**ERM** ![[S3/Datenbanksysteme/Klausuren/2012/Drawing 2025-01-20 09.25.00.excalidraw]]



