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

#include <math.h>

double betaln(double p, double q){
  return lgamma(p) + lgamma(q) - lgamma(p + q);
}

double beta(double p, double q){
  return exp(lgamma(p) + lgamma(q) - lgamma(p + q));
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

double betainc(double x, double p, double q, int ord){

    double Am2 = 1, Am1 = 1;
    double Bm2 = 0, Bm1 = 1;
    double a_n_, b_n_, K, A, B;

    if (x > p/(p+q))
      return 1 - betainc(1-x, q, p, ord);

    K = exp(p * log(x) + (q - 1) * log(1 - x) - log(p) - betaln(p, q));

    for (int n = 1; n < ord + 1; n++) {
      a_n_ = a_n(x, p, q, n);
      b_n_ = b_n(x, p, q, n);

      A = Am2 * a_n_ + Am1 * b_n_;
      B = Bm2 * a_n_ + Bm1 * b_n_;

      Am2 = Am1;    Am1 = A;    Bm2 = Bm1;    Bm1 = B;
    }

    return K * A / B;
}
