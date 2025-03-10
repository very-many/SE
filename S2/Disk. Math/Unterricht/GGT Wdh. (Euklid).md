**Frage:** Bestimme den ggT
$x,y \in\mathbb{Z}$
 $$ggT(6141; 3243)$$

| **m** | **n** | Was gemacht wurde                    | $\left\lfloor\frac nm\right\rfloor$ | x               | y   |
| ----- | ----- | ------------------------------------ | ----------------------------------- | --------------- | --- |
| 6141  | 3243  | Initial ($m =n\mod m$ machen oft jz) | 0                                   | -19             | 36  |
| 3243  | 6141  | $m =3243\mod 6141$                   | 1                                   | 36              | -19 |
| 2898  | 3243  | $m =6141\mod 3243$                   | 1                                   | -2+(-1)cd17=-19 | 17  |
| 345   | 2898  | $m =3243\mod 2898$                   | 8                                   | 1+16=17         | -2  |
| 138   | 345   | ...                                  | 2                                   | -2              | 1   |
| 69    | 138   |                                      | 2                                   | 1               | 0   |
| 0     | *69*  |                                      |                                     | 0               | 1   |
-> $ggT(6141; 3243)=69$

**Frage:** ist $6141x+3243y=207$ lösbar?
$$\begin{align*}
6141x+3243y&= 207\\
6141x'+3243y'&= 69\\
207&= 3\cdot69\\
&= 3\cdot(6141x'+3243y')\\
&= 3\cdot(6141\cdot(-19)+3243\cdot36)\\
&= (6141\cdot(-57)+3243\cdot108)
\end{align*}$$
-> Ja mit $x=-57$ und $y=108$