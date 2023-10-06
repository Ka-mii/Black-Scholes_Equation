#include "../headers/call.hpp" // Include the header for your call class
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>

/**
 * @brief Test case for the call option payoff when S equals 0.
*/
void testCallPayoff_S_EqualsTo_0() {
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double L = 150.0;

    Call callOption(K, T, r, L);

    double t = 0.5;
    double S = 0.0;
    double result = callOption(t, S);
    double expectedResult = 0.0;

    assert(abs(result - expectedResult) < 1e-6);
}

/**
 * @brief Test case for the call option payoff when S equals L.
*/
void testCallPayoff_S_EqualsTo_L() {
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double L = 150.0;

    Call callOption(K, T, r, L);

    double t = 0.5;
    double S = L;
    double result = callOption(t, S);
    double expectedResult = K*std::exp(-r*(T-t));

    assert(abs(result - expectedResult) < 1e-6);
}

/**
 * @brief Test case for the call option payoff.
*/
void testCallPayoff_default() {
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double L = 150.0;

    Call callOption(K, T, r, L);

    double t = 0.5;
    double S = 120.0;
    double result = callOption(t, S);

    double expectedResult = std::max(0.0, K - S);
    assert(abs(result - expectedResult) < 1e-6);
}

int main() {
    std::cout << "Running unit tests...\n";

    testCallPayoff_S_EqualsTo_0();
    testCallPayoff_S_EqualsTo_L();
    testCallPayoff_default();

    std::cout << "All tests passed!\n";
    return 0;
}
