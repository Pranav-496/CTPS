// This code converts a binary number (integer + fractional) to decimal using list<int>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string binary;
    cout << "Enter a binary number (integer + fractional part): ";
    cin >> binary;

    list<int> binInt, binFrac;
    bool isFractional = false;

    // Separate integer and fractional parts
    for (char bit : binary) {
        if (bit == '.') {
            isFractional = true;
            continue;
        }
        if (isFractional)
            binFrac.push_back(bit - '0');
        else
            binInt.push_back(bit - '0');
    }

    // Convert integer part to decimal
    int intDecimal = 0;
    while (!binInt.empty()) {
        intDecimal = intDecimal * 2 + binInt.front();
        binInt.pop_front();
    }

    // Convert fractional part to decimal
    double fracDecimal = 0, fracPower = 0.5;
    for (int bit : binFrac) {
        fracDecimal += bit * fracPower;
        fracPower /= 2;
    }

    // Print the final decimal value
    cout << "Decimal Equivalent: " << intDecimal + fracDecimal << endl;

    return 0;
}
