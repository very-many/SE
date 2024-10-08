

| **x** | **y** |
| ----- | ----- |
| 1     | 2     |
| 2     | 3     |
| 3     | 4     |
$p(x)=a_{0}+a_{1}x+a_{2}x^{2}+a_{3}x^{3}$
$p(1)=a_{0}+a_{1}+a_{2}+a_{3}=2$
$p(2)=a_{0}+a_{1}2+a_{2}4+a_{3}8=3$
$p(3)=a_{0}+a_{1}3+a_{2}9+a_{3}27=4$

$$\begin{pmatrix}1&1&1&1=2 \\ 1&2&4&8=3 \\ 1&3&9&27=4\end{pmatrix}$$
$$\ldots$$
$$\left(\begin{matrix}
1 & 1 & 1 & 1 = 2 \\
0 & 1 & 3 & 7 = 1 \\
0 & 0 & 2 & 12 = 0
\end{matrix}\right)$$

$a_{3}=x_{4}$
$a_{2}=-6x_{4}$
$a_{1}=1+11x_{4}$
$a_{0}=1-6x_{4}$
$$p(x)=(1-6x_{4})+(1+11x_{4})x+(-6x_{4})x^{2}+(x_{4})x^3$$
**Probe:** Durch einsetzen der Punkte.
$$\begin{align*}
p(1)&= 1-6x_{4}+1+11x_{4}+-6x_{4}+x_{4}=2\\
&= 2\\
\end{align*}$$
$$\begin{align*}
p(2)&= 1-6x_{4}+(1+11x_{4})2+(-6x_{4})4+(x_{4})8=3\\
&= 1-6x_{4}+2+22x_{4}+-24x_{4}+8x_{4}=3\\
&= 3
\end{align*}$$
$$\begin{align*}
p(3)&= 1-6x_{4}+(1+11x_{4})3+(-6x_{4})9+(x_{4})27=4\\
&= 1-6x_{4}+3+33x_{4}+-54x_{4}+27x_{4}=4\\
&= 4
\end{align*}$$
Damit geht jedes Polynom 3. Grades $p(x)=(1-6x_{4})+(1+11x_{4})x+(-6x_{4})x^{2}+(x_{4})x^3$ mit $x_{4}\in \mathbb{R}$ durch die Punkte $P_{1}(1|2), P_{2}(2|3), P_{3}(3|4)$.

Für $x_{4}=0$ erhalten wir $p(x)=1+x$, also ein Polynom ersten Grades.

Für $x_{4}=1$ erhalten wir $p(x)=-5+12x-6x^{2}+x^3$, also ein Polynom dritten Grades.