#include <iostream>
using namespace std;

int main()
{
    double a11, a12, a21, a22;
    cout << "Enter the elements of the 2x2 matrix: " << endl;
    cin >> a11 >> a12 >> a21 >> a22;

    // Calculate determinant of the matrix
    double det = a11*a22 - a12*a21;
    if (det == 0) {
        cout << "Error: The matrix is singular and has no inverse." << endl;
        return 1;
    }

    // Calculate inverse matrix
    double inv_a11 = a22 / det;
    double inv_a12 = -a12 / det;
    double inv_a21 = -a21 / det;
    double inv_a22 = a11 / det;

    // Print inverse matrix
    cout << "The inverse of the matrix is: " << endl;
    cout << inv_a11 << " " << inv_a12 << endl;
    cout << inv_a21 << " " << inv_a22 << endl;

    return 0;
}