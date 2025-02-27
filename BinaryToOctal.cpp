// This code converts a binary number (integer + fractional) to octal using list<int>
#include <bits/stdc++.h>
using namespace std;

// Function to convert a binary integer part to octal
string binaryToOctalInt(string binInt) {
    while (binInt.size() % 3 != 0) {
        binInt = "0" + binInt; // Pad with leading zeros to make groups of 3
    }

    string octal = "";
    for (size_t i = 0; i < binInt.size(); i += 3) {
        int value = (binInt[i] - '0') * 4 + (binInt[i + 1] - '0') * 2 + (binInt[i + 2] - '0') * 1;
        octal += to_string(value);
    }

    return octal;
}

// Function to convert a binary fractional part to octal
string binaryToOctalFrac(string binFrac) {
    while (binFrac.size() % 3 != 0) {
        binFrac += "0"; // Pad with trailing zeros to make groups of 3
    }

    string octal = "";
    for (size_t i = 0; i < binFrac.size(); i += 3) {
        int value = (binFrac[i] - '0') * 4 + (binFrac[i + 1] - '0') * 2 + (binFrac[i + 2] - '0') * 1;
        octal += to_string(value);
    }

    return octal;
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

    // Convert integer and fractional parts to octal
    string octInt = binaryToOctalInt(binInt);
    string octFrac = binaryToOctalFrac(binFrac);

    // Print result
    cout << "Octal Equivalent: " << octInt;
    if (!octFrac.empty()) {
        cout << "." << octFrac;
    }
    cout << endl;

    return 0;
}
