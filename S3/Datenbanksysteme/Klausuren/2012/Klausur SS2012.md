## Aufgabe 1.1 ERM

**Entitys:**
Kette = ({**KID: Zahl**, Name: Text})
Filiale = ({**FID: Zahl**, Straße: Text})
Stadt = ({**SID: Zahl**, Name: Text, Kategorie: {Kleinstadt, Mittelstadt, Großstadt, Metropole}})

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
IS-A-Produkt = (Lebensmittel x Produkt)
IS-A-Produkt = (Elektroartikel x Produkt)

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

Eine konkrete Beziehung des Typs *IS_A_Produkt* zwischen einem Entity $e_{1}$ des Typs *Lebensmittel* und einem Entity $e_{2}$ des Typs *Produkt* bedeutet dass: Ein Lebensmittel $e_{1}$ ein Produkt $e_{2}$ ist.

Eine konkrete Beziehung des Typs *IS_A_Produkt* zwischen einem Entity $e_{1}$ des Typs *Elektroartikel* und einem Entity $e_{2}$ des Typs *Produkt* bedeutet dass: Ein Elektroartikel $e_{1}$ ein Produkt $e_{2}$ ist.

Eine konkrete Beziehung des Typs *macht* zwischen einem Entity $e_{1}$ des Typs *Kunde* und einem Entity $e_{2}$ des Typs *Einkauf* bedeutet dass: Kunde $e_{1}$ den Einkauf $e_{2}$ gemacht/getätigt hat.

## Aufgabe 1.2 Relationenschemata

**Entitys:**
Kette = ({**KID: Zahl**, Name: Text})
Filiale = ({**FID: Zahl**, Straße: Text, *KID: Zahl*, *SID: Zahl*})
Stadt = ({**SID: Zahl**, Name: Text, Kategorie: {Kleinstadt, Mittelstadt, Großstadt, Metropole}})

Produkt = ({**PID: Zahl**, Bezeichnung: Text, Preis: FKZ})
Lebensmittel = ({***PID: Zahl***, MHD: Datum})
Elektroartikel = ({***PID: Zahl***, CE: Boolean, Prüfer: Text})

Kunde = ({**Code: Text**, Name: Text, Adresse: (plz: Text, str: Text, hnr: Text)})

Einkauf = ({**EID: Zahl**, Zeitpunkt: Datum, *FID: Zahl*, *Code: Text*})

**Beziehungen:**
gehört_zu = in Filiale
ist_in = in Filiale
bietet = ({***KID: Zahl, PID: Zahl***})
kauft = ({***EID: Zahl, PID: Zahl***, Anzahl: Zahl})
macht = in Einkauf
in = in Einkauf
IS-A-Produkt = in den spezifischen Produkttypen

**Fremdschlüssel-Abhängigkeiten:**
$Lebensmittel|_{PID} \subseteq Produkt|_{PID}$
$Elektroartikel|_{PID} \subseteq Produkt|_{PID}$
$bietet|_{PID} \subseteq Produkt|_{PID}$

## Aufgabe 2 SQL

In welchen Städten gibt es eine Filiale der Kette gut&günstig?
``` SQL
SELECT s.Name
FROM Filiale f
JOIN Kette k ON f.KID = k.KID
JOIN Stadt s ON f.SID = s.SID
WHERE k.Name = "gut&günstig";
```

Wie viele Filialen gibt es in Stuttgart?
``` SQL
SELECT COUNT(f.SID)
FROM Filiale f
JOIN Stadt s ON f.SID = s.SID
WHERE s.Name = "Stuttgart";
```

Wie viele Einkäufe enthielten ein Produkt, dessen Mindesthaltbarkeit zum Zeitpunkt des Einkaufs bereits abgelaufen war.
``` SQL
SELECT COUNT(e.EID)
FROM Einkauf e
JOIN kauft k ON e.EID = k.EID
JOIN Lebensmittel l ON k.PID = l.PID
WHERE l.MHD != NULL 
AND l.MHD < e.Zeitpunkt;
```

Erzeugen Sie eine Liste aller Einkäufe, die in einer bestimmten Filiale getätigt wurden. Geben Sie dabei für jeden Einkauf die Anzahl der gekauften Produkte und den Gesamtwert des Einkaufs an. Rabatte sollen nicht berücksichtigt werden.
```SQL
SELECT 
    E.EID AS EinkaufID,
    COUNT(K.PID) AS AnzahlProdukte,
    SUM(K.Anzahl * P.Preis) AS Gesamtwert
FROM Einkauf E
JOIN kauft K ON E.EID = K.EID
JOIN Produkt P ON K.PID = P.PID
WHERE E.FID = <FID>
GROUP BY E.EID
ORDER BY E.EID;
```

Geben Sie Filialen an, die Elektroartikel führen.
```SQL
SELECT F.FID
FROM Filiale F
JOIN bietet B ON F.KID = B.KID
JOIN Elektroartikel E ON E.PID = P.PID
```

Geben Sie Filialen an, die keine Elektroartikel führen.
```SQL
SELECT DISTINCT F.FID, F.Straße
FROM Filiale F
WHERE F.FID NOT IN (
    SELECT DISTINCT F1.FID
    FROM Filiale F1
    JOIN bietet B ON F1.KID = B.KID
    JOIN Elektroartikel E ON B.PID = E.PID
);

-- oder:

SELECT DISTINCT F.FID, F.Straße
FROM Filiale F
LEFT JOIN bietet B ON F.KID = B.KID
LEFT JOIN Elektroartikel E ON B.PID = E.PID
WHERE E.PID IS NULL;
```


## Aufgabe 3 DB-Theorie

Gehen Sie vom Relationenschema $U = (\{a, b, c, d, e, g, h\}, F)$ mit der FD-Menge $F = { (a, b, g → d), (b, c → d, e, g), (c, e → b, g), (g → a) }$ aus.

**1)**
Bestimmen Sie alle Schlüssel für U
> $h$ taucht garnicht auf?! somit kein Schlüssel?!

-  $c$ muss teil vom Schlüssel sein (Taucht nur links auf)
- $a,b,e,f,g$ können Teil vom Schlüssel sein (Tauchen links und rechts auf) 
- $d$ kann nicht teil vom Schlüssel sein (Taucht nur rechts auf)

Testen der einelementigen Mengen:
-
Testen der zweielementigen Mengen:
$b, c = a,b,c,d,e,g$ !!


