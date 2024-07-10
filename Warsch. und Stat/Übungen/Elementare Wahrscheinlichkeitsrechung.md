# Teil 1

## Aufgabe 1
Eine Lostrommel enthält jeweils fünf rote, blaue und gelbe Kugeln. Pro Farbe sind
die Kugeln mit den Ziffern 1, 2, 3, 4 und 5 beschriftet. Eine Glücksfee zieht aus der Lostrommel
nacheinander zwei Kugeln. Eine bereits gezogene Kugel wird nicht in die Trommel zurück gelegt.

**a)** Modellieren Sie dieses Zufallsexperiment als diskreten Wahrscheinlichkeitsraum.
*Modellierung:* $K=\{R_{1},R_{2},R_{3},R_{4},R_{5},B_{1},B_{2},B_{3},B_{4},B_{5},G_{1},G_{2},G_{3},G_{4},G_{5}\}$
*Ereignisraum:* $\Omega=\{(k_{1},k_{2})\in KxK\mid k_{1}\neq k_{2}\}$  
	Es gilt: $||\Omega|| = ||K||\cdot(||K||-1)=15\cdot14=210$
*Laplace-Prinzip:* Für alle $\omega \in\Omega$ gilt: $Pr[\omega]=\frac{1}{210}$

**b)** Wie hoch ist die Wahrscheinlichkeit, dass zwei rote Kugeln gezogen werden?
$A_{1}=\{(R_{i},R_{j})\mid i,j\in\{1,\ldots,5\},i\neq j\}$
$Pr[A_{1}]=\frac{||A_{1}||}{||\Omega||}=\frac{5\cdot4}{210}=\frac{20}{210}=\frac{2}{21}=0,095238$

**c)** Mit welcher Wahrscheinlichkeit wird eine blaue und eine gelbe Kugel gezogen?
$A_{2}=\{(B_{i},G_{j})\mid i,j\in\{1,2,3,4,5\}\}\cup\{(G_{i},B_{j})\mid{i,j}=\{1,2,\ldots,5\}\}$
$Pr[A_{2}]=\frac{||A_{2}||}{||\Omega||}=\frac{5\cdot5+5\cdot5}{210}=\frac{50}{210}=\frac{5}{21}=0,238085$

**d)** Wie hoch ist die Wahrscheinlichkeit, dass mindestens eine der gezogenen Kugeln mit der
Ziffer 2 beschriftet ist?
$Z=\{R_{2},B_{2},G_{2}\}$ $N=K-Z$
$A_{3}=ZxN\cup NxZ\cup \{k_{1},k_{2}\in ZxZ\mid k_{1}\neq k_{2}\}$

$||A_{3}||=3\cdot12 + 12 \cdot3 +3\cdot2 = 78$
$Pr[A_{3}]=\frac{||A_{3}||}{||\Omega||}=\frac{78}{210}=\frac{13}{35}=0,371429$

**e)** Wie hoch ist die Wahrscheinlichkeit, dass zwei Kugeln mit der Ziffernsumme 4 gezogen
werden?
$$\begin{align*}
A_{4} &=  \{(k_{1},k_{2})\mid k_{1}\in\{R_{1},B_{1},G_{1}\}, k_{2}\in\{R_{3},B_{3},G_{3}\}\}\\
&\cup \{(k_{1},k_{2})\mid k_{1}\in\{R_{2},B_{2},G_{2}\}, k_{2}\in\{R_{2},B_{2},G_{2}\}\}\\
&\cup \{(k_{1},k_{2})\mid k_{1}\in\{R_{3},B_{3},G_{3}\}, k_{2}\in\{R_{1},B_{1},G_{1}\}\}\\
\end{align*}$$
$||A_{4}||=3\cdot3+3\cdot2+3\cdot3 = 9+6+9=24$
$Pr[A_{4}]=\frac{||A_{3}||}{||\Omega||}=\frac{24}{210}=\frac{4}{35}=0,114286$
