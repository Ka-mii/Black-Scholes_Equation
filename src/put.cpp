#include "../headers/put.hpp"
#include "../headers/payoff.hpp"

#include <cmath>
#include <algorithm>

Put::Put(double K, double T, double r, double L) : Payoff(K, T, r, L)
{

}

Put::~Put()
{

}

double Put::operator()(double t, double S)
{
    if (S == 0)
    {
        return K*std::exp(-r*(T-t));
    }
    else if (S == L)
    {
        return 0.0;
    }
    return std::max(0.0, K - S);
}