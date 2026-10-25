#include <iostream>

using namespace std;

// Function to find the n-th element of arithmetic progression
// (print = false дозволяє обчислювати член без спаму в консоль)
double Element(double a1, double d, int n, int level, int& depth, bool print = true) {
    if (level > depth) depth = level;

    if (print) {
        cout << "  [Element] level = " << level << ", n = " << n << endl;
    }

    if (n == 1) return a1;
    return Element(a1, d, n - 1, level + 1, depth, print) + d;
}

// Function to find the sum of first n elements
double Sum(double a1, double d, int n, int level, int& depth) {
    if (level > depth) depth = level;
    cout << "  [Sum] level = " << level << ", n = " << n << endl;

    if (n == 1) return a1;

    int dummy = 0;
    // Передаємо print = false, щоб Element не перебивав вивід Sum
    return Sum(a1, d, n - 1, level + 1, depth) + Element(a1, d, n, 1, dummy, false);
}

int main() {
    double a1, d;
    int n;

    cout << "a1 = "; cin >> a1;
    cout << "d = "; cin >> d;
    cout << "n = "; cin >> n;

    int depthElem = 0, depthSum = 0;

    cout << "\nCalculation of a_n\n";
    double an = Element(a1, d, n, 1, depthElem);
    cout << "a_" << n << " = " << an << " (Depth = " << depthElem << ")\n";

    cout << "\nCalculation of S_n\n";
    double sn = Sum(a1, d, n, 1, depthSum);
    cout << "S_" << n << " = " << sn << " (Depth = " << depthSum << ")\n";

    return 0;
}