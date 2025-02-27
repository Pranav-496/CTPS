#include <bits/stdc++.h>
using namespace std;

// Function to convert an octal digit to a 3-bit binary string
string octalDigitToBinary(char octalDigit) {
    switch (octalDigit) {
        case '0': return "000";
        case '1': return "001";
        case '2': return "010";
        case '3': return "011";
        case '4': return "100";
        case '5': return "101";
        case '6': return "110";
        case '7': return "111";
        default: return "";
    }
}

// Function to convert octal integer part to binary
string octalToBinaryInt(const string& octInt) {
    string binary = "";
    for (char digit : octInt) {
        binary += octalDigitToBinary(digit);
    }
    // Removing leading zeros
    size_t pos = binary.find_first_not_of('0');
    return (pos == string::npos) ? "0" : binary.substr(pos);
}

// Function to convert octal fractional part to binary
string octalToBinaryFrac(const string& octFrac) {
    string binary = "";
    for (char digit : octFrac) {
        binary += octalDigitToBinary(digit);
    }
    return binary;
}

int main() {
    string octal;
    cout << "Enter an octal number (integer + fractional part): ";
    cin >> octal;

    // Splitting integer and fractional parts
    string octInt = "", octFrac = "";
    bool isFractional = false;

    for (char digit : octal) {
        if (digit == '.') {
            isFractional = true;
            continue;
        }
        if (isFractional)
            octFrac += digit;
        else
            octInt += digit;
    }

    // Convert integer and fractional parts to binary
    string binInt = octalToBinaryInt(octInt);
    string binFrac = octalToBinaryFrac(octFrac);

    list<int> bint, binf;

    // Store integer part in list<int>
    for (char bit : binInt) {
        bint.push_back(bit - '0');
    }

    // Store fractional part in list<int>
    for (char bit : binFrac) {
        binf.push_back(bit - '0');
    }

    // Convert integer part to decimal
    int intDecimal = 0;
    while (!bint.empty()) {
        intDecimal = intDecimal * 2 + bint.front();
        bint.pop_front();
    }

    // Convert fractional part to decimal
    double fracDecimal = 0, fracPower = 0.5;
    for (int bit : binf) {
        fracDecimal += bit * fracPower;
        fracPower /= 2;
    }

    // Print the final decimal value with correct formatting
    cout << "Decimal Equivalent: " << fixed << setprecision(10) << (intDecimal + fracDecimal) << endl;

    return 0;
}
