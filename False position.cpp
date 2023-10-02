#include <bits/stdc++.h>
#include <cmath>
using namespace std;


double f(double x) {
    return 2 * exp(x) * sin(x) - 3;
}

double false_position(double a, double b, int max_iterations, double tolerance) {
    double c;
    int iter = 0;

    while (iter < max_iterations) {

        c = (a * f(b) - b * f(a)) / (f(b) - f(a));




        if (abs(f(c)) < tolerance){
             cout<<iter<<endl;
            return c;

        }

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iter++;
    }

    cout<<iter<<endl;

    return c;
}

int main() {
    double a = 1.0;  // Initial interval left endpoint
    double b = 2.0;  // Initial interval right endpoint
    int max_iterations = 1e9;  // Maximum number of iterations
    double tolerance = 0.0001;  // Tolerance for convergence

    double root = false_position(a, b, max_iterations, tolerance);

cout << "Approximate root: " << setprecision(4) << root << endl;

    return 0;
}

