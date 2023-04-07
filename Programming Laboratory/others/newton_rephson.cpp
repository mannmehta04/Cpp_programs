#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    // Define the function whose root we want to find
    return x*x - 3*x + 2;
}

double fprime(double x) {
    // Define the derivative of the function
    return 2*x - 3;
}

double newtonRaphson(double x0, double tol, int maxIter) {
    double xn = x0;
    int i = 0;

    while (i < maxIter) {
        double fxn = f(xn);
        double fpxn = fprime(xn);

        if (abs(fxn) < tol) {
            // We have found a root within the tolerance
            return xn;
        }

        xn = xn - fxn / fpxn;
        i++;
    }

    // We did not find a root within the maximum number of iterations
    cout << "Error: The method did not converge." << endl;
    return NAN;
}

int main() {
    double x0, tol;
    int maxIter;

    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;

    double root = newtonRaphson(x0, tol, maxIter);
    if (!isnan(root)) {
        cout << "The root is: " << root << endl;
    }

    return 0;
}
