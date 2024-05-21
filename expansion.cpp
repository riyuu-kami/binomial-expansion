// this code does not work using the generalized binomial theorem, so inputting an n that is not a natural number (excluding 0) will result in an empty output

#include <iostream>
#include <string>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int nCr(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

string BinomialTheorem(int n) {
    string result = "";
    for (int k = 0; k <= n; k++) {
        int coefficient = nCr(n, k);
        if (coefficient != 1) {
            result += to_string(coefficient);
        }
        if (n - k > 0) {
            if (coefficient != 1) {
                result += "*";
            }
            result += "a";
            if (n - k > 1) {
                result += "^" + to_string(n - k);
            }
        }
        if (k > 0) {
            if (coefficient != 1 || (n - k > 0)) {
                result += "*";
            }
            result += "b";
            if (k > 1) {
                result += "^" + to_string(k);
            }
        }
        if (k < n) {
            result += " + ";
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    string expansion = BinomialTheorem(n);
    cout << "Binomial Theorem Expansion: " << expansion << endl;

    return 0;
}
