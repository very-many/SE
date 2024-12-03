**a)**
``` sql
SELECT 
    B.NName AS Benutzername,
    B.Benutzer_Nr AS BenutzerID,
    MAX(BE.Bestelldatum) AS LetzteBestellung,
    COUNT(DISTINCT BE.Aufsatz_Id) AS ZahlBestellterArtikel,
    COUNT(BE.Bestelldatum) AS ZahlBestellungen
FROM 
    ggr_kop_Benutzer B
LEFT JOIN 
    ggr_kop_bestellt BE ON B.Benutzer_Nr = BE.Benutzer_Nr
GROUP BY 
    B.Benutzer_Nr, B.NName
ORDER BY 
    LetzteBestellung DESC, B.NName ASC;
```

**b)**
``` sql
SELECT 
    B.NName AS Benutzername,
    B.Benutzer_Nr AS BenutzerID
FROM 
    ggr_kop_Benutzer B
JOIN 
    ggr_kop_Adresse A1 ON B.Benutzer_Nr = A1.Benutzer_Nr AND A1.Adr_Typ = 'Privat'
JOIN 
    ggr_kop_Adresse A2 ON B.Benutzer_Nr = A2.Benutzer_Nr AND A2.Adr_Typ = 'Geschäft'
WHERE 
    A1.Ort = A2.Ort;
```

**c)**
``` sql
SELECT 
    B.NName AS Benutzername,
    COALESCE(
        CONCAT(A1.Str, ' ', A1.HausNr, ', ', A1.Plz, ' ', A1.Ort),
        CONCAT(A2.Str, ' ', A2.HausNr, ', ', A2.Plz, ' ', A2.Ort),
        '') AS Adresse
FROM 
    ggr_kop_Benutzer B
LEFT JOIN 
    ggr_kop_Adresse A1 ON B.Benutzer_Nr = A1.Benutzer_Nr AND A1.Adr_Typ = 'Privat'
LEFT JOIN 
    ggr_kop_Adresse A2 ON B.Benutzer_Nr = A2.Benutzer_Nr AND A2.Adr_Typ = 'Geschäft';
```

**d)**
``` sql
SELECT 
    B.Benutzer_Nr AS BenutzerID,
    B.NName AS Benutzername,
    COUNT(DISTINCT BE.Aufsatz_Id) AS VerschiedeneArtikel
FROM 
    ggr_kop_Benutzer B
JOIN 
    ggr_kop_bestellt BE ON B.Benutzer_Nr = BE.Benutzer_Nr
GROUP BY 
    B.Benutzer_Nr, B.NName
ORDER BY 
    VerschiedeneArtikel DESC
LIMIT 1;
```

**e)**
```sql
SELECT 
    A.Autor_Id,
    A.AName AS Autorname
FROM 
    ggr_kop_Autor A
LEFT JOIN 
    ggr_kop_Aufsatz AU ON A.Autor_Id = AU.Autor_Id
LEFT JOIN 
    ggr_kop_bestellt BE ON AU.Aufsatz_Id = BE.Aufsatz_Id AND YEAR(BE.Bestelldatum) = 2009
WHERE 
    BE.Aufsatz_Id IS NULL;
```

**f)**
```sql
SELECT 
    A.Autor_Id,
    A.AName AS Autorname,
    COUNT(BE.Benutzer_Nr) AS Gesamtbestellungen
FROM 
    ggr_kop_Autor A
JOIN 
    ggr_kop_Aufsatz AU ON A.Autor_Id = AU.Autor_Id
JOIN 
    ggr_kop_bestellt BE ON AU.Aufsatz_Id = BE.Aufsatz_Id
GROUP BY 
    A.Autor_Id, A.AName
HAVING 
    Gesamtbestellungen >= 2
ORDER BY 
    Gesamtbestellungen DESC;
```

**g)**
```sql
SELECT 
    SUM(BE.Anzahl_Kopien) AS GesamtKopien,
    SUM(AU.bis_Seite - AU.von_Seite + 1) AS GesamtSeiten
FROM 
    ggr_kop_Aufsatz AU
JOIN 
    ggr_kop_bestellt BE ON AU.Aufsatz_Id = BE.Aufsatz_Id
LEFT JOIN 
    ggr_kop_Zeitschrift Z ON AU.Zeitschriften_Id = Z.Zeitschriften_Id
WHERE 
    AU.Titel LIKE '%Datenbank%' OR AU.Titel LIKE '%Database%'
    OR Z.ZName LIKE '%Datenbank%' OR Z.ZName LIKE '%Database%';
```

