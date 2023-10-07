#ifndef CALCULATION_HPP
#define CALCULATION_HPP

#include "../headers/payoff.hpp"
#include <vector>

/**
 * @brief Runs the complete calculation and displays the result.
 * 
 * @param payoff Payoff to be used.
 * @param sigma Volatility.
 * @param values Ouput vector for the values
 */
void solveComplete(Payoff *payoff, double sigma, std::vector<double> &values);

/**
 * @brief Runs the reduced calculation and displays the result.
 * 
 * @param payoff Payoff to be used.
 * @param sigma Volatility.
 * @param values Ouput vector for the values
 */
void solveReduced(Payoff *payoff, double sigma, std::vector<double> &values);

#endif // CALCULATION_HPP