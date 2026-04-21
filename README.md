# Fractions

My "project". The code was written entirely by me. AI and other resources were used only for information, not for writing the code itself

## Table of Contents
* [Project Rules](#project-rules)
  * [Strictly Prohibited](#strictly-prohibited)
  * [Preferred Approach](#preferred-approach-self-reliance)
  * [Permitted Uses](#permitted-uses)
* [Documentation](#documentation)
  * [Enums and Global Variables](#enums-and-global-variables)
  * [Class: frc::Fraction](#class-frcfraction)
  * [Global Functions (namespace frc)](#global-functions-namespace-frc)
    * [Arithmetic & Utility](#arithmetic--utility)
    * [Comparison Operators](#comparison-operators)

## Project Rules

To maximize learning and skill development, this project follows a strict set of personal guidelines:

### STRICTLY PROHIBITED
* **No AI-generated code:** Using AI (like ChatGPT, Copilot, etc.) to write or complete any part of the source code is forbidden
* **No Copy-Pasting:** Searching for and using ready-made code solutions from the internet for project tasks is not allowed

### PREFERRED APPROACH (Self-Reliance)
* **Independent Debugging:** Analyzing and fixing errors on my own before seeking external help
* **Algorithmic Thinking:** Designing logic and algorithms independently (e.g., calculating GCD/LCM, etc.)
* **Mathematical Research:** Manually figuring out the mathematical rules and logic required for the project

### PERMITTED USES
* **Syntax & Language Reference:** Using the internet or AI to understand language syntax, OOP principles, or standard library functions (e.g., `std::max()`)
* **Error Analysis:** Using external tools to help understand a specific error message (though self-analysis is preferred)
* **Algorithm Concepts:** Researching the *theory* behind algorithms (not the code) when necessary (e.g., the logic behind finding GCD/LCM)
* **Mathematical Assistance:** Using resources to clarify mathematical rules (e.g., the process of adding fractions) if stuck

*This project serves as a testament to my personal coding journey and commitment to fundamental learning* </br>
*This file was written by AI, cuz idk how to write .md files xd*

## Documentation

### Enums and Global Variables
| Feature | Type | Description |
| :--- | :--- | :--- |
| `FractionType` | `enum` | Types for printing: `Common`, `Decimal`, `Mixed` |
| `AUTO_SIMPLIFY` | `bool` | Global flag to enable/disable automatic simplification (default: `false`) |

### Class: `frc::Fraction`

| Method | Return Type | Description                                                               |
| :--- | :--- |:--------------------------------------------------------------------------|
| `Fraction(long num, long den)` | Constructor | Creates a fraction. Throws `std::runtime_error` if `den` is 0             |
| `getNumerator()` | `long` | Returns the numerator                                                     |
| `getDenominator()` | `long` | Returns the denominator                                                   |
| `power(long exponent)` | `Fraction` | Returns a new fraction raised to the given power                          |
| `abs()` | `Fraction` | Returns the absolute value of the fraction                                |
| `getWhole()` | `long` | Returns the integer (whole) part of the fraction                          |
| `getRemainder()` | `Fraction` | Returns the remainder after taking the whole part                         |
| `inverse()` | `Fraction` | Returns a new fraction with swapped numerator and denominator             |
| `simplify()` | `void` | Simplifies the fraction in-place                                          |
| `ToNum()` | `float` | Converts the fraction to a floating-point number                          |
| `print(FractionType)` | `void` | Prints the fraction to console using specified format (default: `Common`) |

### Global Functions (namespace `frc`)

#### Arithmetic & Utility
| Function | Return Type | Description                                                     |
| :--- | :--- |:----------------------------------------------------------------|
| `floatToFraction(float)` | `Fraction` | Converts a `float` value into its `Fraction` representation.    |
| `sum(f1, f2)` | `Fraction` | Returns the sum of two fractions (ex.:`f1 + f2`)                |
| `subtract(f1, f2)` | `Fraction` | Returns the difference between two fractions (ex.:`f1 - f2`)    |
| `multiply(f1, f2)` | `Fraction` | Returns the product of two fractions (ex.:`f1 * f2`)            |
| `divide(f1, f2)` | `Fraction` | Returns the result of division of two fractions (ex.:`f1 / f2`) |

#### Comparison Operators
| Function | Return Type | Description                         |
| :--- | :--- |:------------------------------------|
| `isEqual(f1, f2)` | `bool` | Checks if two fractions are equal   |
| `isGreater(f1, f2)` | `bool` | Checks if `f1` is greater than `f2` |
| `isLess(f1, f2)` | `bool` | Checks if `f1` is less than `f2`    |