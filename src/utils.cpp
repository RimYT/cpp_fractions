#include "../includes/fractions.h"
#include "helpers.h"

namespace frc {
    Fraction floatToFraction(float num) {
        long den = 1;

        while(num - (long)num > 0) {
            num *= 10;
            den *= 10;
        }
        Fraction f = Fraction(num, den);
        return simplifyIfNeeded(f);
    }
}