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
- $Pr[C]$: $$Pr[C]=$$