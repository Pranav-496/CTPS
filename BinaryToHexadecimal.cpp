// This code converts a binary number (integer + fractional) to hexadecimal
#include <bits/stdc++.h>
using namespace std;

// Function to convert a binary integer part to hexadecimal
string binaryToHexInt(string binInt) {
    while (binInt.size() % 4 != 0) {
        binInt = "0" + binInt; // Pad with leading zeros to make groups of 4
    }

    string hex = "";
    for (size_t i = 0; i < binInt.size(); i += 4) {
        int value = (binInt[i] - '0') * 8 + (binInt[i + 1] - '0') * 4 + 
                    (binInt[i + 2] - '0') * 2 + (binInt[i + 3] - '0') * 1;
        hex += (value < 10) ? to_string(value) : string(1, char('A' + value - 10));
    }

    return hex;
}

// Function to convert a binary fractional part to hexadecimal
string binaryToHexFrac(string binFrac) {
    while (binFrac.size() % 4 != 0) {
        binFrac += "0"; // Pad with trailing zeros to make groups of 4
    }

    string hex = "";
    for (size_t i = 0; i < binFrac.size(); i += 4) {
        int value = (binFrac[i] - '0') * 8 + (binFrac[i + 1] - '0') * 4 + 
                    (binFrac[i + 2] - '0') * 2 + (binFrac[i + 3] - '0') * 1;
        hex += (value < 10) ? to_string(value) : string(1, char('A' + value - 10));
    }

    return hex;
}

int main() {
    string binary;
    cout << "Enter a binary number (integer + fractional part): ";
    cin >> binary;

    // Splitting integer and fractional parts
    string binInt = "", binFrac = "";
    bool isFractional = false;

    for (char bit : binary) {
        if (bit == '.') {
            isFractional = true;
            continue;
        }
        if (isFractional)
            binFrac += bit;
        else
            binInt += bit;
    }

    // Convert integer and fractional parts to hexadecimal
    string hexInt = binaryToHexInt(binInt);
    string hexFrac = binaryToHexFrac(binFrac);

    // Print result
    cout << "Hexadecimal Equivalent: " << hexInt;
    if (!hexFrac.empty()) {
        cout << "." << hexFrac;
    }
    cout << endl;

    return 0;
}
