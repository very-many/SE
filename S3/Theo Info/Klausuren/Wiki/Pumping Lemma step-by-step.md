# Zeigen dass nicht regulär
### 1️⃣ Verstehen der Aufgabe

- **Bestimme die Sprache** $L$, die du untersuchen sollst.
- Überlege dir, welche Eigenschaften der Sprache schwer für endliche Automaten darzustellen sind (z.B. **Klammerung**, **Anzahl-Balance**, etc.).

### 2️⃣ Indirekter Beweis (Widerspruchsbeweis)

- **Annahme:** $L$ ist regulär.
- **Folge:** Das Pumping-Lemma muss gelten.

### 3️⃣ Anwendung des Pumping-Lemmas

- Es existiert eine **Pumping-Länge** $p > 0$.
- Für jedes Wort $w \in L$ mit $|w| \geq p$ gilt:
    1. $w = xyz$ mit $|xy| \leq p$
    2. $|y| > 0$
    3. Für alle $i \geq 0$: $xy^i z \in L$

### 4️⃣ Wahl des passenden Wortes $w$

- Wähle ein Wort $w \in L$, das die kritischen Eigenschaften der Sprache hervorhebt.
- Achte darauf, dass $|w| \geq p$ gilt.

### 5️⃣ Zerlegung des Wortes in $xyz$

- Da $|xy| \leq p$, ist $y$ oft in einem "einfachen" Teil des Wortes (z.B. nur Nullen, Klammern, etc.).
- Stelle sicher, dass $|y| > 0$.

### 6️⃣ Pumpen des Wortes

- Betrachte $w' = xy^i z$ für $i = 0, 2$.
- Analysiere, ob das neue Wort **noch in der Sprache liegt**.

### 7️⃣ Widerspruch finden

- Falls $w' \notin L$ → **Widerspruch** zum Pumping-Lemma.
- Also war die Annahme falsch: $L$ ist **nicht regulär**.

### 8️⃣ Fazit

- _Formuliere das_ ****_Endergebnis_**** _klar:_
$$\boxed{L\text{ ist nicht regulär}}$$
# Zeigen dass nicht kontextfrei
### 🚀 1️⃣ Verstehen des Kontexts

- **Bestimme die Sprache** $L$, von der du zeigen möchtest, dass sie **nicht kontextfrei** ist.
- Typische Eigenschaften von nicht-kontextfreien Sprachen:
    - **Mehrfaches Balancieren** (z.B. gleiche Anzahl von drei verschiedenen Symbolen)
    - **Abhängigkeiten in beiden Richtungen**

### ⚡ 2️⃣ Annahme (Widerspruchsbeweis)

- **Annahme:** $L$ ist kontextfrei.
- **Folge:** Das **Pumping-Lemma für kontextfreie Sprachen** muss gelten.

### 🔁 3️⃣ Pumping-Lemma für kontextfreie Sprachen

Es existiert eine **Pumping-Länge** $p > 0$, sodass jedes Wort $w \in L$ mit $|w| \geq p$ so zerlegt werden kann:

mit den Bedingungen:
1. $|vxy| \leq p$
2. $|vy| > 0$
3. Für alle $i \geq 0$ gilt: $uv^i x y^i z \in L$

### 🧩 4️⃣ Wahl des Wortes

- Wähle ein Wort $w \in L$, das **kritische Abhängigkeiten** zeigt.
- Das Wort sollte **lang genug** sein ($|w| \geq p$).

### 🚀 5️⃣ Zerlegung und Analyse

- Zerlege $w$ in $uvxyz$, wobei:
    - $|vxy| \leq p$
    - $|vy| > 0$
- Betrachte die "gepumpten" Varianten:

### ⚠️ 6️⃣ Widerspruch finden

- Zeige, dass für ein bestimmtes $i$ das Wort $w'$ **nicht mehr in der Sprache** liegt.
- Typische Widersprüche:
    - Ungleichgewicht von Symbolen
    - Verletzung von Strukturregeln der Sprache

### ✅ 7️⃣ Fazit

Falls ein Widerspruch auftritt:

Der Schlüssel liegt darin zu erkennen, dass **kontextfreie Grammatiken** keine komplexen Abhängigkeiten zwischen mehreren verschiedenen Bereichen eines Wortes handhaben können.