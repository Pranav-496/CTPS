// This code converts a decimal number (integer + fractional) to binary using list<int>
#include <bits/stdc++.h>
using namespace std;

int main() {
    double dec;
    cout << "Enter a decimal number: ";
    cin >> dec;

    // Separate integer and fractional parts
    int intPart = (int)dec;
    double fracPart = dec - intPart;

    list<int> binInt, binFrac;

    // Convert integer part to binary
    if (intPart == 0) binInt.push_back(0);
    while (intPart > 0) {
        binInt.push_front(intPart % 2);
        intPart /= 2;
    }

    // Convert fractional part to binary
    int precision = 10; // Adjust for more/less precision
    while (fracPart > 0 && precision--) {
        fracPart *= 2;
        int bit = (int)fracPart;
        binFrac.push_back(bit);
        fracPart -= bit; // Remove integer part
    }

    // Print the final binary representation
    for (int bit : binInt) {
        cout << bit;
    }

    if (!binFrac.empty()) {
        cout << ".";
        for (int bit : binFrac) {
            cout << bit;
        }
    }

    cout << endl;
    return 0;
}
