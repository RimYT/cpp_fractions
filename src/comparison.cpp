#include "../includes/fractions.h"

namespace frc {
    bool isEqual(const Fraction& f1, const Fraction& f2) {
        long f1_num = f1.getNumerator();
        long f1_den = f1.getDenominator();

        long f2_num = f2.getNumerator();
        long f2_den = f2.getDenominator();

        if(f1_num * f2_den == f2_num * f1_den) {
            return true;
        }

        return false;
    }

    bool isGreater(const Fraction& f1, const Fraction& f2) {
        long f1_num = f1.getNumerator();
        long f1_den = f1.getDenominator();

        long f2_num = f2.getNumerator();
        long f2_den = f2.getDenominator();

        if(f1_num * f2_den > f2_num * f1_den) {
            return true;
        }

        return false;
    }

    bool isLess(const Fraction& f1, const Fraction& f2) {
        long f1_num = f1.getNumerator();
        long f1_den = f1.getDenominator();

        long f2_num = f2.getNumerator();
        long f2_den = f2.getDenominator();

        if(f1_num * f2_den < f2_num * f1_den) {
            return true;
        }

        return false;
    }


    bool isPositive(const Fraction& f) {
        long num = f.getNumerator();

        if(num > 0) {
            return true;
        }

        return false;
    }
}