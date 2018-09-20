#ifndef __BETAINCDER_H__
#define __BETAINCDER_H__

double _digamma(double x);
double _beta(double p, double q);
double _betaln(double p, double q);
double _betainc(double x, double p, double q, int ord);
double _betaincderp(double x, double p, double q, int ord);
double _betaincderq(double x, double p, double q, int ord);

#endif
