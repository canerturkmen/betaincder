cimport cython

cdef extern from "digamma.c":
    double _digamma(double x)

cdef extern from "beta.c":
    double _beta(double p, double q)
    double _betaln(double p, double q)
    double _betainc(double x, double p, double q, int ord)
    double _betaincderp(double x, double p, double q, int ord)
    double _betaincderq(double x, double p, double q, int ord)


cpdef double digamma(double x):
    """
    Calculate the digamma (psi) function, first logarithmic derivative
    of the Gamma function.
    """
    return _digamma(x)


cpdef double beta(double p, double q):
    """
    Calculate the Beta function, where ``B(p,q) = Gamma(p)*Gamma(q)/Gamma(p+q)``
    """
    return _beta(p, q)


cpdef double betaln(double p, double q):
    """
    Calculate the logarithm of the Beta function, where
    ``betaln(p,q) = ln B(p,q) = ln Gamma(p) + ln Gamma(q) - ln Gamma(p+q)``
    """
    return _betaln(p, q)


cpdef double betainc(double x, double p, double q):
    """
    Calculate the regularized incomplete Beta function, where
    ``betainc(x, p, q) = I_x(p, q)``

    See http://mathworld.wolfram.com/IncompleteBetaFunction.html
    """
    return _betainc(x, p, q, 100)


cpdef double betaincderp(double x, double p, double q):
    """
    Compute the first derivative of the regularized incomplete Beta function
    with respect to the first shape parameter ``p``.

    See ``betainc``.
    """
    return _betaincderp(x, p, q, 100)


cpdef double betaincderq(double x, double p, double q):
    """
    Compute the first derivative of the regularized incomplete Beta function
    with respect to the second shape parameter ``q``.

    See ``betainc``.
    """
    return _betaincderq(x, p, q, 100)
