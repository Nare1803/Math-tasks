#include <iostream>
#include <vector>

void swap_rows(std::vector<std::vector<double>>& matrix, int row1, int row2) {
    std::vector<double> temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}

void gaussian_elimination(std::vector<std::vector<double>>& augmented_matrix) {
    int n = augmented_matrix.size(); // Number of equations
    int m = augmented_matrix[0].size(); // Number of columns

    for (int col = 0; col < n; ++col) {
        int max_row = col;
        for (int row = col + 1; row < n; ++row) {
            if ((augmented_matrix[row][col] > augmented_matrix[max_row][col]) || 
                (augmented_matrix[row][col] < -augmented_matrix[max_row][col])) {//module
                max_row = row;
            }
        }

        // Swap the current row with the row having the largest absolute value
        if (max_row != col) {
            swap_rows(augmented_matrix, col, max_row);
        }

        // Normalize the current row to have a leading coefficient of 1
        double divisor = augmented_matrix[col][col];
        if (divisor == 0) {
            std::cerr << "No unique solution." << std::endl;
            return; // No unique solution exists if there's a zero on the diagonal
        }
        for (int j = col; j < m; ++j) {
            augmented_matrix[col][j] /= divisor;
        }

        // Eliminate the current column in the rows below
        for (int row = col + 1; row < n; ++row) {
            double factor = augmented_matrix[row][col];
            for (int j = col; j < m; ++j) {
                augmented_matrix[row][j] -= factor * augmented_matrix[col][j];
            }
        }
    }

    // Back substitution to get the solutions
    std::vector<double> solutions(n, 0.0); // Vector to hold solutions
    for (int row = n - 1; row >= 0; --row) {
        double sum = 0.0;
        for (int j = row + 1; j < n; ++j) {
            sum += augmented_matrix[row][j] * solutions[j];
        }
        solutions[row] = augmented_matrix[row][n] - sum; // Calculate the solution
    }

    // Output the solutions
    std::cout << "Solutions:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "x" << (i + 1) << " = " << solutions[i] << std::endl;
    
    }
}
int main() 
{
   
    std::vector<std::vector<double>> augmented_matrix = {
        {1, -2, 3, 9},
        {-1, 3, 0, -4},
        {2, -5, 5, 17}
    };

    gaussian_elimination(augmented_matrix);

    return 0;
}

