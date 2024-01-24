#include <iostream>
#include <cstring>

#include "../headers/payoff.hpp"
#include "../headers/call.hpp"
#include "../headers/put.hpp"
#include "../headers/interface.hpp"
#include "../headers/utils.hpp"

// using namespace std;

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

    // Création d'une matrice 3x3
    Matrix A(3, 3);

    // Remplissage de la matrice A
    A.set(0, 0, 2); A.set(0, 1, 1); A.set(0, 2, 2);
    A.set(1, 0, 1); A.set(1, 1, 3); A.set(1, 2, 2);
    A.set(2, 0, 2); A.set(2, 1, 2); A.set(2, 2, 4);

    // Définition du vecteur b
    std::vector<double> b = {4, 5, 6};

    // // Résolution du système Ax = b
    std::vector<double> x = A.solve(b);

    // Affichage de la solution
    std::cout << "Solution x: ";
    for (double xi : x) {
        std::cout << xi << " ";
    }
    std::cout << std::endl;

/* ----------------------------------------------------------------- */

    // Création d'une matrice tridiagonale 3x3
    TridiagonalMatrix TM(3);

    // Remplissage de la matrice tridiagonale A

    // Diagonale principale
    TM.set(0, 0, 2); TM.set(1, 1, 3); TM.set(2, 2, 4);
    // Sous-diagonale
    TM.set(1, 0, 1); TM.set(2, 1, 2);
    // Sur-diagonale
    TM.set(0, 1, 1); TM.set(1, 2, 2);

    // Définition du vecteur b
    std::vector<double> TM_b = {4, 5, 6};

    // Résolution du système Ax = b
    std::vector<double> TM_x = TM.solve(TM_b);

    // Affichage de la solution
    std::cout << "Solution TM_x: ";
    for (double xi : TM_x) {
        std::cout << xi << " ";
    }
    std::cout << std::endl;

    // return 0;

/*     if (argc == 1)
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
            cout << "  <T>: Price of the underlying share." << endl;
            cout << "  <r>: Risk-free interest rate." << endl;
            cout << "  <sigma>: Volatility." << endl;
            cout << "  <M>: Strike price." << endl;
            cout << "  <Steps>: Lower bound of the domain." << endl;
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
    } */

}