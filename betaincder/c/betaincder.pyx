cimport cython

cdef extern from "betaincder.h":
    double _digamma(double x)
    double _beta(double p, double q)
    double _betaln(double p, double q)
    double _betainc(double x, double p, double q, int ord)
    double _betaincderp(double x, double p, double q, int ord)
    double _betaincderq(double x, double p, double q, int ord)


def digamma(double p, double q):
    return _digamma(p, q)


def beta(double p, double q):
    return _beta(p, q)


def betaln(double p, double q):
    return _betaln(p, q)


def betainc(double x, double p, double q):
    return _betainc(x, p, q, 100)


def betaincderp(double x, double p, double q):
    return _betaincderp(x, p, q, 100)


def betaincderq(double x, double p, double q):
    return _betaincderq(x, p, q, 100)
