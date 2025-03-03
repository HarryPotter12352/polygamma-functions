# polygamma-functions

A script to generate and graph polygamma functions in C++

Polygamma functions are used to compute complex sums, including the gamma function. They show up in physics, mathematics and statistics.

## Definition of the polygamma function

The polygamma function of order $n$ is defined as the $n+1$th derivative of the gamma function, $\Gamma(z)$.

$$
\Gamma(z) = \int_{0}^{\infty} t^{z-1}e^{-t} dt
$$

The polygamma $\psi^{(n)}$ is then

$$
\psi^{(n)}(x) = \frac{d^{n+1}}{dz^{n+1}}\ln(\Gamma(z)) = -\int_{0}^{1} \frac{t^{z-1}}{1-t}  (\ln t)^n dt
$$

However, courtesy of the Hurwitz zeta function $\zeta(s,a)$, we will not compute the integral form explicitly.

$$
\psi^{(n)}(x) = (-1)^{n+1}m!\zeta(n+1,z)
$$

The gamma function is provided within the code to compute $m! = \Gamma(m+1)$

The Hurwitz Zeta function is given by

$$
    \zeta(n,s) = \sum_{n=0}^{\infty}\frac{1}{(n+a)^s}
$$
