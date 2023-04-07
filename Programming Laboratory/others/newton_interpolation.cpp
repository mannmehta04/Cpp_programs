#include <iostream>
#include <vector>
using namespace std;

double newtonInterpolate(double x, vector<double> X, vector<double> Y) {
    int n = X.size();

    // Compute the divided differences
    vector<double> f(n);
    for (int i = 0; i < n; i++) {
        f[i] = Y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = n-1; i >= j; i--) {
            f[i] = (f[i] - f[i-1]) / (X[i] - X[i-j]);
        }
    }

    // Evaluate the interpolating polynomial at x
    double p = f[n-1];
    for (int i = n-2; i >= 0; i--) {
        p = f[i] + (x - X[i]) * p;
    }
    return p;
}

int main() {
    vector<double> X = {0, 1, 2, 3};
    vector<double> Y = {1, 2, 3, 5};

    double x = 2.5;
    double p = newtonInterpolate(x, X, Y);

    cout << "The interpolating polynomial evaluated at x = " << x << " is: " << p << endl;

    return 0;
}