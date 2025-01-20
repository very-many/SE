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

**ERM:** ![[S3/Datenbanksysteme/Klausuren/2012/Drawing 2025-01-20 09.25.00.excalidraw]]
**Kardinalitäten:**

| gehört_zu | (1, 1)                                              | (0, N)                                                                                                                      |
| --------- | --------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- |
|           | min/max 1: Eine Filiale gehört genau zu einer Kette | min 0: Eine Kette muss (bei Initialisierung) noch keine Filiale haben<br>max: Eine Katte kann beliebig viele Filialen haben |

| ist_in | (1, 1)                                           | (0, N)                                                                                                   |
| ------ | ------------------------------------------------ | -------------------------------------------------------------------------------------------------------- |
|        | min/max 1: Eine Filiale ist in genau einer Stadt | min 0: In einer Stadt muss keine Filiale sein<br>max: In einer Stadt können beliebig viele Filialen sein |

| bietet | (0, M)                                                                                                                              | (0, N)                                                                                                                           |
| ------ | ----------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------- |
|        | min 0: Eine Kette muss  (bei Initialisierung) noch keine Produkte anbieten<br>max: Eine Kette kann beliebig viele Produkte anbieten | min 0: Eine Produkt muss nicht in einer Kette angeboten werden<br>max: Ein Produkt an in beliebig vielen Ketten angeboten werden |

**Bedeutung Beziehungs-Typen:**
Eine konkrete Beziehung des Typs *gehört_zu* zwischen einem Entity $e_{1}$ des Typs *Filiale* und einem Entity $e_{2}$ des Typs *Kette* bedeutet dass: Filiale $e_{1}$ zur Kette $e_{2}$ gehört.

Eine konkrete Beziehung des Typs *ist_in* zwischen einem Entity $e_{1}$ des Typs *Filiale* und einem Entity $e_{2}$ des Typs *Stadt* bedeutet dass: Filiale $e_{1}$ in Stadt $e_{2}$ stationiert ist.

Eine konkrete Beziehung des Typs *in* zwischen einem Entity $e_{1}$ des Typs *Einkauf* und einem Entity $e_{2}$ des Typs *Filiale* bedeutet dass: Einkauf $e_{1}$ in Filiale $e_{2}$ getätigt wurde.

Eine konkrete Beziehung des Typs *bietet* zwischen einem Entity $e_{1}$ des Typs *Kette* und einem Entity $e_{2}$ des Typs *Produkt* bedeutet dass: Kette $e_{1}$ Produkt $e_{2}$ zum kauf anbietet.

Eine konkrete Beziehung des Typs *kauft* zwischen einem Entity $e_{1}$ des Typs *Einkauf* und einem Entity $e_{2}$ des Typs *Produkt* bedeutet dass: im Einkauf $e_{1}$ Produkt $e_{2}$ gekauft wurde.

Eine konkrete Beziehung des Typs *macht* zwischen einem Entity $e_{1}$ des Typs *Kunde* und einem Entity $e_{2}$ des Typs *Einkauf* bedeutet dass: Kunde $e_{1}$ den Einkauf $e_{2}$ gemacht/getätigt hat.

## Aufgabe 1.2 Relationenschemata

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
gehört_zu = in Filiale
ist_in = in Filiale
bietet = ({***KID: Zahl, PID: Zahl***})
kauft = ({***EID: Zahl, PID: Zahl***, Anzahl: Zahl})
macht = in Einkauf
in = in Einkauf