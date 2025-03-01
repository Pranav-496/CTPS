// This code converts a hexadecimal number (integer + fractional) to decimal
#include <bits/stdc++.h>
using namespace std;

// Function to convert an hexadecimal digit to a 4-bit binary string
string hexadecimalDigitToBinary(char octalDigit)
{
    switch (octalDigit)
    {
    case '0':
        return "0000";
    case '1':
        return "0001";
    case '2':
        return "0010";
    case '3':
        return "0011";
    case '4':
        return "0100";
    case '5':
        return "0101";
    case '6':
        return "0110";
    case '7':
        return "0111";
    case '8':
        return "1000";
    case '9':
        return "1001";
    case 'A':
        return "1010";
    case 'B':
        return "1011";
    case 'C':
        return "1100";
    case 'D':
        return "1101";
    case 'E':
        return "1110";
    case 'F':
        return "1111";
    default:
        return "";
    }
}

// Function to convert hexadecimal integer part to binary
string HexadecimalToBinaryInt(string hexInt)
{
    string binary = "";
    for (char digit : hexInt)
    {
        binary += hexadecimalDigitToBinary(digit);
    }

    // Removing leading zeros
    size_t pos = binary.find_first_not_of('0');
    return (pos == string::npos) ? "0" : binary.substr(pos);
}

// Function to convert hexadeciaml fractional part to binary
string HexadecimalToBinaryFrac(string hexFrac)
{
    string binary = "";
    for (char digit : hexFrac)
    {
        binary += hexadecimalDigitToBinary(digit);
    }
    return binary;
}

int main()
{
    string hexa;
    cout << "Enter the Hexadeciaml number (intger + fractional) :";
    cin >> hexa;

    // Splitting integer and fractional parts
    string hexInt = "", hexFrac = "";
    bool isFractional = false;

    for (char digit : hexa)
    {
        if (digit == '.')
        {
            isFractional = true;
            continue;
        }
        if (isFractional)
            hexFrac += digit;
        else
            hexInt += digit;
    }

    // Convert integer and fractional parts to binary
    string binInt = HexadecimalToBinaryInt(hexInt);
    string binFrac = HexadecimalToBinaryFrac(hexFrac);

    list<int> bint, binf;

    // Store integer part in list<int>
    for (char bit : binInt)
    {
        bint.push_back(bit - '0');
    }

    // Store fractional part in list<int>
    for (char bit : binFrac)
    {
        binf.push_back(bit - '0');
    }

    // Convert integer part to decimal
    int intDecimal = 0;
    while (!bint.empty())
    {
        intDecimal = intDecimal * 2 + bint.front();
        bint.pop_front();
    }

    // Convert fractional part to decimal
    double fracDecimal = 0, fracPower = 0.5;
    for (int bit : binf)
    {
        fracDecimal += bit * fracPower;
        fracPower /= 2;
    }

    // Print the final decimal value with correct formatting
    cout << "Decimal Equivalent: " << fixed << setprecision(10) << (intDecimal + fracDecimal) << endl;
    return 0;
}