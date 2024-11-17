## Aufgabe 1

| **x**   | **y**   |
| --- | --- |
| 1   | 2   |
| 2   | 3   |

## Aufgabe 3

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

## Aufgabe 4

| **x** | **y** |
| ----- | ----- |
| 0     | 1     |
| 1     | 2     |
| 2     | 3     |
| 3     | 4     |
**Schritt 1:**
$$
\begin{align*}
V&= \begin{pmatrix}1&0&0&0 \\ 1&1&1&1 \\ 1&2&4&8 \\ 1&3&9&27\end{pmatrix}\\
\\
V^{T}&= \begin{pmatrix}1&1&1&1 \\ 0&1&2&3 \\ 0&1&4&9 \\ 0&1&8&27\end{pmatrix}\\
\\
V^{T}V&= 
\begin{pmatrix}1&1&1&1 \\ 0&1&2&3 \\ 0&1&4&9 \\ 0&1&8&27\end{pmatrix} \cdot \begin{pmatrix}1&0&0&0 \\ 1&1&1&1 \\ 1&2&4&8 \\ 1&3&9&27\end{pmatrix} = \begin{pmatrix}4&6&14&36 \\ 6&14&36&98 \\ 14&36&98&276 \\36&98&276&794\end{pmatrix}
\end{align*} 
$$
**Schritt 2:**
$$
\begin{align*}
V^{T}\cdot\vec{y} &= 
\begin{pmatrix}1&1&1&1 \\ 0&1&2&3 \\ 0&1&4&9 \\ 0&1&8&27\end{pmatrix} \cdot
\begin{pmatrix}1\\2\\3\\4\end{pmatrix} =
\begin{pmatrix}10\\20\\50\\134\end{pmatrix}
\end{align*}
$$
**Schritt 3:**
$$V^{T}V \cdot\vec{a} = V^{T}\cdot\vec{y}$$
$$\begin{align*}
\begin{matrix}a_{0}-a_{1}-a_{2}-a_{3}\\
\begin{pmatrix}4&6&14&36 \\ 6&14&36&98 \\ 14&36&98&276 \\36&98&276&794\end{pmatrix} \end{matrix} = 
\begin{matrix}\\\begin{pmatrix}10\\20\\50\\134\end{pmatrix}\end{matrix}\\
\\
\begin{pmatrix}4&6&14&36&\mid10 \\ 6&14&36&98&\mid20 \\ 14&36&98&276&\mid50\\36&98&276&794&\mid134\end{pmatrix}\\
\\
\cdots\\
\\
\begin{pmatrix}4&6&14&36&\mid10 \\ 0&5&15&44&\mid5 \\ 0&0&4&18&\mid0\\0&0&0&\frac{3}{5}&\mid0\end{pmatrix}
\end{align*}$$
$$\begin{align*}
\frac{3}{5}a_{3}&= 0\\
a_{3}&= 0\\
\\
4a_{2} + 18 \cdot 0 &= 0\\
a_{2} &= 0\\
\\
5a_{1} + 15 \cdot 0 + 44 \cdot 0 &= 5\\
5a_{1} &= 5\\
a_{1}&= 1\\
\\
4a_{0} + 6 \cdot1 + 14 \cdot0 + 36 \cdot 0 &= 10\\
4a_{0}&= 10 - 6\\
a_{0}&= 1
\end{align*}$$
**Lösung:**
$$p(x)=x+1$$