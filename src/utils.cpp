#include "../headers/utils.hpp"

#include <vector>
#include <stdexcept>
#include <iostream>

void Matrix::decomposeLU(std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U) const {
    int n = data.size();
    L.resize(n, std::vector<double>(n, 0));
    U.resize(n, std::vector<double>(n, 0));

    for (int i = 0; i < n; i++) {
        // Calcul de U
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = data[i][k] - sum;
        }

        // Calcul de L
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1; // Diagonale comme 1
            else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += (L[k][j] * U[j][i]);
                }
                L[k][i] = (data[k][i] - sum) / U[i][i];
            }
        }
    }
}

std::vector<double> Matrix::solve(const std::vector<double>& b) const {
    if (data.size() != b.size()) {
        throw std::invalid_argument("La dimension de b ne correspond pas à la matrice.");
    }

    int n = data.size();
    std::vector<std::vector<double>> L, U;
    decomposeLU(L, U);

    // Résolution de Ly = b
    std::vector<double> y(n, 0);
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    // Résolution de Ux = y
    std::vector<double> x(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }

    return x;
}

void TridiagonalMatrix::decomposeLU(std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U) const {
    int n = data.size();
    L.resize(n, std::vector<double>(n, 0));
    U.resize(n, std::vector<double>(n, 0));
    double sk;
    double s0=1, s1=data[0][0];

    for (int i = 2; i <= n; i++) {
        L[i-2][i-2] = 1;
        L[i-1][i-2] = data[i-1][i-2] * s0/s1;
        U[i-2][i-2] = s1/s0;
        U[i-2][i-1] = data[i-2][i-1];

        sk = data[i-1][i-1]*s1 - data[i-1][i-2]*data[i-2][i-1]*s0;
        s0 = s1;
        s1 = sk;
    }
    L[n-1][n-1] = 1;
    U[n-1][n-1] = s1/s0;
}
