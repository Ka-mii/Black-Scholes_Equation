#ifndef CALL_HPP
#define CALL_HPP

#include "payoff.hpp"

/**
 * @brief Call option payoff.
 * 
 */
class Call : public Payoff
{
public:
    /**
     * @brief Construct a new Call object.
     * 
     * @param K Strike price.
     * @param T Time to maturity.
     * @param r Risk free interest rate.
     * @param L Upper bound of the domain.
     */
    Call(double K, double T, double r, double L);

    /**
     * @brief Destroy the Call object.
     * 
     */
    virtual ~Call();

    /**
     * @brief Overrides {@link Payoff} function.
     * 
     * @param t Time.
     * @param S Asset price.
     * @return double Price.
     */
    virtual double operator()(double t, double S) override;
};

#endif //CALL_HPP