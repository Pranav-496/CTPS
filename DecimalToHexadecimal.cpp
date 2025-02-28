// This code converts a decimal number (integer + fractional) to hexadecimal
#include <bits/stdc++.h>
using namespace std;

// Function to convert a binary integer part to hexadecimal
string binaryToHexInt(string binInt)
{
    while (binInt.size() % 4 != 0)
    {
        binInt = "0" + binInt; // Pad with leading zeros to make groups of 4
    }

    string hex = "";
    for (size_t i = 0; i < binInt.size(); i += 4)
    {
        int value = (binInt[i] - '0') * 8 + (binInt[i + 1] - '0') * 4 +
                    (binInt[i + 2] - '0') * 2 + (binInt[i + 3] - '0') * 1;
        hex += (value < 10) ? to_string(value) : string(1, char('A' + value - 10));
    }

    return hex;
}

// Function to convert a binary fractional part to hexadecimal
string binaryToHexFrac(string binFrac)
{
    while (binFrac.size() % 4 != 0)
    {
        binFrac += "0"; // Pad with trailing zeros to make groups of 4
    }

    string hex = "";
    for (size_t i = 0; i < binFrac.size(); i += 4)
    {
        int value = (binFrac[i] - '0') * 8 + (binFrac[i + 1] - '0') * 4 +
                    (binFrac[i + 2] - '0') * 2 + (binFrac[i + 3] - '0') * 1;
        hex += (value < 10) ? to_string(value) : string(1, char('A' + value - 10));
    }

    return hex;
}

int main()
{
    double dec;
    cout << "Enter a decimal number: ";
    cin >> dec;

    // Separate integer and fractional parts
    int intPart = (int)dec;
    double fracPart = dec - intPart;

    list<int> binInt, binFrac;

    // Convert integer part to binary
    if (intPart == 0)
        binInt.push_back(0);
    while (intPart > 0)
    {
        binInt.push_front(intPart % 2);
        intPart /= 2;
    }

    // Convert fractional part to binary
    int precision = 16; // Adjust for more/less precision
    while (fracPart > 0 && precision--)
    {
        fracPart *= 2;
        int bit = (int)fracPart;
        binFrac.push_back(bit);
        fracPart -= bit; // Remove integer part
    }

    string bint = "", binf = "";
    for (auto ele : binInt)
    {
        bint += to_string(ele);
    }
    for (auto ele : binFrac)
    {
        binf += to_string(ele);
    }

    // Convert integer and fractional parts to hexadecimal
    string hexInt = binaryToHexInt(bint);
    string hexFrac = binaryToHexFrac(binf);

    // Print result
    cout << "Hexadecimal Equivalent: " << hexInt;
    if (!hexFrac.empty())
    {
        cout << "." << hexFrac;
    }
    cout << endl;
    return 0;
}
