/*
  Compute the beta and log-beta functions as well as approximations to the
  incomplete Beta function, and the derivatives of the regularized incomplete
  beta function with respect to shape parameters. For reference of the
  approximations of the regularized incomplete beta function and its derivatives
  see

  Robinson-Cox, J. F., & Boik, R. J. (1998). Derivatives of the Incomplete Beta
  Function. Journal of Statistical Software, 3(01).

  Author: Caner Turkmen <caner.turkmen@boun.edu.tr>
*/
#include "betaincder.h"
#include <math.h>

double _betaln(double p, double q){
  return lgamma(p) + lgamma(q) - lgamma(p + q);
}

double _beta(double p, double q){
  return exp(_betaln(p, q));
}

double a_n(double x, double p, double q, int n){
  double f, F1, F2;

  f = q * x / (p * (1 - x));

  if(n == 1)
    return p * f * (q - 1) / (q * (p + 1));

  F1 = p*p*f*f*(n-1) / (q*q);
  F2 = (p+q+n-2)*(p+n-1)*(q-n)/((p+2*n-3) * (p+2*n-2) * (p+2*n-2) * (p+2*n-1));
  return F1 * F2;
}

double b_n(double x, double p, double q, int n){
  double f, N1, D1;

  f = q * x / (p * (1 - x));

  N1 = 2 * (p*f + 2*q) * n * (n+p-1) + p*q*(p-2-p*f);
  D1 = q*(p + 2*n - 2)*(p + 2*n);
  return N1/D1;
}

double _betainc(double x, double p, double q, int ord){

    double Am2 = 1, Am1 = 1;
    double Bm2 = 0, Bm1 = 1;
    double a_n_, b_n_, K, A, B;

    if (x > p/(p+q))
      return 1 - _betainc(1-x, q, p, ord);

    K = exp(p * log(x) + (q - 1) * log(1 - x) - log(p) - _betaln(p, q));

    for (int n = 1; n < ord + 1; n++) {
      a_n_ = a_n(x, p, q, n);
      b_n_ = b_n(x, p, q, n);

      A = Am2 * a_n_ + Am1 * b_n_;
      B = Bm2 * a_n_ + Bm1 * b_n_;

      Am2 = Am1;    Am1 = A;    Bm2 = Bm1;    Bm1 = B;
    }

    return K * A / B;
}

double _da_n_dp(double x, double p, double q, int n){
    double f, p2n3, N1, N2a, N2b, N2c, N2d, N2e, D;

    f = (q * x) / (p * (1-x));

    if(n == 1)
      return - p*f*(q-1) / (q*(p+1)*(p+1));

    p2n3 = p + 2*n - 3;

    N1 = -(n-1) * f*f * p*p * (q-n)  / (q*q * pow(p2n3, 2));

    N2a = (-8 + 8*p + 8*q) * n*n*n;
    N2b = (16*p*p + (-44+20*q)*p + 26 - 24*q) * n*n;
    N2c = (10*p*p*p + (14*q - 46)*p*p + (-40*q + 66)*p - 28 + 24*q)*n;
    N2d = 2*p*p*p*p + (-13 + 3*q)*p*p*p + (-14*q + 30)*p*p;
    N2e = (-29 + 19*q)*p + 10 - 8*q;

    D = pow(p2n3 + 1, 3) * pow(p2n3 + 2, 2);

    return (N2a + N2b + N2c + N2d + N2e) / D * N1;
}

double _da_n_dq(double x, double p, double q, int n){
    double f, N1, D;
    f = (q * x) / (p * (1-x));

    if(n == 1)
        return p * f / (q * (p + 1));

    N1 = (p*p * f*f / (q*q)) * (n-1) * (p+n-1) * (2*q+p-2);
    D = (p+2*n-3) * (p+2*n-2)*(p+2*n-2) * (p+2*n-1);
    return N1 / D;
}

double _db_n_dp(double x, double p, double q, int n){
    double f, N1, D;
    f = (q * x) / (p * (1-x));

    N1 = (p*f/q) * ((-4*p - 4*q + 4)*n*n + (4*p - 4 + 4*q - 2*p*p)*n + p*p * q);
    D = (p+2*n-2)*(p+2*n-2) * (p+2*n)*(p+2*n);
    return N1 / D;
}

double _db_n_dq(double x, double p, double q, int n){
    double f;
    f = (q * x) / (p * (1-x));

    return -(p*p * f) / (q * (p + 2*n - 2) * (p + 2*n));
}

double _betaincderp(double x, double p, double q, int ord){
    double Am2 = 1 , Am1 = 1 , A;
    double Bm2 = 0 , Bm1 = 1 , B;
    double dAm2 = 0, dAm1 = 0, dA;
    double dBm2 = 0, dBm1 = 0, dB;
    double a_n_, b_n_, K, F1;
    double da_n_dp, db_n_dp;

    if (x == 0)
      return 0;

    if (x > p/(p+q))
      return -_betaincderq(1-x, q, p, ord);

    K = exp(p * log(x) + (q - 1) * log(1 - x) - log(p) - _betaln(p, q));

    for (int n = 1; n < ord + 1; n++) {
      a_n_ = a_n(x, p, q, n);
      b_n_ = b_n(x, p, q, n);
      da_n_dp = _da_n_dp(x, p, q, n);
      db_n_dp = _db_n_dp(x, p, q, n);

      A = Am2 * a_n_ + Am1 * b_n_;
      dA = da_n_dp * Am2 + a_n_ * dAm2 + db_n_dp * Am1 + b_n_ * dAm1;
      B = Bm2 * a_n_ + Bm1 * b_n_;
      dB = da_n_dp * Bm2 + a_n_ * dBm2 + db_n_dp * Bm1 + b_n_ * dBm1;

      Am2 = Am1;  Am1 = A;  dAm2 = dAm1;  dAm1 = dA;
      Bm2 = Bm1;  Bm1 = B;  dBm2 = dBm1;  dBm1 = dB;
    }

    F1 = A / B * (log(x) - 1/p + _digamma(p+q) - _digamma(p)) + dA/B - A*dB/(B*B);
    return K * F1;
}

double _betaincderq(double x, double p, double q, int ord){
    double Am2 = 1 , Am1 = 1 , A;
    double Bm2 = 0 , Bm1 = 1 , B;
    double dAm2 = 0, dAm1 = 0, dA;
    double dBm2 = 0, dBm1 = 0, dB;
    double a_n_, b_n_, K, F1;
    double da_n_dq, db_n_dq;

    if (x == 0)
      return 0;

    if (x > p/(p+q))
      return -_betaincderp(1-x, q, p, ord);

    K = exp(p * log(x) + (q - 1) * log(1 - x) - log(p) - _betaln(p, q));

    for (int n = 1; n < ord + 1; n++) {
      a_n_ = a_n(x, p, q, n);
      b_n_ = b_n(x, p, q, n);
      da_n_dq = _da_n_dq(x, p, q, n);
      db_n_dq = _db_n_dq(x, p, q, n);

      A = Am2 * a_n_ + Am1 * b_n_;
      dA = da_n_dq * Am2 + a_n_ * dAm2 + db_n_dq * Am1 + b_n_ * dAm1;
      B = Bm2 * a_n_ + Bm1 * b_n_;
      dB = da_n_dq * Bm2 + a_n_ * dBm2 + db_n_dq * Bm1 + b_n_ * dBm1;

      Am2 = Am1;  Am1 = A;  dAm2 = dAm1;  dAm1 = dA;
      Bm2 = Bm1;  Bm1 = B;  dBm2 = dBm1;  dBm1 = dB;
    }

    F1 = A / B * (log(1-x) + _digamma(p+q) - _digamma(q)) + dA/B - A*dB/(B*B);
    return K * F1;
}
