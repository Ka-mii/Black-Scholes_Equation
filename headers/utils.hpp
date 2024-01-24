#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <stdexcept>

class Matrix {
protected:
    std::vector<std::vector<double>> data;

    // Méthode pour effectuer la décomposition LU
    // Déclarer comme virtuelle pour permettre la surcharge dans les classes dérivées
    virtual void decomposeLU(std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U) const;

public:
    Matrix(int rows, int cols) : data(rows, std::vector<double>(cols, 0)) {}
    virtual ~Matrix() {}  // Destructeur virtuel

    void set(int row, int col, double value) {
        if (row >= data.size() || col >= data[0].size()) {
            throw std::out_of_range("Index out of range");
        }
        data[row][col] = value;
    }

    double get(int row, int col) const {
        if (row >= data.size() || col >= data[0].size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[row][col];
    }

    std::vector<double> solve(const std::vector<double>& b) const;

    // Autres méthodes utiles (par exemple, affichage, multiplication de matrices, etc.)
};

class TridiagonalMatrix : public Matrix {
public:
    TridiagonalMatrix(int n) : Matrix(n, n) {}

    void decomposeLU(std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U) const override;
    // La méthode 'solve' reste inchangée et utilisera la nouvelle implémentation de decomposeLU
};

#endif // UTILS_HPP