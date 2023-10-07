#include "../headers/interface.hpp"
#include "../headers/call.hpp"
#include "../headers/put.hpp"
#include "../headers/payoff.hpp"
#include <stdexcept>

void runCalculation(double K, double T, double r, double L, double sigma, bool reducedEquation, bool call)
{
    Payoff *payoff = nullptr;

    if(call)
    {
        payoff = new Call(K, T, r, L);
    }
    else
    {
        payoff = new Put(K, T, r, L);
    }

    delete payoff;
    payoff = nullptr;
}