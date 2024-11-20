## Tabellen Erstellen
``` SQL
CREATE TABLE JTh_Benutzer (
    Benutzer_Nr INT PRIMARY KEY,
    VName VARCHAR(50),
    NName VARCHAR(50)
);

CREATE TABLE JTh_Adresse (
    Benutzer_Nr INT,
    Plz CHAR(5),
    Ort VARCHAR(100),
    Str VARCHAR(100),
    HausNr VARCHAR(10),
    Adr_Typ VARCHAR(20),
    PRIMARY KEY (Benutzer_Nr, Adr_Typ),
    FOREIGN KEY (Benutzer_Nr) REFERENCES JTh_Benutzer(Benutzer_Nr)
);

CREATE TABLE JTh_Aufsatz (
    Aufsatz_Id INT PRIMARY KEY,
    Titel VARCHAR(200),
    Zeitschriften_Id INT,
    Jahrgang INT,
    von_Seite INT,
    bis_Seite INT,
    Autor_Id INT,
    FOREIGN KEY (Zeitschriften_Id) REFERENCES JMu_Zeitschrift(Zeitschriften_Id),
    FOREIGN KEY (Autor_Id) REFERENCES JTh_Autor(Autor_Id)
);

CREATE TABLE JTh_Autor (
    Autor_Id INT PRIMARY KEY,
    AName VARCHAR(100)
);

CREATE TABLE JTh_Zeitschrift (
    Zeitschriften_Id INT PRIMARY KEY,
    ZName VARCHAR(200)
);

CREATE TABLE JTh_bestellt (
    Benutzer_Nr INT,
    Aufsatz_Id INT,
    Bestelldatum DATE,
    PRIMARY KEY (Benutzer_Nr, Aufsatz_Id, Bestelldatum),
    FOREIGN KEY (Benutzer_Nr) REFERENCES JTh_Benutzer(Benutzer_Nr),
    FOREIGN KEY (Aufsatz_Id) REFERENCES JTh_Aufsatz(Aufsatz_Id)
);
```

## Tabellen Füllen
``` SQL
INSERT INTO JTh_Benutzer (Benutzer_Nr, VName, NName)
VALUES
(1, 'Anna', 'Müller'),
(2, 'Peter', 'Schmidt'),
(3, 'Maria', 'Weber');

INSERT INTO JTh_Adresse (Benutzer_Nr, Plz, Ort, Str, HausNr, Adr_Typ)
VALUES
(1, '10115', 'Berlin', 'Hauptstr.', '12', 'Privat'),
(1, '10115', 'Berlin', 'Nebenstr.', '5', 'Büro'),
(2, '80331', 'München', 'Ringstr.', '7', 'Privat');

INSERT INTO JTh_Autor (Autor_Id, AName)
VALUES
(1, 'Max Mustermann'),
(2, 'Erika Musterfrau'),
(3, 'Hans Beispiel');

INSERT INTO JTh_Zeitschrift (Zeitschriften_Id, ZName)
VALUES
(1, 'Nature'),
(2, 'Science'),
(3, 'Tech Monthly');

INSERT INTO JTh_Aufsatz (Aufsatz_Id, Titel, Zeitschriften_Id, Jahrgang, von_Seite, bis_Seite, Autor_Id)
VALUES
(1, 'Quantum Physics', 1, 2023, 1, 15, 1),
(2, 'Machine Learning Advances', 2, 2022, 20, 45, 2),
(3, 'Blockchain Revolution', 3, 2023, 50, 70, 3);

INSERT INTO JTh_bestellt (Benutzer_Nr, Aufsatz_Id, Bestelldatum)
VALUES
(1, 1, '2024-01-15'),
(2, 2, '2024-01-16'),
(3, 3, '2024-01-17');

```
