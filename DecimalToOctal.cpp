#include <bits/stdc++.h>
using namespace std;

// Function to convert a binary integer part to octal
string binaryToOctalInt(string binInt)
{
    while (binInt.size() % 3 != 0)
    {
        binInt = "0" + binInt; // Pad with leading zeros to make groups of 3
    }

    string octal = "";
    for (size_t i = 0; i < binInt.size(); i += 3)
    {
        int value = (binInt[i] - '0') * 4 + (binInt[i + 1] - '0') * 2 + (binInt[i + 2] - '0') * 1;
        octal += to_string(value);
    }

    return octal;
}

// Function to convert a binary fractional part to octal
string binaryToOctalFrac(string binFrac)
{
    while (binFrac.size() % 3 != 0)
    {
        binFrac += "0"; // Pad with trailing zeros to make groups of 3
    }

    string octal = "";
    for (size_t i = 0; i < binFrac.size(); i += 3)
    {
        int value = (binFrac[i] - '0') * 4 + (binFrac[i + 1] - '0') * 2 + (binFrac[i + 2] - '0') * 1;
        octal += to_string(value);
    }

    return octal;
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
    int precision = 10; // Adjust for more/less precision
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

    // Convert integer and fractional parts to octal
    string octInt = binaryToOctalInt(bint);
    string octFrac = binaryToOctalFrac(binf);

    // Print result
    cout << "Octal Equivalent: " << octInt;
    if (!octFrac.empty())
    {
        cout << "." << octFrac;
    }
    cout << endl;

    return 0;
}