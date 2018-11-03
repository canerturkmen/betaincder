## Welcome

This tiny library contains some C/Cython code for calculating
- the (normalized) incomplete Beta function - `betainc`
- the first derivatives (w.r.t. shape parameters) of the incomplete Beta function
  via the INBEDER algorithm
- the digamma (Psi) function, the beta function and its logarithm (`betaln`)

## API

- **`beta(p, q)`**: Calculate the Beta function, where `B(p,q) = Gamma(p)*Gamma(q)/Gamma(p+q)`
- **`betaln(p, q)`**: Calculate the logarithm of the Beta function, where `betaln(p,q) = ln B(p,q) = ln Gamma(p) + ln Gamma(q) - ln Gamma(p+q)`
- **`betainc(x, p, q)`**: Calculate the regularized incomplete Beta function, where `betainc(x, p, q) = I_x(p, q)`. See http://mathworld.wolfram.com/IncompleteBetaFunction.html
- **`betaincderp(x, p, q)`**: Compute the first derivative of the regularized incomplete Beta function with respect to the first shape parameter ``p``.
- **`betaincderq(x, p, q)`**: First derivative of the regularized incomplete Beta function with respect to the second shape parameter ``q``.
- **`digamma(x)`**: The digamma function. See http://mathworld.wolfram.com/DigammaFunction.html.

## Installation

```bash
$ pip install betaincder
```

## Usage

The functions can be invoked from python, or `cimport`ed from Cython.

```python
from betaincder import betainc, betaincderp, betaincderq
print betaincderq(.5, 10, 10)
```

or

```python
%%cython 
from betaincder.c.betaincder cimport digamma, betaln, betainc, betaincderq
print betaincderq(.5, 10, 10)
```

## References
- Robinson-Cox, J. F., & Boik, R. J. (1998). Derivatives of the Incomplete Beta Function. Journal of Statistical Software, 3(01).
- Bernardo, Jose M. "Algorithm AS 103: Psi (digamma) function." Journal of the Royal Statistical Society. Series C (Applied Statistics) 25.3 (1976): 315-317.
