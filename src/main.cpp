#include <iostream>
#include <cstring>

#include "../headers/payoff.hpp"
#include "../headers/call.hpp"
#include "../headers/put.hpp"
#include "../headers/interface.hpp"

using namespace std;

/**
 * @brief Main function
 * 
 * @param argc Number of arguments
 * @param argv List of parameters
 * @return int Final error Code
*/
int main(int argc, char *argv[])
{
    bool reducedEquation = false;
    bool call = false;

    double T, r, sigma, K, L;

    if (argc == 1)
    {
        cout << "Usage: " << argv[0] << " [-r|--reduced] [-c|--call] <T> <r> <sigma> <K> <L>" << endl;
        return 0;
    }

    // Scanning arguments
    for (int i=0; i<argc; i++)
    {
        if (!strcmp(argv[i], "-r") || !strcmp(argv[i], "--reduced"))
        {
            reducedEquation = true;
        }
        else if (!strcmp(argv[i], "-c") || !strcmp(argv[i], "--call"))
        {
            call = true;
        }
        else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
        {
            cout << "Usage: " << argv[0] << " [-r|--reduced] [-c|--call] <T> <r> <sigma> <K> <L>" << endl;
            cout << "  -r, --reduced: Use the reduced equation." << endl;
            cout << "  -c, --call: Compute the call price instead of put price." << endl;
            cout << "  -h, --help: Display this help." << endl;
            cout << "  <T>: Time to maturity." << endl;
            cout << "  <r>: Risk-free interest rate." << endl;
            cout << "  <sigma>: Volatility." << endl;
            cout << "  <K>: Strike price." << endl;
            cout << "  <L>: Lower bound of the domain." << endl;
            return 0;
        }
    }

    // Setting initial values
    if (sscanf(argv[argc - 5], "%lf", &T) != 1)
    {
        cout << "Error: Invalid value for T." << endl;
        return 1;
    }
    if (sscanf(argv[argc - 4], "%lf", &r) != 1)
    {
        cout << "Error: Invalid value for r." << endl;
        return 1;
    }
    if (sscanf(argv[argc - 3], "%lf", &sigma) != 1)
    {
        cout << "Error: Invalid value for sigma." << endl;
        return 1;
    }
    if (sscanf(argv[argc - 2], "%lf", &K) != 1)
    {
        cout << "Error: Invalid value for K." << endl;
        return 1;
    }
    if (sscanf(argv[argc - 1], "%lf", &L) != 1)
    {
        cout << "Error: Invalid value for L." << endl;
        return 1;
    }

    try
    {
        runCalculation(K, T, r, L, sigma, reducedEquation, call);
    }
    catch(const std::exception& e)
    {
        std::cerr << argv[0] << ": " << e.what() << '\n';
        return 1;
    }

}