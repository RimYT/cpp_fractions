#include "includes/fractions.h"
#include <iostream>

using namespace frc;
using namespace std;

Fraction f1 = Fraction(5, -10);
Fraction f2 = Fraction(1, 8);
Fraction f3 = 10;
Fraction f4 = Fraction(2, 3);
Fraction f5 = Fraction(13, 5);

int main() {
    AUTO_SIMPLIFY = true;
    sum(95, floatToFraction(3.5)).print(Mixed);
    return 0;
}