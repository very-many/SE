## Aufgabe 1
**a + c)**
$a_{1}\rightarrow a_{5}$
$a_{2}\rightarrow a_{1},a_{2},a_{3},a_{4},a_{5}$

**b)**
$a_{1}\rightarrow a_{4},a_{5}$
$a_{2}\rightarrow a_{1},a_{5}$

## Aufgabe 2

$L \rightarrow O$
$L \rightarrow O,D$

## Aufgabe 3
Gegeben: $H = \{(a_{1}a_{2} \rightarrow a_{3}),(a_{2}a_{3} \rightarrow a_{4}),(a_{3} \rightarrow a_{5}),(a_{5}a_{4} \rightarrow a_{6})\}$

**a)** Ist $(a_{1}a_{2} \rightarrow a_{5}a_{6})$ enthalten?

$$\begin{align*}
a_{1}a_{2} &\rightarrow a_{3} \\
a_{3} &\rightarrow a_{5} \\
a_{2}a_{3} &\rightarrow a_{4}\\
\\
\Rightarrow a_{1}a_{2} &\rightarrow a_{5}a_{6} \in H^{+}
\end{align*}$$

**b)** Ist $(a_{3}a_{4} \rightarrow a_{2}a_{6})$ enthalten?

Nö, es wird nie auf $a_{2}$ gezeigt.