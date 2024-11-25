## 1
**a)**
``` sql
SELECT *
FROM ggr_kop_Benutzer
INNER JOIN ggr_kop_bestellt USING (Benutzer_Nr)
ORDER BY Benutzer_Nr, Aufsatz_ID;
```

**b)**
``` sql
SELECT *
FROM ggr_kop_Benutzer
INNER JOIN ggr_kop_bestellt
ON ggr_kop_Benutzer.Benutzer_Nr = ggr_kop_bestellt.Benutzer_Nr
ORDER BY ggr_kop_Benutzer.Benutzer_Nr, ggr_kop_bestellt.Aufsatz_ID;
```

**c)**
``` sql
SELECT *
FROM ggr_kop_Benutzer
LEFT JOIN ggr_kop_bestellt USING (Benutzer_Nr)
ORDER BY Benutzer_Nr, Aufsatz_ID;
```

**d)**
``` sql
SELECT *
FROM ggr_kop_Benutzer
LEFT JOIN ggr_kop_bestellt
ON ggr_kop_Benutzer.Benutzer_Nr = ggr_kop_bestellt.Benutzer_Nr
ORDER BY ggr_kop_Benutzer.Benutzer_Nr, ggr_kop_bestellt.Aufsatz_ID;
```

## 2
**a)**
``` sql
SELECT *
FROM ggr_kop_Benutzer
LEFT JOIN ggr_kop_bestellt
ON ggr_kop_Benutzer.Benutzer_Nr = ggr_kop_bestellt.Benutzer_Nr
WHERE EXTRACT(YEAR FROM ggr_kop_bestellt.Bestelldatum) >= 2010
ORDER BY ggr_kop_Benutzer.Benutzer_Nr, ggr_kop_bestellt.Aufsatz_ID;
```

**b)**
``` sql
SELECT *
FROM ggr_kop_Benutzer
LEFT JOIN ggr_kop_bestellt
ON ggr_kop_Benutzer.Benutzer_Nr = ggr_kop_bestellt.Benutzer_Nr
AND EXTRACT(YEAR FROM ggr_kop_bestellt.Bestelldatum) >= 2010
ORDER BY ggr_kop_Benutzer.Benutzer_Nr, ggr_kop_bestellt.Aufsatz_ID;
```

**c)**
- **a)** Mit `WHERE` werden alle Benutzer ohne Bestellungen ab 2010 vollständig aus dem Ergebnis ausgeschlossen.
- **b)** Mit der Bedingung in der `ON`-Klausel bleiben alle Benutzer erhalten, auch wenn sie keine Bestellungen ab 2010 haben. In solchen Fällen sind die entsprechenden Spalten aus der Tabelle `ggr_kop_bestellt` `NULL`.