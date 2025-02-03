## Beweis: Die Sprache $B$ ist nicht regulär

Wir wollen mit dem **Pumping-Lemma für reguläre Sprachen** zeigen, dass die Sprache $B$ der wohlgeformten booleschen Formeln nicht regulär ist.

---

### 🚀 1. Definition der Sprache

$$B = \{ \text{wohlgeformte boolesche Formeln über } \{ \wedge, \vee, \neg, (, ), a, b, c \} \}$$

**Beispiele:**

- ✅ In $B$: $a \wedge b$, $b \vee \neg(\neg a \wedge b)$
- ❌ Nicht in $B$: $a)b\vee$, $\wedge b \vee c \neg$

Wohlgeformte Formeln müssen:

- **korrekt geklammert** sein,
- **sinnvolle Operatoranwendungen** besitzen,
- Variablen und Operatoren in der richtigen Reihenfolge verwenden.

---

### ⚡ 2. Annahme (indirekter Beweis)

Wir nehmen **widerlegungsweise** an, dass $B$ **regulär** ist.

Dann gilt das **Pumping-Lemma**:  
Es existiert eine **Pumping-Länge** $p > 0$, sodass jedes Wort $w \in B$ mit $|w| \geq p$ in drei Teile zerlegt werden kann:

$$w=xyz$$

mit den Bedingungen:

1. $|xy| \leq p$
2. $|y| > 0$
3. Für alle $i \geq 0$ gilt: $xy^i z \in B$

---

### 🧩 3. Wahl des Wortes

Wir wählen ein Wort $w \in B$, das viele Klammern enthält, da das **korrekte Klammern** eine Eigenschaft ist, die reguläre Sprachen **nicht gut** handhaben können.

**Geeignetes Wort:**

$w = (^{p} \ a \ \wedge \ b \ )^{p}$
$
Das ist:

$w = (((\dots((a \wedge b))))\dots)$

mit genau $p$ **öffnenden** und $p$ **schließenden** Klammern.  
✅ Das Wort ist **wohlgeformt** (korrekt geklammert).

---

### 🔁 4. Anwendung des Pumping-Lemmas

Wir zerlegen $w$ in $xyz$, sodass:

- $|xy| \leq p$  
    → Das bedeutet, dass $x$ und $y$ **nur aus öffnenden Klammern** bestehen, da die ersten $p$ Zeichen genau das sind.
- $|y| > 0$  
    → Also enthält $y$ mindestens **eine öffnende Klammer**: $y = (^\ell$ für ein $\ell \geq 1$.

Nun betrachten wir das "gepumpte" Wort:

$w' = xy^2 z$

Das bedeutet, wir **fügen zusätzliche öffnende Klammern hinzu**:

$w' = (^{p + \ell} \ a \ \wedge \ b \ )^{p}$

---

### ⚠️ 5. Überprüfung der Struktur

Jetzt haben wir:

- **$p + \ell$** öffnende Klammern
- Aber nur **$p$** schließende Klammern

**Folge:**

- **Ungleichgewicht der Klammern** → das Wort ist **nicht mehr wohlgeformt**!
- Das neue Wort $w'$ ist also **nicht mehr in $B$**.

---

### ❌ 6. Widerspruch

Das **Pumping-Lemma** besagt, dass alle "gepumpten" Varianten $xy^i z$ **in der Sprache bleiben** müssen.  
Aber wir haben ein Wort $w'$ gefunden, das **nicht in $B$** liegt.

Das ist ein **Widerspruch** zur Annahme, dass $B$ regulär ist.

---

### ✅ 7. Fazit

Da wir einen Widerspruch erhalten haben, folgt:

$$\boxed{B \text{ ist nicht regulär.}}$$

Der entscheidende Punkt ist, dass das **Balancieren von Klammern** eine Eigenschaft ist, die reguläre Sprachen nicht darstellen können. Dafür braucht man mindestens einen **Kellerautomaten** → also eine **kontextfreie Sprache**.