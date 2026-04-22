#include "../includes/fractions.h"
#include "helpers.h"
#include <string>
#include <sstream>

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

    std::string Fraction::str(const FractionType& type) const {
        switch(type) {
            case Common:
                return std::to_string(numerator) + "/" + std::to_string(denominator);
                break;
            case Decimal: {
                std::ostringstream oss;
                oss << float(*this);
                return oss.str();
                break;
            }
            case Mixed:
                return std::to_string(this->getWhole()) + " | " + std::to_string(this->getRemainder().getNumerator()) + "/" + std::to_string(denominator);
                break;
            default:
                return "Unknown type!";
                break;
        }
    }

    std::string to_string(const Fraction& f, const FractionType& type) {
        return f.str(type);
    }
}