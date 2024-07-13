# Wahrscheinlichkeitsbaum Ausfüllen
![[fugwvzqigh.png]]

- *a:* $$\begin{align*}
\frac{9}{100}&= a \cdot \frac{9}{25}\\
a&= \frac{\frac{9}{100}}{\frac{9}{25}}\\
a&= \frac{1}{4}
\end{align*}$$
- *b:* $$\begin{align*}
1&= a+b\\
b&= 1-a\\
b&= \frac{3}{4}
\end{align*}$$
- *c:* $$\begin{align*}
1&= c+ \frac{8}{25}+\frac{9}{25}\\
c &=  1-\frac{8}{25}+\frac{9}{25}\\
c&= \frac{8}{25}
\end{align*}$$
- *d:* $$\begin{align*}
d&= a \cdot \frac{8}{25}\\
d&= \frac{1}{4} \cdot \frac{8}{25}\\
d&= \frac{8}{100} =\frac{2}{25}
\end{align*}$$
- *e:* $$\begin{align*}
e&= b \cdot \frac{9}{25}\\
e&= \frac{3}{4} \cdot \frac{9}{25}\\
e&= \frac{27}{100}
\end{align*}$$
# Produktanalyse
In einer Fabrik wird ein Produkt auf drei verschiedenen Maschinen , und gefertigt.  
Die Gesamtproduktion verteilt sich wie folgt:  

| Maschine | Anteil | ()          |
| -------- | ------ | ----------- |
| $M_{1}$  | 0.79   | $Pr[A_{1}]$ |
| $M_{2}$  | 0.16   | $Pr[A_{2}]$ |
| $M_{3}$  | 0.05   | $Pr[A_{2}]$ |
Der Ausschuss der Fertigung ist abhängig von der Maschine:  

| Maschine | Anschluss | ()                |
| -------- | --------- | ----------------- |
| $M_{1}$  | 0.19      | $Pr[F\mid A_{1}]$ |
| $M_{2}$  | 0.19      | $Pr[F\mid A_{2}]$ |
| $M_{3}$  | 0.01      | $Pr[F\mid A_{3}]$ |
Wie hoch ist die Wahrscheinlichkeit, dass ein zufällig aus der Gesamtproduktion ausgewähltes Exemplar defekt ist?  
  
$F$= fehlerhaftes Exemplar  
$A_{i}$= das Exemplar wurde auf Maschine i gefertigt

- $Pr[F]$: *(SdtW)*$$\begin{align*}
Pr[F]&= Pr[F\mid A_{1}] \cdot Pr[A_{1}] + Pr[F\mid A_{2}] \cdot Pr[A_{2}] + Pr[F\mid A_{3}] \cdot Pr[A_{3}]\\
&= 0,19\cdot0,79+0,19\cdot0,16+0,01\cdot0,05\\
&= 0,1810
\end{align*}$$
- $Pr[A_{1}\mid F]$: *(Satz von Bayes)*$$\begin{align*}
Pr[A_{1}|F]&= \frac{Pr[F\mid A_{1}]\cdot Pr[A_{1}]}{Pr[F]}\\
&= \frac{0,19\cdot0,79}{0,1810}\\
&\approx 0,829282
\end{align*}$$
- $Pr[A_{2}\mid F]$: *(Satz von Bayes)* $$\begin{align*}
Pr[A_{2}|F]&= \frac{Pr[F\mid A_{2}]\cdot Pr[A_{2}]}{Pr[F]}\\
&= \frac{0,19\cdot0,16}{0,1810}\\
&\approx 0,167955
\end{align*}$$
- $Pr[A_{3}\mid F]$: *(Satz von Bayes)* $$\begin{align*}
Pr[A_{3}|F]&= \frac{Pr[F\mid A_{3}]\cdot Pr[A_{3}]}{Pr[F]}\\
&= \frac{0,01\cdot0,05}{0,1810}\\
&= \frac{1}{362}
\end{align*}$$
# Malware Scanner
Ein Systemadministrator führt Scans von Festplatten auf Systemen mit verdächtiger Aktivität durch.  
Erfahrungsgemäß werden 19% der Dateien als verdächtig markiert.  
Von den markierten Dateien enthalten 56% tatsächlich Malware.  
Eine unverdächtige Datei enthält trotzdem in 30% der Fälle Schadsoftware.  
  
Es sollen folgende Ereignisse untersucht werden:  
$V \rightarrow$ Datei verdächtig  
$M \rightarrow$ Datei enthält Malware  

gegeben:
$Pr[V]=0,19$
$Pr[M\mid V]=0,56$
$Pr[M\mid \overline{V}]=0,30$

- Eine Datei wird gescannt. Mit welcher Wahrscheinlichkeit ist die Datei verdächtig und enthält Malware?  *(Multiplikationsgesetz der Wahrscheinlichkeit)*$$\begin{align*}
Pr[V\cap M]&= Pr[M\mid V] \cdot Pr[V]\\
&= 0,56 \cdot0,19\\
&= 0,1064
\end{align*}$$
- Berechnen Sie die Wahrscheinlichkeit, dass eine zufällig ausgewählte Datei Malware enthält. *(SdtW)*$$\begin{align*}
Pr[M]&= Pr[M\mid V]\cdot Pr[V] + Pr[M\mid \overline{V}]\cdot Pr[\overline{V}]\\
&= 0,56\cdot0,19+0,30\cdot(1-0,19)\\
&= 0,1064+0,243\\
&= 0,3494
\end{align*}$$
  
- Deine Datei enthält sicher Schadsoftware. Mit welcher Wahrscheinlichkeit wurde diese Datei als verdächtig markiert? *(Satz von Bayes)*$$\begin{align*}
Pr[V\mid M]&= \frac{Pr[M\mid V]\cdot Pr[V]}{Pr[M]}\\
&= \frac{0,56\cdot0,19}{0,3494}\\
&\approx  0,304522
\end{align*}$$
# Mengen
Gegeben sind die Ereignisse $A$, $B$ und $C$, sowie die Elementarereignisse $a$ bis $g$ mit ihren Wahrscheinlichkeiten:

| **$\omega$**          | **$Pr[\omega]$** |
| ----------------- | ------------ |
| **a**             | 0,09         |
| **b**             | 0,11         |
| **c**             | 0,13         |
| **d**             | 0,1          |
| **e**             | 0,08         |
| **f**             | 0,48         |
| **g**             | 0,01         |
| **$\sum\limits$** | 1            |
$A=\{a,c,d\}$
$B=\{a,b,c,e\}$
$C=\{a,d,e,g\}$

Berechnen Sie die Wahrscheinlichkeiten zu folgenden Ereignissen:
- $Pr[\overline{B}]$: $$\begin{align*}
Pr[\overline{B}]&= 1-Pr[B]\\
&= 1-(Pr[a] + Pr[b] + Pr[c] + Pr[e])\\
&= 1-(0,09+0,11+0,13+0,08)\\
&= 1-0,41\\
&= 0,59
\end{align*}$$
- $Pr[B\cap C]$: $$\begin{align*}
Pr[B\cap C]&= Pr[a]+Pr[e]\\
&= 0,09+0,08\\
&= 0,17
\end{align*}$$
- $Pr[C]$: $$\begin{align*}
Pr[C]&= Pr[a]+Pr[d]+Pr[e]+Pr[g]\\
&= 0,09+0,10+0,08+0,01\\
&= 0,28
\end{align*}$$
- $Pr[A\mid B]$: *(Multiplikationsgesetz der Wahrscheinlichkeit)*$$\begin{align*}
Pr[A\cap B]&= Pr[A\mid B]\cdot Pr[B]\\
Pr[A\mid B]&= \frac{Pr[A\cap B]}{Pr[B]}\\
&= \frac{{P[a]+Pr[c]}}{{Pr[a]+Pr[b]+Pr[c]+Pr[e]}}\\
&= \frac{0,09+0,13}{0,09+0,11+0,13+0,08}\\
&= \frac{22}{41}
\end{align*}$$
- $Pr[B\mid \overline{C}]$: *(Multiplikationsgesetz der Wahrscheinlichkeit)*$$\begin{align*}
Pr[B\cap\overline{C}]&= Pr[B\mid\overline{C}]\cdot Pr[\overline{C}]\\
Pr[B\mid\overline{C}]&= \frac{Pr[B\cap \overline{C}]}{Pr[\overline{C}]}\\
&= \frac{Pr[b]+Pr[c]}{Pr[b]+Pr[c]+Pr[f]}\\
&= \frac{0,24}{0,72}\\
&= \frac{1}{3}
\end{align*}$$
- $Pr[A\cup B\cup C]$: $$\begin{align*}
Pr[A\cup B \cup C]&= Pr[a]+Pr[b]+Pr[c]+Pr[d]+Pr[e]+Pr[g]\\
&= 1-Pr[f]\\
&= 0,52
\end{align*}$$
# Bedingte Wahrscheinlichkeiten
Gegeben sind die Ereignisse $A$, $B_{1}$, $B_{2}$ und $B_{3}$ mit folgenden Wahrscheinlichkeiten:

| **$i$** | **$Pr[B_{i}]$** | **$Pr[A\mid B_{i}]$** |
| ------- | --------------- | --------------------- |
| **1**       | 0,38            | 0,3                   |
| **2**       | 0,24            | 0,12                  |
| **3**       | 0,38            | 0,01                  |
Berechnen Sie folgende Wahrscheinlichkeiten:
- $Pr[A]$: *(SdtW)*$$\begin{align*}
Pr[A]&= Pr[A\mid B_{1}] \cdot Pr[B_{1}] + Pr[A\mid B_{2}] \cdot Pr[B_{2}] + Pr[A\mid B_{2}] \cdot Pr[B_{3}]\\
&= 0,3\cdot0,38+0,12\cdot0,24+0,01\cdot0,38\\
&= 0,1466
\end{align*}$$
- $Pr[B_{2}\mid A]$: *(Satz von Bayes)*$$\begin{align*}
Pr[B_{2}\mid A]&= \frac{Pr[A\mid B_{2}]\cdot Pr[B_{2}]}{Pr[A]}\\
&= \frac{0,12\cdot0,24}{0,1466}\\
&= \frac{144}{733}
\end{align*}$$
# Erwartungswert/Varianz
Die diskrete Zufallsvariable $X$ wird durch folgende Wertetabelle definiert:

| **$k$** | **$Pr[X=k]$** |
| ------- | ------------- |
| **-5**  | 0,31          |
| **-4**  | 0,07          |
| **2**   | 0,07          |
| **4**   | 0,08          |
| **6**   | 0,03          |
| **9**   | 0,02          |
| **13**  | 0,36          |
| **20**  | 0,06          |
Berechnen Sie:
- $Exp[X]$: $$\begin{align*}
Exp[X]&= -5\cdot0,31+(-4)\cdot0,07+2\cdot0,07+4\cdot0,08+6\cdot0,03+9\cdot0,02+13\cdot0,36+20\cdot0,06\\
&= 4,87
\end{align*}$$
- $Exp[X^{2}]$: $$\begin{align*}
Exp[X^{2}]&= -5^{2}\cdot0,31+(-4)^{2}\cdot0,07+2^{2}\cdot0,07+4^{2}\cdot0,08+6^{2}\cdot0,03+9^{2}\cdot0,02+13^{2}\cdot0,36+20^{2}\cdot0,06\\
&= 97,97
\end{align*}$$
- $Var[X]$: $$\begin{align*}
Var[X]&= Exp[X^{2}]-Exp[X]^{2}\\
&= 97,97-4,87^2\\
&= 97,97-23,7169\\
&= 74,2531
\end{align*}$$
# Standardnormalverteilung
Gegeben ist eine normalverteilte Zufallsvariable $X$ mit dem Erwartungswert $\mu= -1$ und Varianz $\sigma ^{2}= 9$.  
Berechnen Sie folgende Wahrscheinlichkeiten:
- $Pr[X\leq9,54]$:$$\begin{align*}
z&=\frac{x-\mu}{\sigma}\\
&= \frac{9,54-(-1)}{\sqrt{9}}\\
&= 3,51\overline{3}\\\\

\rightarrow Pr[X\leq 9,54]&= 0,999784
\end{align*}$$
- $Pr[X\leq 9,62]$:$$\begin{align*}
z&=\frac{x-\mu}{\sigma}\\
&= \frac{9,62-(-1)}{\sqrt{9}}\\
&= 3,54\\\\

\rightarrow Pr[X\leq 9,62]&= 0,999800
\end{align*}$$
- $Pr[9,54\leq X\leq 9,62]$:$$\begin{align*}
Pr[9,54\leq X\leq 9,62]&= Pr[X\leq9,62]-Pr[X\leq 9,54]\\
&= 0,999800 - 0,000784\\
&= 0,000016
\end{align*}$$