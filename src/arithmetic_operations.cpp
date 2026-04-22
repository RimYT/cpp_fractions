#include "../includes/fractions.h"
#include "helpers.h"

namespace frc {
    Fraction operator + (const Fraction& f1, const Fraction& f2) {
        long f1_num = f1.getNumerator();
        long f1_den = f1.getDenominator();

        long f2_num = f2.getNumerator();
        long f2_den = f2.getDenominator();

        if(f1_den == f2_den) {
            Fraction f = Fraction(f1_num + f2_num, f1_den);
            return simplifyIfNeeded(f);
        }

        long common = lcm(f1_den, f2_den);
        long f1_mul = common / f1_den;
        long f2_mul = common / f2_den;

        Fraction f = Fraction((f1_num * f1_mul) + (f2_num * f2_mul), common);
        return simplifyIfNeeded(f);
    }

    Fraction operator - (const Fraction& f1, const Fraction& f2) {
        long f1_num = f1.getNumerator();
        long f1_den = f1.getDenominator();

        long f2_num = f2.getNumerator();
        long f2_den = f2.getDenominator();

        if(f1_den == f2_den) {
            Fraction f = Fraction(f1_num - f2_num, f1_den);
            return simplifyIfNeeded(f);
        }

        long common = lcm(f1_den, f2_den);
        long f1_mul = common / f1_den;
        long f2_mul = common / f2_den;

        Fraction f = Fraction((f1_num * f1_mul) - (f2_num * f2_mul), common);
        return simplifyIfNeeded(f);
    }

    Fraction operator * (const Fraction& f1, const Fraction& f2) {
        long f1_num = f1.getNumerator();
        long f1_den = f1.getDenominator();

        long f2_num = f2.getNumerator();
        long f2_den = f2.getDenominator();

        Fraction f = Fraction(f1_num * f2_num, f1_den * f2_den);
        return simplifyIfNeeded(f);
    }

    Fraction operator / (const Fraction& f1, const Fraction& f2) {
        long f1_num = f1.getNumerator();
        long f1_den = f1.getDenominator();

        long f2_num = f2.getNumerator();
        long f2_den = f2.getDenominator();

        Fraction f = Fraction(f1_num * f2_den, f1_den * f2_num);
        return simplifyIfNeeded(f);
    }

    // -------- Assignment Operations --------
    Fraction& Fraction::operator += (const Fraction& f) {
        *this = (*this) + f;
        return *this;
    }

    Fraction& Fraction::operator -= (const Fraction& f) {
        *this = (*this) - f;
        return *this;
    }

    Fraction& Fraction::operator *= (const Fraction& f) {
        *this = (*this) * f;
        return *this;
    }

    Fraction& Fraction::operator /= (const Fraction& f) {
        *this = (*this) / f;
        return *this;
    }

    // -------- Math Functions --------
    Fraction pow(const Fraction& base, const long& exponent) {
        Fraction f = Fraction(std::pow(base.getNumerator(), exponent), std::pow(base.getDenominator(), exponent));
        return simplifyIfNeeded(f);
    }

    Fraction abs(const Fraction& f) {
        Fraction f_abs = Fraction(std::abs(f.getNumerator()), f.getDenominator());
        return simplifyIfNeeded(f_abs);
    }
}