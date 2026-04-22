#include "includes/fractions.h"
#include <iostream>
#include <cmath>

using namespace frc;
using namespace std;

Fraction f1 = Fraction(5, -10);
Fraction f2 = Fraction(1, 8);
Fraction f3 = 10;
Fraction f4 = Fraction(2, 3);
Fraction f5 = Fraction(13, 5);
Fraction f6 = Fraction(32, 3);

int main() {
    AUTO_SIMPLIFY = true;
    cout << floor(f1) << endl;

    return 0;
}