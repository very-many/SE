## **1 b)** Create Statements
```SQL
CREATE TABLE g03_Referent(
    RefID INTEGER PRIMARY KEY,
    Name VARCHAR (30) NOT NULL,
    VName VARCHAR (30) NOT NULL,
    EMail VARCHAR (50) NOT NULL
);

CREATE TABLE g03_ExtReferent(
    RefID INTEGER,
    FOREIGN KEY (RefID) REFERENCES g03_Referent(RefID) ON DELETE CASCADE,
    Fax VARCHAR (30) NOT NULL,
    Tel VARCHAR (30) NOT NULL,
    Ort VARCHAR (30) NOT NULL,
    Plz VARCHAR (30) NOT NULL,
    Str VARCHAR (30) NOT NULL,
    PRIMARY KEY (RefID)
);

CREATE TABLE g03_IntReferent(
    RefID INTEGER,
    FOREIGN KEY (RefID) REFERENCES g03_Referent(RefID) ON DELETE CASCADE,
    Nebenstelle VARCHAR (30),
    Zimmer VARCHAR (30),
    PRIMARY KEY (RefID)
);

CREATE TABLE g03_SeminarThema(
    Verantwortlicher INTEGER,
    Vortragender INTEGER,
    FOREIGN KEY (Verantwortlicher) REFERENCES g03_Referent(RefID),
    FOREIGN KEY (Vortragender) REFERENCES g03_Referent(RefID),
    STID INTEGER PRIMARY KEY,
    Beschreibung VARCHAR (300),
    MaxTZahl INTEGER,
    MinTZahl INTEGER,
    Preis FLOAT NOT NULL,
    Titel VARCHAR (30) NOT NULL,
    UEinheiten INTEGER NOT NULL
);

CREATE TABLE g03_Seminar(
    STID INTEGER,
    FOREIGN KEY (STID) REFERENCES g03_SeminarThema(STID),
    SID INTEGER PRIMARY KEY,
    Ort VARCHAR (30)
);

CREATE TABLE g03_Termin(
    SID INTEGER,
    FOREIGN KEY (SID) REFERENCES g03_Seminar(SID) ON DELETE CASCADE,
    TID INTEGER PRIMARY KEY,
    Von TIME,
    Bis TIME,
    Datum DATE
);

CREATE TABLE g03_Kunde(
    KID INTEGER PRIMARY KEY,
    Name VARCHAR (30) NOT NULL,
    VName VARCHAR (30) NOT NULL,
    EMail VARCHAR (50) NOT NULL,
    Fax VARCHAR (30) NOT NULL,
    Tel VARCHAR (30) NOT NULL,
    Ort VARCHAR (30) NOT NULL,
    Plz VARCHAR (30) NOT NULL,
    Str VARCHAR (30) NOT NULL
);

CREATE TABLE g03_Buchung(
    SID INTEGER,
    KID INTEGER,
    FOREIGN KEY (SID) REFERENCES g03_Seminar(SID),
    FOREIGN KEY (KID) REFERENCES g03_Kunde(KID),
    PRIMARY KEY (SID, KID),
    Datum DATE,
    Rabatt FLOAT,
    Zustand VARCHAR(9) NOT NULL,
	CONSTRAINT chk_Zustand CHECK (Zustand IN ('offen', 'berechnet', 'bezahlt', 'storniert'))
);

CREATE TABLE g03_Warteschlange(
    SID INTEGER,
    KID INTEGER,
    FOREIGN KEY (SID) REFERENCES g03_Seminar(SID),
    FOREIGN KEY (KID) REFERENCES g03_Kunde(KID),
    PRIMARY KEY (SID, KID),
    Position INTEGER
);
```

## **2** Insert Statements
```SQL
INSERT INTO g03_Referent (RefID, Name, VName, EMail) VALUES 
(1, 'Müller', 'Hans', 'hans.mueller@example.com'),
(2, 'Schmidt', 'Anna', 'anna.schmidt@example.com'),
(3, 'Fischer', 'Peter', 'peter.fischer@example.com'),
(4, 'Weber', 'Sophie', 'sophie.weber@example.com');

INSERT INTO g03_ExtReferent (RefID, Fax, Tel, Ort, Plz, Str) VALUES 
(1, '123456789', '987654321', 'Stuttgart', '70173', 'Königstr. 1'),
(2, '223456789', '887654321', 'Karlsruhe', '76131', 'Kaiserstr. 2');

INSERT INTO g03_IntReferent (RefID, Nebenstelle, Zimmer) VALUES 
(3, '1234', '101'),
(4, '5678', '202');

INSERT INTO g03_SeminarThema (Verantwortlicher, Vortragender, STID, Beschreibung, MaxTZahl, MinTZahl, Preis, Titel, UEinheiten) VALUES 
(1, 1, 1, 'Einführung in die Programmierung', 20, 5, 300.0, 'Programmierung 101', 10),
(2, 2, 2, 'Fortgeschrittene Datenbanktechniken', 15, 3, 500.0, 'Datenbanken', 15),
(3, 3, 3, 'Projektmanagement Basics', 25, 7, 400.0, 'Projektmanagement', 12);

INSERT INTO g03_Seminar (STID, SID, Ort) VALUES 
(1, 1, 'Stuttgart'),
(1, 2, 'Karlsruhe'),
(2, 3, 'Mannheim'),
(2, 4, 'Freiburg'),
(3, 5, 'Heidelberg');

INSERT INTO g03_Termin (SID, TID, Von, Bis, Datum) VALUES 
(1, 1, '09:00:00', '12:00:00', '2024-12-01'),
(2, 2, '13:00:00', '16:00:00', '2024-12-02'),
(3, 3, '10:00:00', '15:00:00', '2024-12-03'),
(4, 4, '09:00:00', '12:00:00', '2024-12-04'),
(4, 5, '13:00:00', '16:00:00', '2024-12-04'),
(5, 6, '10:00:00', '14:00:00', '2024-12-05'),
(5, 7, '15:00:00', '18:00:00', '2024-12-05');

INSERT INTO g03_Kunde (KID, Name, VName, EMail, Fax, Tel, Ort, Plz, Str) VALUES 
(1, 'Meyer', 'Tom', 'tom.meyer@example.com', '123456789', '987654321', 'Stuttgart', '70173', 'Königstr. 1'),
(2, 'Bauer', 'Lisa', 'lisa.bauer@example.com', '223456789', '887654321', 'Karlsruhe', '76131', 'Kaiserstr. 2'),
(3, 'Wagner', 'Marie', 'marie.wagner@example.com', '323456789', '787654321', 'Mannheim', '68161', 'Friedrichstr. 3'),
(4, 'Becker', 'Paul', 'paul.becker@example.com', '423456789', '687654321', 'Freiburg', '79098', 'Berliner Allee 4'),
(5, 'Hoffmann', 'Emma', 'emma.hoffmann@example.com', '523456789', '587654321', 'Heidelberg', '69115', 'Bismarckstr. 5');

INSERT INTO g03_Buchung (SID, KID, Datum, Rabatt, Zustand) VALUES 
(1, 1, '2024-11-25', 10.0, 'offen'),
(2, 2, '2024-11-26', 0.0, 'bezahlt'),
(3, 3, '2024-11-27', 5.0, 'berechnet'),
(4, 4, '2024-11-28', 15.0, 'storniert'),
(5, 5, '2024-11-29', 20.0, 'bezahlt'),
(1, 2, '2024-11-30', 0.0, 'offen'),
(3, 4, '2024-12-01', 10.0, 'bezahlt'),
(4, 5, '2024-12-02', 5.0, 'berechnet'),
(5, 1, '2024-12-03', 15.0, 'storniert'),
(2, 3, '2024-12-04', 20.0, 'bezahlt');

INSERT INTO g03_Warteschlange (SID, KID, Position) VALUES 
(1, 3, 1),
(1, 4, 2),
(2, 5, 1);
```

# **X** Query
```SQL
SELECT COUNT(*) as total, COUNT(fax) as ext, COUNT(*)-COUNT(fax) as int
	FROM g03_Referent as a 
	LEFT JOIN g03_ExtReferent USING(RefID)


SELECT DISTINCT SID, COUNT(TID)
FROM g03_Seminar JOIN g03_Termin USING(SID)
GROUP BY SID
ORDER BY SID


SELECT DISTINCT SID, COUNT(SID)
FROM g03_Seminar JOIN g03_Buchung USING(SID)
WHERE zustand = 'bezahlt'
GROUP BY SID
ORDER BY SID


SELECT SID, COUNT(KID) as groesse_warteschlange
FROM g03_Seminar JOIN g03_Warteschlange USING(SID)
GROUP BY SID
HAVING COUNT(KID) >= All(
	SELECT COUNT(KID)
	FROM g03_Warteschlange
	GROUP BY KID)


SELECT RefID, COUNT(kid) as Verantw_Teilnehmer
FROM g03_Referent re LEFT JOIN g03_SeminarThema st ON (re.RefID = st.verantwortlicher)
	LEFT JOIN (g03_Seminar se JOIN g03_Buchung be ON se.SID = be.SID AND zustand = 'bezahlt') USING(STID)
GROUP BY RefID


SELECT RefID, SUM((1 - be.rabatt/100) * st.preis) as money
FROM g03_Referent re LEFT JOIN g03_SeminarThema st ON (re.RefID = st.verantwortlicher)
	LEFT JOIN (g03_Seminar se JOIN g03_Buchung be ON se.SID = be.SID AND zustand = 'bezahlt') USING(STID)
GROUP BY RefID
```