import unittest as ut

from . import *


class DigammaTests(ut.TestCase):

    def test_digamma_100(self):
        self.assertAlmostEqual(digamma(100), 4.60016185)

    def test_digamma_10(self):
        self.assertAlmostEqual(digamma(10), 2.25175259)

    def test_digamma_1(self):
        self.assertAlmostEqual(digamma(1), -0.57721566)

    def test_digamma_1em1(self):
        self.assertAlmostEqual(digamma(0.1), -10.42375494)

    def test_digamma_small(self):
        self.assertAlmostEqual(digamma(0.000000435), -2298851.15192831)

    def test_digamma_very_small(self):
        self.assertAlmostEqual(digamma(1.77e-15), -5.64971751e14, delta=1e9)

    def test_digamma_very_large(self):
        self.assertAlmostEqual(digamma(2.25e20), 46.8626320760972424443136)


class BetaTests(ut.TestCase):

    def test_beta_1(self):
        self.assertAlmostEqual(beta(1.5, 11.0), 0.02350088552)

    def test_betaln_1(self):
        self.assertAlmostEqual(betaln(1.5, 11.0), -3.75071717649)

    def test_beta_2(self):
        self.assertAlmostEqual(beta(1e3, 1e3), 9.764902039697e-604)

    def test_betaln_2(self):
        self.assertAlmostEqual(betaln(1e3, 1e3), -1388.482601635902)

    def test_beta_3(self):
        self.assertAlmostEqual(beta(1.15e-13, 2.27e-13), 1.31009385175e13, delta=1e5)

    def test_betaln_3(self):
        self.assertAlmostEqual(betaln(1.15e-13, 2.27e-13), 30.20370498612863)


class BetaIncTests(ut.TestCase):
    """values taken from the table in Boik&Robinson-Cox"""

    def test_betainc_1(self):
        self.assertAlmostEqual(betainc(0.001, 1.5, 11.0), 8.9170110943e-04)

    def test_betainc_2(self):
        self.assertAlmostEqual(betainc(0.5, 1.5, 11.0), 9.9861068710e-01)

    def test_betainc_3(self):
        self.assertAlmostEqual(betainc(0.5, 1e3, 1e3), .5)

    def test_betainc_4(self):
        self.assertAlmostEqual(betainc(0.55, 1e3, 1e3), 9.9999631680e-01)

    def test_betainc_at_zero(self):
        self.assertAlmostEqual(betainc(0., 10, 10), 0)

    def test_betainc_at_one(self):
        self.assertAlmostEqual(betainc(1., 10, 10), 1)


class BetaIncDerTests(ut.TestCase):
    """values taken from the table in Boik&Robinson-Cox"""

    def test_betaincdp_1(self):
        self.assertAlmostEqual(betaincderp(0.001, 1.5, 11.0), -4.5720356143e-03)

    def test_betaincdp_2(self):
        self.assertAlmostEqual(betaincderp(0.5, 1.5, 11.0), -2.5501997025e-03)

    def test_betaincdp_3(self):
        self.assertAlmostEqual(betaincderp(0.5, 1e3, 1e3), -8.9224793360e-03)

    def test_betaincdp_4(self):
        self.assertAlmostEqual(betaincderp(0.55, 1e3, 1e3), -3.6713107970e-07)

    def test_betaincdp_at_zero(self):
        self.assertAlmostEqual(betaincderp(0., 10, 10), 0)

    def test_betaincdp_at_one(self):
        self.assertAlmostEqual(betaincderp(1., 10, 10), 0)

    def test_betaincdq_1(self):
        self.assertAlmostEqual(betaincderq(0.001, 1.5, 11.0), 1.1845672718e-04)

    def test_betaincdq_2(self):
        self.assertAlmostEqual(betaincderq(0.5, 1.5, 11.0), 9.0824388310e-04)

    def test_betaincdq_3(self):
        self.assertAlmostEqual(betaincderq(0.5, 1e3, 1e3), 8.9224793360e-03)

    def test_betaincdq_4(self):
        self.assertAlmostEqual(betaincderq(0.55, 1e3, 1e3), 4.0584118313e-07)

    def test_betaincdq_at_zero(self):
        self.assertAlmostEqual(betaincderq(0., 10, 10), 0)

    def test_betaincdq_at_one(self):
        self.assertAlmostEqual(betaincderq(1., 10, 10), 0)
