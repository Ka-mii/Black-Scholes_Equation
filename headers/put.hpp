#ifndef PUT_H
#define PUT_H

#include "payoff.hpp"

/**
 * @brief Put option payoff.
 * 
 */
class Put : public Payoff
{
public:
    /**
     * @brief Construct a new Put object.
     * 
     * @param K Strike price.
     * @param T Time to maturity.
     * @param r Risk free interest rate.
     * @param L Upper bound of the domain.
     */
    Put(double K, double T, double r, double L);

    /**
     * @brief Destroy the Put object.
     * 
     */
    virtual ~Put();

    /**
     * @brief Overrides {@link Payoff} function.
     * 
     * @param t Time.
     * @param S Asset price.
     * @return double Price.
     */
    virtual double operator()(double t, double S) override;
};

#endif //PUT_H