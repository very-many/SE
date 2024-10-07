## %%12.03%%
**BUCH:** Stochastik für Einsteiger - Norbert Henze (?) - Kap. 7, 8, 9 (KOMBINATORIK)

***
# Diskrete Wahrscheinlichkeitsräume

Wahrscheinlichkeit == W'keit (Weil kürzer)

**Bsp. Lotto "6 aus 49"**

49 Bälle. Bälle mit Zahlen 1 bis 49. Wenn man 3 Zahlen richtig hat, gewinnt man - mehr als 3 gewinnt mehr.

Beim Lotto "6 aus 49" werden aus der Menge der Zahlen {1, 2, 3, ..., 49} sechs Zahlen zufällig gezogen.
Die Reihenfolge in der die zahlen gezogen werden spielt dabei keine Rolle.
Beispielsweise liefert die Ziehung 3, 13, 27, 4, 25, 33 dasselbe Ergebnis wie die Ziehung 25, 13, 4, 3, 33, 27.

- Die Ziehung der Lottozahlen ist ein *Zufallsexperiment*.
- Das Ergebnis einer Ziehung nennt man *Elementarereignis*.
- Die Menge aller Elementarereignisse bezeichnet man als *Ereignisraum* (Symbolisch $\Omega$).
$$\Omega:\{w\leq\{1,2,3,\ldots,49\}\text{ | }||{w}||=6\}$$
%%( ||w|| steht für die Mächtigkeit von w)%%


Es gilt:
$$||\Omega||=\left.\left(\begin{matrix}49\\6\end{matrix}\right.\right)=\frac{49!}{6!(49-6)!}=13983816$$
Für ein $w\in\Omega$ bezeichnet *Pr[w] die W'keit, dass w das Ergebnis einer Ziehung ist*.

**Annahme:** Die Elementarereignisse sind *gleichverteilt (Laplace)*, d.h. jedes Elementarereignis hat dieselbe W'keit gezogen zu werden. 
Formal:
$$\text{F\"ur alle }w\in\Omega=Pr[w]=\frac{1}{||\Omega||}=\frac{1}{13983816}$$

## %%14.03%%
## Def. 1.1

## Def. 1.2

## Kleine dumme Begriffe
- Sicheres Ereignis:
	- $\Omega$ -> sicheres Ereignis (100% Wahrscheinlich)
- Unmögliches Ereignis:
	- $\varnothing$ -> unmögliches Ereignis (0% Wahrscheinlich)
## Bsp. Würfel
Das Werfen eines fairen 6-seitigen Würfels ist ein Zufallsexperiment (Wenn *fair*, dann Laplace, meistens).
- $\Omega=\{1,2,3,4,5,6\}$
- $\text{F\"ur alle: }w\in\Omega:Pr[w]=\frac{1}{||\Omega||}=\frac{1}{6}$

Gerade Augenzahl == Ereignis G = {2, 4, 6} $$Pr[G]=\sum\limits_{w\in G}{}{Pr[w]}=||G||\cdot\frac{1}{6}=\frac{3}{6}=\frac{1}{2}$$
## Bsp. Prozessanalyse
Betrachte einen Computer, dessen Prozessor I/O-Operationen oder Rechenoperationen ausführen kann.
Die Programme, die auf dem Computer ablaufen sind entweder rechenlastig oder datenlastig.

Die W'keit, dass ein datenlastiger Prozess eine Rechenoperation ausführt, ist gleich 0,25. Bei einem rechenlastigen Prozess beträgt sie 0,8.
Der Aktuell laufende Prozess ist mit einer W'keit von 0,7 ein datenlastiger Prozess.

**Frage:** Wie hoch ist die W'keit, dass die nächste ausgeführte Operation eine I/O-Operation ist?
$$\Omega \{rl,dl\} x \{io, cpu\}$$
[[Draw - Baumdiagramm]]

| w         | Pr[w]                |
| --------- | -------------------- |
| (rl, cpu) | $0,3\cdot0,8=0,24$   |
| (rl, io)  | $0,3\cdot0,2=0,06$   |
| (dl, cpu) | $0,7\cdot0,25=0,175$ |
| (dl, io)  | $0,7\cdot0,75=0,525$ |
rl: $\sum\limits=0,3$
dl: $\sum\limits=0,7$

Ereignis A= {(rl,io), (dl,io)} $$\begin{align} 
Pr[A]&=Pr[(rl, io)]+Pr[(dl, io)] \\
&=0,3\cdot0,2+0,7\cdot0,75 \\
&=0,06+0,525 \\
&=0,585
\end{align}$$
- *Bezeichnungen*
	- rl == rechenlastig
	- dl == datenlastig
	- io == I/O-Operationen
	- cpu == Rechenoperationen

## Bsp. Datenübertragung

**Szenario:**
S -Datenübertragung-> E
S <-ok/fehlerhaft- E

Der Rechner S sendet das Datenpaket P an den Rechner E.
Das Paket wird mit der Wahrscheinlichkeit p($0<p<1$), korrekt übertragen. Die Übertragung wird so lange wiederholt, bis das Paket korrekt von E empfangen wurde.

Sei $k\in \mathbb{N}$
**Frage:** Mit welcher W'keit sind genau k Übertragungen erforderlich?
*Annahme:* Die Übertragungen sind unabhängig.
*Modellierung:* 
- $\Omega=\{1,2,3,\ldots\}=\ \mathbb{N}$
Es gilt: $$Pr[k]=(1-p)^{k-1}\cdot p$$
- Bemerkungen
	- $(1-p)$ für $k-1$ fehlerhafte Übertragungen
	- das letzte $p$ für eine (und die letzte) korrekte Übertragung
---
### Bsp:
k=5: 
$$\begin{align}
&F,F,F,F,K \\
&(1-p)\cdot(1-p)\cdot(1-p)\cdot(1-p)\cdot p
\end{align}$$

---

Zu Zeigen:
$$\begin{align}
\sum\limits_{k=1}^{\infty}Pr[k]&=1 \\
\sum\limits_{k=1}^{\infty}Pr[k]&=\sum\limits_{k=1}^{\infty}(1-p)^{k-1} \\
&=p\cdot\sum\limits_{k=1}^{\infty}(1-p)^{k-1} \\
&=p\cdot\sum\limits_{k=0}^{\infty}(1-p)^{k} \text{ bem. geo Reihe}\\
&=p\cdot\frac{1}{1-(1-p)} \\
&=p\cdot\frac{1}{p} \\
&=1
\end{align}$$
$$
\text{geo Reihe: }\sum\limits_{k=0}^{\infty}q^{i}=\frac{1}{1-q} \text{ falls |q| <1}
$$
### Bps:
$p = 0,75, q = 1-p = 0,25$
$$Pr[4]=0,25³\cdot0,75\approx 0,0117$$
--- 

## %%19.03%%

## Satz 2.1 Additionssatz
**Beweis:**
Seiten $A,B \subseteq \Omega$ mit $A\cap B=\emptyset$
$$Pr[A\cup B]=\sum\limits_{w\in A\cup B}$$
## Satz 2.2
## Satz 2.3 Siebformel
**Beweis:**
Seien $A,B\in \Omega$
[[Draw- A schnitt B]]
$$Pr[A\cup B] = Pr[A]+Pr[B]-Pr[A\cup B]$$
	Für $w \in A\cup B$ wurde $Pr[w]$ doppelt addiert

---
### Nicht Fertig, war irgendeine Frage die beantwortet wurde
$Pr[A]=A-(A\cap B)\cup (A\cap B)$
$Pr[B]=B-(A\cap B)\cup (A\cap B)$
*Additionssatz:*
$Pr[A\cap B] = Pr[A-(A\cap B)]+Pr[A\cap B]$
$= Pr[A]+Pr[B]-Pr[A\cap B]$
---

$A,B,C\in\Omega$
[[Draw - schnitt A, B, C]]
$$\begin{align}
Pr[A\cup B\cup C]=&Pr[A]+Pr[B]+Pr[C] \\
&-Pr[A\cap B] -Pr[A\cap C]-Pr[B\cap C]\\
&+Pr[A\cap B\cap C]
\end{align}$$
**Beispiel:**
*Anwendung dieser Formel:*
$$\begin{aligned}\textsf{Allgemein: Für }&\geq2\textsf{ Ereignisse }A_1,\ldots,A_n\textsf{ gilt:}\\&\quad Pr\left[A_1\cup\ldots\cup A_n\right]\\&=\sum_{S\subseteq\{1,...,n\}}(-1)^{\|S\|+1}Pr\left[\bigcap_{i\in\mathcal{S}}A_i\right]\end{aligned}$$

$A_1,A_2,A_3\subseteq\Omega$
$S\subseteq\{1,2,3\}$

| $S$         | $(-1)^{\|S\|+1}$ | $Pr[\bigcap_{i\subseteq S}A_i]$ |
| ----------- | ---------------- | ------------------------------- |
| $\emptyset$ | -1               | $Pr[\emptyset]$                 |
| {1}         | +1               | $Pr[A_1]$                       |
| {2}         | +1               | $Pr[A_2]$                       |
| {3}         | +1               | $Pr[A_3]$                       |
| {1,2}       | -1               | $Pr[A_1\cap A_2]$               |
| {2,3}       | -1               | $Pr[A_2\cap A_3]$               |
| {1,2,3}     | +1               | $Pr[A_{1}\cap A_{2}\cap A_{3}]$ |
[[Definitionen und Saetze.pdf]](Page 7)

**Beispiel:**
$\Omega={a,b,c,d,e,f,g}$

| w       | a    | b    | c    | d    | e    | f    | g    |     |
| ------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | --- |
| $Pr[w]$ | 17,5 | 13,4 | 13,8 | 12,0 | 15,2 | 17,2 | 10,9 | %   |
$A=\{a,c,d\}$ $B=\{a,b,c,e\}$ $C=\{a,d,e,g\}$

### Hier Rechnung zur direkten Berechnung einfügen...

*Anwendung der Siebformel:*
$$\begin{align}
Pr[A\cup B\cup C]=&Pr[A]+Pr[B]+Pr[C]\\
&- Pr[A\cap B]-Pr[A\cap C]-Pr[B\cap C] \\
&+ Pr[A\cap B\cap C]
\end{align}$$
$$\begin{align}
=&Pr[\{a,c,d\}]+Pr[\{a,b,c,e\}]+Pr[\{a,d,e, g\}]\\
&- Pr[\{a,c\}]-Pr[\{a,d\}]-Pr[\{a,e\}] \\
&+ Pr[\{a\}]
\end{align}$$$$\begin{align}
=&0,433+0,599+0,556 \\
&- 0,313-0,295-0,327 \\
&+ 0,175 = 0,828
\end{align}$$
**Beispiel:**
Betrachte das folgende Glücksspiel:
	Ein fairer Würfel wird 10-mal geworfen.
	Der Spieler gewinnt, wenn jede der Ziffern $1, 2, 3, 4, 5, 6$ mindestens einmal geworfen wird.

*Frage:* Wie hoch ist die Wahrscheinlichkeit eines Gewinns?
$\Omega=\{(w_{1},w_{1},\ldots,w_{10}\mid w_{i}\{1,2,\ldots,6\}f.a.i=1,\ldots,10\}$
$=\{1,2,\ldots,6\}¹⁰$

Für alle $w\in\Omega$: $Pr[w]=\frac$

Gewinn
$G=\{(w_{1},w_{2},\ldots,w_{10})\in\Omega\mid\{w_{1},w_{2},\ldots,w_{3}\}=\{1,2,\ldots,6\}\}$

*Ziel:* Berechnung der Wahrscheinlichkeit $Pr[G]=\sum\limits_{w\in G}Pr[w]=(\frac 1 6)^{10}\cdot||G||$
*Bemerkung:* Hmm?! Schwierig!
*Eventuell Einfacher:*$Pr[G]=1-Pr[\overline G]$
## %%21.03%%
%%Beispiel geht weiter hier%%

Man verliert, wenn min. eine der Zahlen $1,2,\ldots,6$ nicht gewürfelt wird.
Formalisierung als "Ausschluss-Ereignis":
Sei $T \subseteq \{1,2,\ldots,6\}$ Definierte
$$A_T=\{(w_1,\ldots,w_{10\in}\Omega|\forall i:w_i\in\{1,\ldots6\}-T\}$$
$A_{T}$ enthält alle Elementarereignisse, bei denen min. die Zahlen in $T$ nicht gewürfelt wurden.

Beispielsweise enthält $A_{\{2,4\}}$ alle Elementarereignisse, bei denen 2 und 4 (und evtl. noch weitere Zahlen) nicht gewürfelt werden.

*Es gilt:*
- Falls $S\subseteq T, dann A_S\subseteq A_T$
- $A_{S} \cap A_{T}=A_{S\cup T}$
das Ereignis $(4,5,6,6,4,6,5,5,4)$ (somit ist $4,5,6\notin T$) ist in $A_{\{1,2,3\}},A_{\{1\}},A_{\{2\}},A_{\{3\}},A_{\{1,2\}},A_{\{2,3\}},A_{\{1,3\}}$ enthalten.

*Verlust:*
$$\begin{align*}
V&=A_{\{1\}}\cup A_{\{2\}}\cup A_{\{3\}}\cup A_{\{4\}}\cup A_{\{5\}}\cup A_{\{6\}}\\
&=\bigcup_{i=1}^{A_i}A_{\{i\}}
\end{align*}$$
	(Bemerkung {1}=1,...,{i}=i)
*Anwendung der Siebformel:*
$$\begin{align*}
Pr[V]&= Pr[\bigcup_{i=1}^{6}A_{\{i\}}]\\
&= \sum\limits_{T\subseteq\{1,\ldots,6\}}(-1)^{||T||+1}Pt[\bigcap_{i\in T}A_{\{i\}}]\\
&= \sum\limits_{T:||T||=1}(-1)^{2}Pr[A_{T}]\\
&+\sum\limits_{T:||T||=2}(-1)^{3}Pr[A_{T}]\\
&+\sum\limits_{T:||T||=3}(-1)^{4}Pr[A_{T}]\\
&+\sum\limits_{T:||T||=4}(-1)^{5}Pr[A_{T}]\\
&+\sum\limits_{T:||T||=5}(-1)^{6}Pr[A_{T}]\\
&+\sum\limits_{T:||T||=6}(-1)^{7}Pr[A_{T}]\\
--\\
&= \sum\limits_{i=1}^{5}\sum\limits_{T:||T||=i}(-1)^{i+1}\Pr[A_{i}]
\end{align*}$$
(Bemerkung: $\bigcap\limits_{i\in T}A_{\{i\}}=A_{T}$ und $+\sum\limits_{T:||T||=6}(-1)^{7}Pr[A_{T}] = 0$, da $A_{\{1,2\ldots,6\}}=\emptyset$)

Es gilt:
$Pr[A_{T}]=(\frac{{6-||T||}}{{6}})^{10}$ (W'keit eine Zahl zu würfeln, die nicht in T enthalten ist)
$$\begin{align*}
&\sum\limits_{i=1}^{5}\sum\limits_{T:||T||=i}(-1)^{i+1}\Pr[A_{i}]\\
&\sum\limits_{i=1}^{5}\sum\limits_{T:||T||=i}(-1)^{i+1}(\frac{6-i}{6})^{10}\\
&=\sum\limits_{i=1}^{5}(-1)^{i+1}\begin{pmatrix}6\\i\end{pmatrix}(\frac{6-i}{6})^{10}\\
&\approx0,728188 
\end{align*}$$
Somit: $Pr[G]=1-Pr[V]=0,271812$

---
## Definition 3.1 Bedingte Wahrscheinlichkeiten
Gegeben sind die Ereignisse $A$ und $B$, wobei $Pr[B]>0$.
Die *bedingte W'keit* $Pr[A|B]$ von $A$ gegeben $B$ ist definiert durch:
$$
Pr\left[A|B\right]=\frac{Pr\left[A\cap B\right]}{Pr\left[B\right]}.
$$
**Beispiel:**
Ein fairer Würfel wird 2x geworfen.
*Modellierung:*
- $\Omega=\{1,2,3,\ldots,6\}x\{1,2,3,\ldots,6\}$
- $Pr[w]=\frac{1}{36}$ für alle $w\in \Omega$

*Ereignis* "Die Würfelsumme ist gleich 8":
$A=\{(2,6),(3,5),(4,4),(5,3),(6,2)\}$
$Pr[A]=\frac{5}{36}=\frac{||A||}{||\Omega||}$

*Ereignis* "Der erste Wurf liefert 3":
$B=\{(3,1),(3,2),(3,3),(3,4),(3,5),(3,6)\}$

$Pr[B]=\frac{6}{36}=\frac{1}{6}$

$$\begin{align*}
Pr[A|B]&=\frac{Pr[A\cap B]}{{Pr[B]}}\\
&= \frac{Pr[A\{(3,5)\}]}{Pr[B]}\\
&= \frac{{\frac{1}{36}}}{\frac{6}{36}}\\
&= \frac{1}{6}
\end{align*}$$
## %%26.03%%
### Eigenschaften von Def. 3.1:
1. $Pr[B|B]=1$
2. Für alle $A\subseteq \Omega:Pr[A|\Omega]=Pr[A]$
3. Falls $A\cap B=\emptyset$, dann ist $Pr[A|B]=0$
4. Für alle $B\subseteq \Omega$ mit $Pr[B]>0$ gilt:
	$(\Omega, Pr[\cdot|B])$ ist ein diskreter Wahrscheinlichkeitsraum.

**Beispiel:** Zweikinderproblem
Betrachte eine Familie mit zwei Kindern. (keine Zwillinge)
*Frage:* Wie hoch ist die W'keit, dass beide Kinder Mädchen sind?
*Modellierung:*
- $\Omega=\{mm, mj, jm, jj\}$
- $\forall \omega\in\Omega:Pr[\omega]=\frac{1}{4}$

$A=\{mm\} \rightarrow Pr[A]=\frac{1}{4}$
*Frage:* Wie hoch ist die W'keit, dass beide Kinder Mädchen sind, unter der Annahme, dass mindestens eines der Kinder ein Mädchen ist?
$B=\{mh, jm, mm\}$
$$\begin{align*}\\
Pr[A|B]&= \frac{Pr[A\cap B]}{Pr[B]}\\
&=\frac{Pr[\{mm\}]}{\frac{3}{4}}\\
&= \frac{\frac{1}{4}}{\frac{2}{4}}\\
&= \frac{1}{3}
\end{align*}$$
## Satz 3.5 Multiplikationssatz
**Beweis:**
$$\begin{align*}
&Pr[A_{1}|\Omega]\cdot Pr[A_{2}|A_{1}]\cdot Pr[A_{3}|A_{n}\cap A_{2}]\cdot Pr[A_{n}|A_{1}\cap A_{2}\cap \ldots\cap A_{n-1}]\\
&= \frac{Pr[A_{1}]}{Pr[\Omega]}\cdot \frac{Pr[A1\cap A2]}{Pr[A1]}\cdot \ldots \cdot\frac{PrA_{1}\cap\ldots\cap A_{n}}{Pr[A_{1}\cap\ldots\cap A_{n-1}]}\\

\end{align*}$$
*Gekürzt:*
$$=Pr[A_{1}\cap A_{2}\cap\ldots\cap A_{n}]$$

**Beispiel:** Geburtstagsproblem (boots with the furry nooooooooo)
*Frage:* Wie hoch ist die W'keit, dass bei einer Gruppe von $m$ Personen min. 2 Personen am selben Tag Geburtstag haben?
*Annahmen:* 
- Jeder Tag in $\{1,2,3,\ldots,365\}$ ist gleich wahrscheinlich
- Schaltjahre werden nicht berücksichtigt (Sind eine lüge)
- Es gilt: $m\in\{1,2,\ldots,365\}$
*Modellierung:*
- $\Omega=\{1,2,3,\ldots,365\}^{m}$
- $\forall \omega\in \Omega: Pr[\omega]= \frac{1}{||\Omega||}=\frac{1}{365^{m}}$

Mit $D_{j}$, $1\leq j\leq m$, wird das Ereignis bezeichnet, dass die ersten $j$ Personen an verschiedenen Tagen Geboren Geburtstag haben.

| **Geburtstag der Person** | $g_{1}$ | $g_{2}$ | $g_{3}$ | $\ldots$ | $g_{j-1}$ | $g_{j}$ |     | $g_{m}$ |
| ------------------------- | ------- | ------- | ------- | -------- | --------- | ------- | --- | ------- |
| **Person**                | $1$     | $2$     | $3$     |          | $j-1$     | $j$     |     | $m$     |
Alle Personen hat an verschiedenen Tagen Geburtstag genau dann, wenn $g_{i}+g_{j}$ für alle $i+j$gilt.

Element in $D_{j}$:

| *$g_{1}$* | *$g_{2}$* | *$g_{3}$* | *$\ldots$* | *$g_{j-1}$* | *$g_{j}$* | ... | $g_{m}$ |
| --------- | --------- | --------- | ---------- | ----------- | --------- | --- | ------- |
*Farbig:* müssen paarweise disjunkt sein
Nicht Farbig: interessieren nicht!

Es gilt:
$\Omega=D_{1}\supseteq D_{2}\supseteq D_{3}\supseteq \ldots\supseteq D_{m-1}\supseteq D_{m}$
$D_{m}=D_{1}\cap D_{2}\cap D_{3}\cap\ldots\cap D_{m}$

$D_{1}$:

| *$g_{1}$* | $g_{2}$ | $g_{3}$ | $\ldots$ | $g_{j-1}$ | $g_{j}$ |     | $g_{m}$ |
| --------- | ------- | ------- | -------- | --------- | ------- | --- | ------- |

$$\begin{align*}
Pr[D_{j}|D_{j-1}]&= \fraq{365-(j-1)}{}
\end{align*}$$

$D_{1}\cap D_{2}\cap D_{3}\cap D_{4}=D_{4}$

*Multiplikationssatz:*
$$\begin{align*}
Pr[D_{m}]&=Pr[D_{1}\cap D_{2}\cap\ldots\cap D_{m}]\\
&= Pr[D_{1}]\cdot Pr[D_{2}|D_{1}]\cdot Pr[D_{3}|D_{1}\cap D_{2}]\\
&\cdot\ldots \cdot Pr[D_{m}|D_{1}\cap D_{2}\cap\ldots\cap D_{m-1}]\\
&= Pr[D_{1}]\cdot Pr[D_{2}|D_{1}] \cdot Pr[D_{3}|D_{2}]\\
&\cdot\ldots \cdot Pr[D_{m}|D_{m-1}]\\
&= \prod\limits_{j=2}^{m}Pr[D_{j}|D_{j-1}]\\
&= \prod\limits_{j=2}^{m}\frac{365-(j-1)}{365}\\
&= \prod\limits_{j=2}^{m-1} \frac{365-j}{365}\\
&= \prod\limits_{j=2}^{m-1} (1- \frac{j}{365})\\
&\leq \prod\limits_{j=2}^{m-1} e^{-\frac{j}{365}}\\
&= e^{\sum\limits\ß}\\
&= e^{-\frac{1}{365}\sum\limits_{j=1}^{m-1}j}\\
&= e^{\frac{-1}{365}\frac{m(m-1)}{2}}\\
&= e^{-\frac{m(m-1)}{730}}
\end{align*}$$
$B_{m}$ = Ereignis, dass min. 2 Personen am selben Tag Geburtstag haben.
$$\begin{align*}
Pr[B_{m}]&=1-Pr[D_{m}]\\
&\leq1-e^{-\frac{m(m-1)}{730}}
\end{align*}$$
## %%04.04%%
Fehlt
## %%11.04%%

## Satz 3.7 Satz der totalen Wahrscheinlichkeit

$Pr\left[B\right]=\sum_{i=1}^nPr\left[B|A_i\right]\cdot Pr\left[A_i\right].$

$Pr[B|A_{i}]\cdot Pr[A_{i}]= Pr[A_{i}\cap B]$

## Satz 3.9 Satz von Bayes

$$\begin{aligned}Pr\left[A_{i}|B\right]&=\quad\frac{Pr\left[B|A_i\right]Pr\left[A_i\right]}{Pr\left[B\right]}\\&=\quad\frac{Pr\left[B|A_i\right]\cdot Pr\left[A_i\right]}{\sum_{j=1}^nPr\left[B|A_j\right]Pr\left[A_j\right]}.\end{aligned}$$
**Beispiel:** Ärztliche Diagnostik

In der ärztlichen Diagnostik werden häufig Blutuntersuchungen durchgeführt. Oft liefert ein solcher Test ein positives oder negatives Ergebnis. Das Ergebnis ist nicht immer korrekt.
Man unterscheidet zwei Arten von Fehlern:
- *False Positive:* Patient gesund, Test positiv
- *False Negative:* Patient krank, Test negativ

*Ziel:* Bewertung eines solchen Tests mit Hilfe von dem Satz von Bayes.

Angenommen 1% der Bevölkerung leidet an der Krankheit K.
Die Krankheit kann mit einem Bluttest nachgewiesen werden.


**Blutuntersuchung**

|               | positiv | negativ |
| ------------- | ------- | ------- |
| Person krank  | 95%     | ==5%==  |
| Person gesung | *2%*    | 98%     |
==False Negative==
*False Positive*

**Frage:** Wie hoch ist die W'keit, dass eine zufällig ausgewählte Person erkrankt ist, wenn bei ihr der Bluttest positiv ausfällt?

*Ereignisse:*
- K -> "Die Person ist Krank"
- P -> "Das Ergebnis der Blutuntersuchung ist positiv"

*Es gilt:*
- $Pr[P|K]=0,95$
- $Pr[\overline P|K]=0,05$
- $Pr[P|\overline K]=0,02$
- $Pr[\overline P|\overline K]=0,98$

Satz von Bayes:

$$Pr[K|P]=\frac{Pr[P|K]\cdot Pr[K]}{Pr[P]}=*$$
Einschub / Zwischenrechnung:
$$\begin{align*}
Pr[P]&= Pr[P|K]\cdot Pr[K]\cdot Pr[P|\overline K]\cdot Pr[\overline K] \text{ |Satz:(3.7 SotW)}\\
&= 0,95\cdot 0,01+0,02\cdot 0,99\\
&= 0,0293
\end{align*}$$
 
$$\begin{align*}
*&= \frac{0,95\cdot0,01}{0,0293}\\
&= 0,324232
\end{align*}$$

*Bisschen neuer Fall:*
Angenommen eine Person geht zum Arzt. Der Arzt weiß aufgrund seiner langjährigen Berufserfahrung, dass 30% der Menschen mit den beobachteten Symptomen an der Krankheit K leiden. Deshalb ordnet er einen Bluttest an. Dieser ist Positiv.

$$Pr[P]=0,95\cdot0,3+0,02\cdot0,7=0,299$$

$$\begin{align*}
Pr[K|P]&= \frac{0,95\cdot0,3}{0,299}\\
&= 0,953177
\end{align*}$$
# Unabhängige Ereignisse
## Def 4.1 Unabhängigkeit
Die Ereignisse A und B sind unabhängig, falls
$$Pr[A\cap B]=Pr[A]\cdot Pr[B]$$
gilt.

A,B unabhängig:
$$\begin{align*}
Pr[A|B]&= \frac{Pr[A\cap B]}{Pr[B]}\\
&= \frac{Pr[A]\cdot Pr[B]}{Pr[B]}\\
&= Pr[A]
\end{align*}$$
Analog: $Pr[A|B]=Pr[A]$ // $Pr[B|A]=Pr[B]$

**Beispiel:** Es werden nacheinander ein roter und ein blauer Würfel geworfen.

Betrachte die folgenden Ereignisse:
- A -> "Die Augenzahl des roten Würfels ist gerade"
- B -> "Die Augenzahl der blauen Würfels ist gerade"
- C -> "Die Augensumme beider Würfel ist gleich 7"

*Es gilt:* $Pr[A]=Pr[B]=\frac{1}{2}$

$A\cap B=\{(2,2),(2,4),(2,6),(4,2),(4,4),(4,6),(6,2),(6,4),(6,6)\}$
$Pr[A\cap B]=\frac{||A\cap B||}{||\Omega||}=\frac{8}{36}=\frac{1}{4}=\frac{1}{2}\cdot \frac{1}{2}= Pr[A]\cdot Pr[B]$
$Pr[A|B]=\frac{Pr[A\cap B]}{Pr[B]}=\frac{\frac{1}{4}}{{\frac{1}{2}}}=\frac{1}{2}=Pr[A]$
$Pr[B|A]=\frac{Pr[A\cap B]}{Pr[A]}=\frac{\frac{1}{4}}{{\frac{1}{2}}}=\frac{1}{2}=Pr[B]$

-> A,B unabhängig

$C=\{(1,6),(2,5)(3,4),(4,3),(5,2),(6,1)\}$
$A\cap C=\{(2,5),(4,3),(6,1)\}$

$Pr[A\cap C]=\frac{3}{36}=\frac{1}{12}=\frac{1}{6}\cdot \frac{1}{2}= Pr[C]\cdot Pr[A]$

-> A, C unabhängig

**Beispiel:** betrachte eine Urne, die 6 kugeln enthält, die mit 1,2,3,4,5,6 beschriftet sind.
Zwei Kugeln werden ohne Zurücklegen gezogen.

$\Omega=\{(w_{1},w_{2})\in \{1,2,\ldots,6\} ^{2}|w_{1}\neq w_{2}\}, ||\Omega||=6\cdot5x30 (?)$

*Ereignisse:*
- A -> "die erste gezogene Kugel ist gerade"
- B -> "die zweite gezogene Kugel ist gerade"

$Pr[A]=\frac{1}{2}$
$$\begin{align*}
Pr[B]&= Pr[B|A]\cdot Pr[A]+Pr[B|\overline A]\cdot Pr[\overline A] \text{ (SotW!)}\\
&= \frac{2}{5}\cdot \frac{1}{2}+ \frac{3}{5} \cdot \frac{1}{2}\\
&= \frac{1}{2}
\end{align*}$$
## %%16.04%%

