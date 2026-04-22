#include "../includes/fractions.h"
#include "helpers.h"

namespace frc {
    Fraction from_float(float num) {
        long den = 1;

        while(num - (long)num > 0) {
            num *= 10;
            den *= 10;
        }
        Fraction f = Fraction(num, den);
        return simplifyIfNeeded(f);
    }

    Fraction inverse(const Fraction& f) {
        Fraction f_new = Fraction(f.getDenominator(), f.getNumerator());
        return simplifyIfNeeded(f_new);
    }
}