#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    // Define the function whose root we want to find
    return x*x - 3*x + 2;
}

double bisection(double a, double b, double tol, int maxIter) {
    double fa = f(a);
    double fb = f(b);

    if (fa * fb > 0) {
        // The bisection method requires that f(a) and f(b) have opposite signs
        cout << "Error: f(a) and f(b) have the same sign." << endl;
        return NAN;
    }

    double c = (a + b) / 2;
    int i = 0;

    while (i < maxIter) {
        double fc = f(c);

        if (abs(fc) < tol) {
            // We have found a root within the tolerance
            return c;
        }

        if (fa * fc < 0) {
            // The root is in the interval [a,c]
            b = c;
            fb = fc;
        } else {
            // The root is in the interval [c,b]
            a = c;
            fa = fc;
        }

        c = (a + b) / 2;
        i++;
    }

    // We did not find a root within the maximum number of iterations
    cout << "Error: The method did not converge." << endl;
    return NAN;
}

int main() {
    double a, b, tol;
    int maxIter;

    cout << "Enter interval [a,b]: ";
    cin >> a >> b;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;

    double root = bisection(a, b, tol, maxIter);
    if (!isnan(root)) {
        cout << "The root is: " << root << endl;
    }

    return 0;
}