#include <gtest/gtest.h>
#include "../src/calculator.h"

TEST(CalculatorTest, Add) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.add(1.0, 2.0), 3.0);
}

TEST(CalculatorTest, Subtract) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.subtract(5.0, 2.0), 3.0);
}

TEST(CalculatorTest, Multiply) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.multiply(3.0, 4.0), 12.0);
}

TEST(CalculatorTest, Divide) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.divide(10.0, 2.0), 5.0);
    EXPECT_THROW(calc.divide(10.0, 0), std::invalid_argument);
}
