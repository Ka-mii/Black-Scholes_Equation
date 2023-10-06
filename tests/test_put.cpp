#include "../headers/put.hpp" // Include the header for your put class
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>

/**
 * @brief Test case for the put option payoff when S equals 0
*/
void testPutPayoff_S_EqualsTo_0() {
    double K = 100.0;
    double T = 1;
    double r = 0.1;
    double L = 300.0;
    
    Put putOption(K, T, r, L);

    double t = 0.5;
    double S = 0.0;
    double result = putOption(t, S);
    double expectedResult = K*std::exp(-r*(T-t));

    assert(abs(result - expectedResult) < 1e-6);
}

/**
 * @brief Test case for the put option payoff when S equals L
*/
void testPutPayoff_S_EqualsTo_L() {
    double K = 100.0;
    double T = 1;
    double r = 0.1;
    double L = 300.0;

    Put putOption(K, T, r, L);

    double t = 0.5;
    double S = L;
    double result = putOption(t, S);
    double expectedResult = 0.0;

    assert(abs(result - expectedResult) < 1e-6);
}

/**
 * @brief Test case for the put option payoff
*/
void testPutPayoff_default() {
    double K = 100.0;
    double T = 1;
    double r = 0.1;
    double L = 300.0;

    Put putOption(K, T, r, L);

    double t = 0.5;
    double S = 120.0;
    double result = putOption(t, S);

    double expectedResult = std::max(0.0, K - S);
    assert(abs(result - expectedResult) < 1e-6);
}

int main() {
    std::cout << "Running unit tests...\n";

    testPutPayoff_S_EqualsTo_0();
    testPutPayoff_S_EqualsTo_L();
    testPutPayoff_default();

    std::cout << "All tests passed!\n";
    return 0;
}
