#include <iostream>
#include "fractions.h"

int main() {
    // Enable automatic simplification for all new fractions
    frc::AUTO_SIMPLIFY = true;

    frc::Fraction a(1, 2);
    frc::Fraction b(1, 4);

    // Basic arithmetic
    frc::Fraction sum = a + b;         // 3/4
    frc::Fraction prod = a * b;        // 1/8
    
    std::cout << a << " + " << b << " = " << sum << std::endl;
    std::cout << a << " * " << b << " = " << prod << std::endl;

    // Compound assignment
    frc::Fraction c(2, 6);             // Will be simplified to 1/3 immediately
    std::cout << "Simplified 2/6: " << c << std::endl;

    c += frc::Fraction(2, 3);          // 1/3 + 2/3 = 1/1
    std::cout << "1/3 after adding 2/3: " << c << std::endl;

    // Power function
    frc::Fraction base(2, 3);
    frc::Fraction result = frc::pow(base, 2);
    std::cout << "(2/3)^2 = " << result << std::endl; // 4/9

    return 0;
}