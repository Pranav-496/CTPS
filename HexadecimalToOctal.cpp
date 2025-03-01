#include <bits/stdc++.h>
using namespace std;

// Function to convert a hexadecimal digit to a 4-bit binary string
string hexToBinary(char hexDigit) {
    switch (toupper(hexDigit)) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
        default: return "";
    }
}

// Convert hexadecimal integer part to binary
string hexIntToBinary(string hexInt) {
    string binary = "";
    for (char digit : hexInt) binary += hexToBinary(digit);
    return binary;
}

// Convert hexadecimal fractional part to binary
string hexFracToBinary(string hexFrac) {
    string binary = "";
    for (char digit : hexFrac) binary += hexToBinary(digit);
    return binary;
}

// Convert binary integer part to octal
string binaryToOctalInt(string binInt) {
    while (binInt.size() % 3 != 0) binInt = "0" + binInt; // Pad with leading zeros

    string octal = "";
    for (size_t i = 0; i < binInt.size(); i += 3) {
        int value = (binInt[i] - '0') * 4 + (binInt[i + 1] - '0') * 2 + (binInt[i + 2] - '0') * 1;
        octal += to_string(value);
    }

    return octal;
}

// Convert binary fractional part to octal
string binaryToOctalFrac(string binFrac) {
    while (binFrac.size() % 3 != 0) binFrac += "0"; // Pad with trailing zeros

    string octal = "";
    for (size_t i = 0; i < binFrac.size(); i += 3) {
        int value = (binFrac[i] - '0') * 4 + (binFrac[i + 1] - '0') * 2 + (binFrac[i + 2] - '0') * 1;
        octal += to_string(value);
    }

    return octal;
}

int main() {
    string hexNum;
    cout << "Enter the Hexadecimal number (integer + fractional): ";
    cin >> hexNum;

    // Splitting integer and fractional parts
    string hexInt = "", hexFrac = "";
    bool isFractional = false;

    for (char digit : hexNum) {
        if (digit == '.') {
            isFractional = true;
            continue;
        }
        if (isFractional)
            hexFrac += digit;
        else
            hexInt += digit;
    }

    // Convert integer and fractional parts to binary
    string binInt = hexIntToBinary(hexInt);
    string binFrac = hexFracToBinary(hexFrac);

    // Convert binary to octal
    string octInt = binaryToOctalInt(binInt);
    string octFrac = binaryToOctalFrac(binFrac);

    // Print output
    cout << "Binary Integer: " << binInt << endl;
    cout << "Binary Fraction: " << binFrac << endl;
    cout << "Octal Equivalent: " << octInt;
    if (!octFrac.empty()) cout << "." << octFrac;
    cout << endl;

    return 0;
}
