# Aufgabe 1
>Zeichnen Sie ein Blockschaltbild einer einfachen Von-Neumann-Rechnerarchitektur bestehend aus CPU, Hauptspeicher, Massenspeicher und Bussystemen. Benennen Sie alle Komponenten. Erklären Sie Memory-Mapped Files.

![[assets/Pasted image 20240316180708.png]]
![[von-neumann.bSXLkpZL.jpg]]

# Aufgabe 2
>Betriebssysteme steuern und verwalten Betriebsmittel. Nennen Sie drei Betriebsmittel.

- Prozessor
- Speicher
- Threads
- Bildschirm
- Drucker
- ?!?!?!

# Aufgabe 3
>Zeichnen Sie das Prozesszustandsdiagramm von UNIX. Welcher Zustand ist besonders auffällig? Erklären Sie Sinn und Zweck dieses auffälligen Zustands.

![[Pasted image 20250113125220.png]]
Ein Zombie-Prozess ist ein Prozess in Unix-ähnlichen Betriebssystemen, der beendet wurde, aber dessen Exit-Status noch nicht vom übergeordneten Prozess abgeholt wurde. Der Zombie-Prozess nimmt noch Systemressourcen in Anspruch, aber er führt keine Aktivitäten mehr aus, da er bereits beendet wurde.

Zweck?

# Aufgabe 4
>In einem Rechenzentrum sind 2 Tapes, 2 Plotter, 2 Drucker und 1 3D-Drucker zur gemeinsamen Nutzung freigegeben: E = (2 2 2 1). Es gebe 5 Benutzerprozesse, die bereits Ressourcen nutzen und auch noch weitere Ressourcen belegen wollen. Führen Sie den aus der Vorlesung bekannten Algorithmus zur Verklemmungserkennung durch.

>Die Belegungsmatrix B und die Wünschematrix C sind wie folgt:

$$\begin{align*}
B=\begin{pmatrix}0 & 1&1&0 \\ 1&0&0&0 \\ 0&0&0&0 \\ 1&1&0&0 \\ 0&0&1&0\end{pmatrix} & & C=\begin{pmatrix}1&0&0&0\\
0&1&0&0\\
0&0&0&1\\
0&0&0&1\\
1&0&0&0\end{pmatrix}
\end{align*}$$

| **B** | Tapes | Plotter | Drucker | 3D-Drucker |
| ----- | ----- | ------- | ------- | ---------- |
| P1    | 0     | 1       | 1       | 0          |
| P2    | 1     | 0       | 0       | 0          |
| P3    | 0     | 0       | 0       | 0          |
| P4    | 1     | 1       | 0       | 0          |
| P5    | 0     | 0       | 1       | 0          |

| **B** | 2   | 2   | 2   | 0   |
| ----- | --- | --- | --- | --- |

| **E** | 2   | 2   | 2   | 1   |
| ----- | --- | --- | --- | --- |

| **E - B -> A** | 0   | 0   | 0   | 1   |
| -------------- | --- | --- | --- | --- |

Jetzt die Rechnungen:

| A     | 0   | 0   | 0   | 1   |
| ----- | --- | --- | --- | --- |
| C(P4) | 0   | 0   | 0   | 1   |
| B4    | 1   | 1   | 0   | 0   |

| A     | 1   | 1   | 0   | 1   |
| ----- | --- | --- | --- | --- |
| C(P3) | 0   | 0   | 0   | 1   |
| B3    | 0   | 0   | 0   | 0   |

| A     | 1   | 1   | 0   | 1   |
| ----- | --- | --- | --- | --- |
| C(P5) | 1   | 0   | 0   | 0   |
| B5    | 0   | 0   | 1   | 0   |

| A     | 1   | 1   | 1   | 1   |
| ----- | --- | --- | --- | --- |
| C(P2) | 0   | 1   | 0   | 0   |
| B2    | 1   | 0   | 0   | 0   |

| A     | 2   | 1   | 1   | 1   |
| ----- | --- | --- | --- | --- |
| C(P1) | 1   | 0   | 0   | 0   |
| B1    | 0   | 1   | 1   | 0   |

| **->A** | 2   | 2   | 2   | 1   |
| ------- | --- | --- | --- | --- |
**-> Keine Verklemmung**

# Aufgabe 4
>Wir hatten uns u.a. die Verfahren „First Fit“ und „Worst Fit“ für die Zuordnung von Hauptspeicher an Prozesse angesehen. Erklären Sie diese Verfahren. Zeichnen Sie die Ergebnisse beider Verfahren direkt in die u.a. Grafiken (jeweils ab der 2ten Zeile) für Start A: 18; Start B: 4; Start C: 4; Ende B; Start D: 5; Start E: 12 ein. Hinweis: Die z.Z. bereits belegten Speicherblöcke haben alle die Größe 1 (graue Felder).

**First Fit**
Erklärung

|             | 10    | 4   | 20  | 18  | 7   | 9   | 12  | 5   |
| ----------- | ----- | --- | --- | --- | --- | --- | --- | --- |
| Start A: 18 |       |     | A   |     |     |     |     |     |
| Start B: 4  | B     |     | A   |     |     |     |     |     |
| Start C: 4  | B + C |     | A   |     |     |     |     |     |
| Ende B      | C     |     | A   |     |     |     |     |     |
| Start D: 5  | C + D |     | A   |     |     |     |     |     |
| Start E: 12 | C + D |     | A   | E   |     |     |     |     |

**Worst Fit**
Erklärung

| Ereignis    | 10  | 4   | 20  | 18    | 7   | 9   | 12  | 5   |
| ----------- | --- | --- | --- | ----- | --- | --- | --- | --- |
| Start A: 18 |     |     | A   |       |     |     |     |     |
| Start B: 4  |     |     | A   | B + C |     |     |     |     |
| Start C: 4  |     |     | A   | B + C |     |     |     |     |
| Ende B      |     |     | A   | C     |     |     |     |     |
| Start D: 5  |     |     | A   | C + D |     |     |     |     |
| Start E: 12 |     |     | A   | C + D |     |     | E   |     |

# Aufgabe 6
>Führen Sie die Berechnungen für das Buddy-System mit folgenden Ereignissen durch: Start A: 212; Start B: 99; Start C: 62; Ende A; Start D: 128; Start E: 120; Ende B; Ende E; Start F: 256.

| Ereignis     | 512                               |
| ------------ | --------------------------------- |
| Start A: 212 | 256(A), 256                       |
| Start B: 99  | 256(A), 128(B), 128               |
| Start C: 62  | 256(A), 128(B), 64(C), 64         |
| Ende A       | 256, 128(B), 64(C), 64            |
| Start D: 128 | 128(D), 128, 128(B), 64(C), 64    |
| Start E: 120 | 128(D), 128(E), 128(B), 64(C), 64 |
| Ende B       | 128(D), 128(E), 128, 64(C), 64    |
| Ende E       | 128(D), 256, 64(C), 64            |
| Start F: 256 | 128(D), 256(F), 64(C), 64         |

