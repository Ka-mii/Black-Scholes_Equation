#ifndef INTERFACE_HPP
#define INTERFACE_HPP

/**
 * @brief Runs the calculation and displays the result.
 * 
 * @param T Time to maturity.
 * @param r Risk-free interest rate.
 * @param sigma Volatility.
 * @param K Strike price.
 * @param L Upper bound of the domain.
 * @param reducedEquation Use the reduced equation.
 * @param call Computes a call instead of a put.
 * @throws Exception.
 */
void runCalculation(double K, double T, double r, double L, double sigma, bool reducedEquation, bool call);

#endif // INTERFACE_HPP