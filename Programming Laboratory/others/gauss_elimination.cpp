#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 4;

void printMatrix(double matrix[][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void gaussElimination(double matrix[][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        // Find pivot row
        int pivotRow = i;
        double maxElem = fabs(matrix[i][i]);
        for (int j = i + 1; j < rows; j++) {
            if (fabs(matrix[j][i]) > maxElem) {
                maxElem = fabs(matrix[j][i]);
                pivotRow = j;
            }
        }

        // Swap rows
        if (pivotRow != i) {
            for (int j = i; j < cols; j++) {
                double temp = matrix[i][j];
                matrix[i][j] = matrix[pivotRow][j];
                matrix[pivotRow][j] = temp;
            }
        }

        // Eliminate elements below pivot
        for (int j = i + 1; j < rows; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < cols; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    // Back-substitution
    double x[MAX_ROWS];
    for (int i = rows - 1; i >= 0; i--) {
        x[i] = matrix[i][cols - 1];
        for (int j = i + 1; j < rows; j++) {
            x[i] -= matrix[i][j] * x[j];
        }
        x[i] /= matrix[i][i];
    }

    // Print solution
    cout << "Solution:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main()
{
    double matrix[MAX_ROWS][MAX_COLS] = {
        {1, 2, 1, 0},
        {2, 2, 3, 3},
        {-1, -3, 0, 2}
    };

    cout << "Original matrix:" << endl;
    printMatrix(matrix, MAX_ROWS, MAX_COLS);

    gaussElimination(matrix, MAX_ROWS, MAX_COLS);

    return 0;
}