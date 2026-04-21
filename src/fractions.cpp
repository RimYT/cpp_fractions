#include "fractions.h"
#include <iostream>
#include <numeric>
#include <string>
#include <stdexcept>
#include <cmath>

namespace frc {
    // handlers
    long gcd(long a, long b) {
        a = std::abs(a);
        b = std::abs(b);
        long mx = std::max(a, b);
        long mn = std::min(a, b);

        while(true) {
            long t = mx % mn;

            if(t == 0) {
                break;
            } else {
                mx = std::max(t, mn);
                mn = std::min(t, mn);
            }
        }

        return mn;
    }
    long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }
    void simplifyIfNeeded(Fraction &f) {
        if(AUTO_SIMPLIFY) {f.simplify();}
        return;
    }

    // "class" funcs
    long Fraction::getNumerator() {
        return numerator;
    }

    long Fraction::getDenominator() {
        return denominator;
    }

    void Fraction::power(float exponent) {
        numerator = pow(numerator, exponent);
        denominator = pow(denominator, exponent);

        simplifyIfNeeded(*this);
    }

    void Fraction::simplify() {
        long common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

    float Fraction::ToNum() {
        return float(numerator) / denominator;
    }

    void Fraction::print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    // other funcs

    Fraction sumFractions(Fraction f1, Fraction f2) {
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
}

