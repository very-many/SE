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
## Satz 2.3 (Siebformel)
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
![[Pasted image 20240319164038.png]]
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
Anwendung der Siebformel:
$$\begin{align*}
Pr[V]&= Pr[\bigcup_{i=1}^{6}A_{\{i\}}]\\
&= \sum\limits_{T\subseteq\{1,\ldots,6\}}(-1)^{||T||+1}Pt[\bigcap_{i\in T}A_{\{i\}}]
\end{align*}$$

