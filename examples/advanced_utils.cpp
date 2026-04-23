#include <iostream>
#include "fractions.h"

int main() {
    try {
        // Conversion from float
        float pi_approx = 3.14f;
        frc::Fraction f_pi = frc::from_float(pi_approx);
        std::cout << "3.14 as fraction: " << f_pi << std::endl;
        f_pi.simplify();
        std::cout << "3.14 as simplified fraction: " << f_pi << std::endl;

        // Comparison operators
        frc::Fraction f1(1, 2);
        frc::Fraction f2(2, 4);
        
        if (f1 == f2) {
            std::cout << f1 << " is equal to " << f2 << std::endl;
        }

        // Floor/Ceil/Round
        frc::Fraction f3(7, 3); // 2.333...
        std::cout << "Floor of 7/3: " << frc::floor(f3) << std::endl;
        std::cout << "Ceil of 7/3: " << frc::ceil(f3) << std::endl;
        std::cout << "Round of 7/3: " << frc::round(f3) << std::endl;

        frc::Fraction f4(1, 2); // 0.5
        std::cout << "Floor of 1/2: " << frc::floor(f4) << std::endl;
        std::cout << "Ceil of 1/2: " << frc::ceil(f4) << std::endl;
        std::cout << "Round of 1/2: " << frc::round(f4) << std::endl;

        // Error handling
        std::cout << "Trying to create a fraction with zero denominator..." << std::endl;
        frc::Fraction bad_fraction(1, 0);

    } catch (const std::runtime_error& e) {
        std::cerr << "Caught error: " << e.what() << std::endl;
    }

    return 0;
}