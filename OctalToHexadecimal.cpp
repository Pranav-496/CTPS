// This code converts a octal number (integer + fractional) to hexadecimal
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
string octalToBinaryInt(string octInt) {
    string binary = "";
    for (char digit : octInt) {
        binary += octalDigitToBinary(digit);
    }

    // Removing leading zeros
    size_t pos = binary.find_first_not_of('0');
    return (pos == string::npos) ? "0" : binary.substr(pos);
}

// Function to convert octal fractional part to binary
string octalToBinaryFrac(string octFrac) {
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
