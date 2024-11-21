## Tabellen Erstellen
``` PostgreSQL
CREATE TABLE JTh_Benutzer (
    Benutzer_Nr SERIAL PRIMARY KEY,
    VName VARCHAR(50) NOT NULL,
    NName VARCHAR(50) NOT NULL
);

CREATE TABLE JTh_Adresse (
    Benutzer_Nr INT NOT NULL,
    Plz CHAR(5) NOT NULL,
    Ort VARCHAR(100) NOT NULL,
    Str VARCHAR(100) NOT NULL,
    HausNr VARCHAR(10) NOT NULL,
    Adr_Typ VARCHAR(20) NOT NULL,
    PRIMARY KEY (Benutzer_Nr, Adr_Typ),
    FOREIGN KEY (Benutzer_Nr) REFERENCES JTh_Benutzer(Benutzer_Nr) ON DELETE CASCADE
);

CREATE TABLE JTh_Aufsatz (
    Aufsatz_Id SERIAL PRIMARY KEY,
    Titel VARCHAR(200) NOT NULL,
    Zeitschriften_Id INT NOT NULL,
    Jahrgang INT NOT NULL,
    von_Seite INT NOT NULL,
    bis_Seite INT NOT NULL,
    Autor_Id INT NOT NULL,
    FOREIGN KEY (Zeitschriften_Id) REFERENCES JMu_Zeitschrift(Zeitschriften_Id) ON DELETE CASCADE,
    FOREIGN KEY (Autor_Id) REFERENCES JTh_Autor(Autor_Id) ON DELETE CASCADE
);

CREATE TABLE JTh_Autor (
    Autor_Id INT PRIMARY KEY,
    AName VARCHAR(100) NOT NULL
);

CREATE TABLE JTh_Zeitschrift (
    Zeitschriften_Id INT PRIMARY KEY,
    ZName VARCHAR(200) NOT NULL
);

CREATE TABLE JTh_bestellt (
    Benutzer_Nr INT NOT NULL,
    Aufsatz_Id INT NOT NULL,
    Bestelldatum DATE NOT NULL,
    PRIMARY KEY (Benutzer_Nr, Aufsatz_Id, Bestelldatum),
    FOREIGN KEY (Benutzer_Nr) REFERENCES JTh_Benutzer(Benutzer_Nr) ON DELETE CASCADE,
    FOREIGN KEY (Aufsatz_Id) REFERENCES JTh_Aufsatz(Aufsatz_Id) ON DELETE CASCADE
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
