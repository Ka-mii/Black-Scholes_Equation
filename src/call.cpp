#include "../headers/call.hpp"
#include <cmath>
#include <algorithm>

Call::Call(double K, double T, double r, double L) : Payoff(K, T, r, L)
{

}

Call::~Call()
{

}

double Call::operator()(double t, double S)
{
    if (S == 0)
    {
        return 0.0;
    }
    else if (S == L)
    {
        return K*std::exp(-r*(T-t)); // Cela signifie que si le prix de l'actif sous-jacent atteint L, vous avez le droit d'acheter l'actif à un prix d'exercice (K) et de le vendre au marché, ce qui donne un payoff calculé en fonction du taux d'intérêt sans risque (r) et du temps restant (t - T).
    }
    return std::max(K - S, 0.0);
}