#include "fractions.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace frc {
    //  -------- handlers --------
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
    Fraction simplifyIfNeeded(Fraction f) {
        if(AUTO_SIMPLIFY) {f.simplify();}
        return f;
    }

    //  -------- "class" funcs --------
    long Fraction::getNumerator() const {
        return numerator;
    }

    long Fraction::getDenominator() const {
        return denominator;
    }

    Fraction Fraction::power(long exponent) {
        Fraction f = Fraction(pow(numerator, exponent), pow(denominator, exponent));
        return simplifyIfNeeded(f);
    }

    Fraction Fraction::abs() {
        Fraction f = Fraction(std::abs(numerator), std::abs(denominator));
        return simplifyIfNeeded(f);
    }

    long Fraction::getWhole() {
        return numerator / denominator;
    }

    Fraction Fraction::getRemainder() {
        return Fraction(numerator % denominator, denominator);
    }

    Fraction Fraction::inverse() {
        long num = numerator;
        long den = denominator;

        Fraction f = Fraction(den, num);
        return simplifyIfNeeded(f);
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

    Fraction floatToFraction(float num) {
        long den = 1;

        while(num - (long)num > 0) {
            num *= 10;
            den *= 10;
        }
        Fraction f = Fraction(num, den);
        return simplifyIfNeeded(f);
    }

    // -------- compare operations --------
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

    // -------- arithmetic operations --------
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

