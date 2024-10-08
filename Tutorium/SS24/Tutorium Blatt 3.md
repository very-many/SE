
## Aufgabe 1
### 1)

| **x** | **y** |
| ----- | ----- |
| 2     | 4     |
| 3     | 5     |
| 4     | 6     |
| 5     | 7     |
| 6     | 8     |
$$\begin{align*}
\bar x &= 4\\
\bar y &= 6
\end{align*}$$

| **$\Delta x$** | **$\Delta y$** |
| -------------- | -------------- |
| $2-4=-2$       | $4-6=-2$       |
| -1             | -1             |
| 0              | 0              |
| 1              | 1              |
| 2              | 2              |
$$\begin{align*}
&\sum\limits\Delta x \cdot\Delta y\\
&= -2 \cdot(-2) + (-1) \cdot (-1) + 0 \cdot0 + 1 \cdot1 + 2 \cdot2\\
&= 10
\end{align*}$$

| **$\Delta x^2$** | **$\Delta y^2$** |
| ---------------- | ---------------- |
| $(-2)^{2}=4$     | $(-2)^{2}=4$     |
| 1                | 1                |
| 0                | 0                |
| 1                | 1                |
| 4                | 4                |
$$\begin{align*}
&\sqrt{\sum\limits\Delta x^{2}  \cdot \sum\limits\Delta y^{2}}\\
&= \sqrt{10 \cdot10}\\
&= 10
\end{align*}$$
$$r=\frac{10}{10}=1$$
---
## Aufgabe 2
### 1)
| **x** | **y** |
| ----- | ----- |
| 1     | 3     |
| 2     | 6     |
| 3     | 8     |
| 4     | 11    |
| 5     | 14    |
**Schritt 1**
$$V=\begin{pmatrix}1&1 \\ 1&2 \\ 1&3 \\ 1&4 \\ 1&5\end{pmatrix}$$
$$V^{T} = \begin{pmatrix}1&1&1&1&1 \\ 1&2&3&4&5\end{pmatrix}$$
$$V^{T}\cdot V = \begin{pmatrix}1&1&1&1&1 \\ 1&2&3&4&5\end{pmatrix}\cdot\begin{pmatrix}1&1 \\ 1&2 \\ 1&3 \\ 1&4 \\ 1&5\end{pmatrix}
=\begin{pmatrix}5&15 \\ 15&55\end{pmatrix}$$
**Schritt 2**
$$V^{T}\cdot\begin{pmatrix}y_{1} \\ y_{2} \\ y_{3} \\ y_{4} \\ y_{5}\end{pmatrix}=\begin{pmatrix}1&1&1&1&1 \\ 1&2&3&4&5\end{pmatrix} \cdot \begin{pmatrix}3 \\ 6 \\ 8 \\ 11 \\ 14\end{pmatrix}=\begin{pmatrix}42 \\ 153\end{pmatrix}$$
**Schritt 3**
$$V^{T}\cdot V \cdot\begin{pmatrix}a_{0} \\ a_{1}\end{pmatrix}=V^{T}\begin{pmatrix}y_{1} \\ y_{2} \\ y_{3} \\ y_{4} \\ y_{5}\end{pmatrix}$$
$$\begin{align*}
&\begin{pmatrix}5&15&= &42\\
15&55&= &153\end{pmatrix}\\
&\begin{pmatrix}5&15&= &42\\
0&10&= &27\end{pmatrix}\\
\end{align*}$$
$$\begin{align*}
5\cdot x_{1}+ 15\cdot x_{2} &=42 \\
10*x_2 &= 27
\end{align*}$$
$$\begin{align*}
x_{1}&= \frac{3}{10}\\
x_{2}&= \frac{27}{10}
\end{align*}$$
