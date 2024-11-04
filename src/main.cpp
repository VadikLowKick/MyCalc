#include <iostream>
#include "calculator.h"

int main() {
    Calculator calc;
    double a, b;
    char op;

    std::cout << "Enter an expression (e.g., 3 + 4): ";
    std::cin >> a >> op >> b;

    try {
        double result;
        switch (op) {
            case '+':
                result = calc.add(a, b);
                break;
            case '-':
                result = calc.subtract(a, b);
                break;
            case '*':
                result = calc.multiply(a, b);
                break;
            case '/':
                result = calc.divide(a, b);
                break;
            default:
                std::cerr << "Unknown operator: " << op << std::endl;
                return 1;
        }
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
