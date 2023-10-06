#ifndef PAYOFF_HPP
#define PAYOFF_HPP

/**
 * @brief This class provides an interface to build payoff functions.
 * 
 */
class Payoff
{
protected:
    /**
     * @brief Strike price of the option.
     * 
     */
    double K;
    /**
     * @brief Time to maturity of the option.
     * 
     */
    double T;
    /**
     * @brief Risk free interest rate.
     * 
     */
    double r;
    /**
     * @brief Lower bound of the domain of the option.
     * 
     */
    double L;
public:
    /**
     * @brief Construct a new Payoff object.
     * 
     * @param K Strike price.
     * @param T Time to maturity.
     * @param r Risk free interest rate.
     * @param L Lower bound of the domain.
     */
    Payoff(double K, double T, double r, double L);
    /**
     * @brief Destroy the Payoff object.
     * 
     */
    virtual ~Payoff() {};

    /**
     * @brief Computes the conditions of the payoff function.
     * 
     * @param t Time.
     * @param S Stock price.
     * @return double Value of the condition.
     */
    virtual double operator()(double t, double S) = 0;

    /**
     * @brief Computes the payoff function.
     * 
     * @param t Time.
     * @param S Stock price.
     * @return double Value of the payoff function.
     */
    double C(double t, double S) { return (*this)(t, S); }

    /**
     * @brief Get the Strike object.
     * 
     * @return double Strike price.
     */
    double get_K() const { return K; };

    /**
     * @brief Get the Time To Maturity object.
     * 
     * @return double Time to maturity.
     */
    double get_T() const { return T; };

    /**
     * @brief Get the Risk Free Interest Rate object.
     * 
     * @return double Risk free interest rate.
     */
    double get_r() const { return r; };

    /**
     * @brief Get the Lower Bound Domain object.
     * 
     * @return double Lower bound of the domain.
     */
    double get_L() const { return L; };
};

#endif //PAYOFF_HPP