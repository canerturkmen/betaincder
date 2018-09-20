/*
  Compute an approximation to the digamma function, using the asymptotic
  series expansion. See, e.g.

  Bernardo, Jose M. "Algorithm AS 103: Psi (digamma) function." Journal of the
  Royal Statistical Society. Series C (Applied Statistics) 25.3 (1976): 315-317.

  Author: Caner Turkmen <caner.turkmen@boun.edu.tr>
*/
#include "betaincder.h"
#include <math.h>

#define EMASC 0.577215664901532860606512090082 /* Euler-Mascheroni constant */

double _digamma(double x){
  double xpm2;

  if (x <= 1e-5)
    return -EMASC - (1 / x);

  if (x < 8.5)
    return _digamma(1 + x) - 1 / x;

  xpm2 = pow(x, -2);
  return log(x) - 0.5 / x
         - 0.083333333333333333 * xpm2
         + 0.008333333333333333 * pow(xpm2, 2)
         - 0.003968253968253968 * pow(xpm2, 3)
         + 0.004166666666666667 * pow(xpm2, 4)
         - 0.007575757575757576 * pow(xpm2, 5)
         + 0.021092796092796094 * pow(xpm2, 6);
}
