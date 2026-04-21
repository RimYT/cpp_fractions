#include "src/fractions.h"
#include <iostream>

using namespace frc;
using namespace std;

Fraction f1 = Fraction(5, -10);
Fraction f2 = Fraction(1, 8);
Fraction f3 = 10;
Fraction f4 = Fraction(10, 15);
Fraction f5 = Fraction(2, 3);

int main() {
    AUTO_SIMPLIFY = true;
    cout << isGreater(f5, f4);
    return 0;
}