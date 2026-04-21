#include "../includes/fractions.h"
#include "helpers.h"

namespace frc {
    Fraction sum(const Fraction& f1, const Fraction& f2) {
        long f1_num = f1.getNumerator();
        long f1_den = f1.getDenominator();

        long f2_num = f2.getNumerator();
        long f2_den = f2.getDenominator();

        if(f1_den == f2_den) {
            Fraction f = Fraction(f1_num + f2_num, f1_den);
            simplifyIfNeeded(f);
            return f;
        }

        long common = lcm(f1_den, f2_den);
        long f1_mul = common / f1_den;
        long f2_mul = common / f2_den;

        Fraction f = Fraction((f1_num * f1_mul) + (f2_num * f2_mul), common);
        simplifyIfNeeded(f);
        return f;
    }

    Fraction subtract(const Fraction& f1, const Fraction& f2) {
        long f1_num = f1.getNumerator();
        long f1_den = f1.getDenominator();

        long f2_num = f2.getNumerator();
        long f2_den = f2.getDenominator();

        if(f1_den == f2_den) {
            Fraction f = Fraction(f1_num - f2_num, f1_den);
            simplifyIfNeeded(f);
            return f;
        }

        long common = lcm(f1_den, f2_den);
        long f1_mul = common / f1_den;
        long f2_mul = common / f2_den;

        Fraction f = Fraction((f1_num * f1_mul) - (f2_num * f2_mul), common);
        simplifyIfNeeded(f);
        return f;
    }

    Fraction multiply(const Fraction& f1, const Fraction& f2) {
        long f1_num = f1.getNumerator();
        long f1_den = f1.getDenominator();

        long f2_num = f2.getNumerator();
        long f2_den = f2.getDenominator();

        Fraction f = Fraction(f1_num * f2_num, f1_den * f2_den);
        simplifyIfNeeded(f);
        return f;
    }

    Fraction divide(const Fraction& f1, const Fraction& f2) {
        long f1_num = f1.getNumerator();
        long f1_den = f1.getDenominator();

        long f2_num = f2.getNumerator();
        long f2_den = f2.getDenominator();

        Fraction f = Fraction(f1_num * f2_den, f1_den * f2_num);
        simplifyIfNeeded(f);
        return f;
    }
}