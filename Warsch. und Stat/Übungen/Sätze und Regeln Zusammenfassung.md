- **Multiplikationsgesetz der Wahrscheinlichkeit** $$\begin{align*}
Pr[A\cap B]&= Pr[A\mid B]\cdot Pr[B]\\\\

Pr[A\mid B]&= \frac{Pr[A\cap B]}{Pr[B]}\\
\end{align*}$$
- **Satz der totalen Wahrscheinlichkeit**$$\begin{align*}
Pr[A]&= Pr[A\mid B]\cdot Pr[B] + Pr[A\mid \overline{B}]\cdot Pr[\overline{B}]
\end{align*}$$
- **Satz von Bayes**$$Pr[B\mid A]=\frac{Pr[A\mid B]\cdot Pr[B]}{Pr[A]}$$
- **Erwartungswert**$$\begin{align*}
Exp[X]&= \sum\limits_{i=1}^{n}{x_{i}\cdot Pr[x_{i}]}
\end{align*}$$
- **Erwartungswert²**$$\begin{align*}
Exp[X]&= \sum\limits_{i=1}^{n}{x_{i}^{2}\cdot Pr[x_{i}]}
\end{align*}$$
- **Varianz**$$\begin{align*}
Var[X]&= Exp[X^{2}]-Exp[X]^{2}
\end{align*}$$
- **Unabhängigkeit**$$\begin{align*}
Pr[A\cap B]&= Pr[A]\cdot Pr[B]\\
Pr[A]&= \frac{Pr[A\cap B]}{Pr[B]}
\end{align*}$$
- **Ungleichung von Markov** $$Pr[X\ge a]\le\frac{Exp[X]}{a}$$
- **Chebyshev Ungleichung**$$Pr[|X-\mu|\ge k\sigma]\le \frac{1}{k^{2}}$$


- Für eine stetig gleichverteilte Zufallsvariable $X$ gilt:

1. Der Erwartungswert $Exp[X]$:$$Exp[X] = \frac{a + b}{2}​$$

2. Die Varianz $\text{Var}[X]$:$$Var[X] = \frac{(b - a)^2}{12}$$