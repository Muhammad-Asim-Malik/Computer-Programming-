//  Roman Numeral Conversion

#include <iostream>
#include <string>
using namespace std;

// Function declaration
string convertToRoman(int year);

// Block diagram:
// Inputs: integer year
// Outputs: string (Roman numeral representation)
// Processing: Converts decimal year to Roman numerals

int main() {
    int year;
    
    cout << "Enter a year: ";
    cin >> year;
    
    // Validate input
    if (year <= 0) {
        cout << "Year must be a positive number!" << endl;
        return 1;
    }
    
    // Convert and display Roman numeral
    string romanYear = convertToRoman(year);
    cout << year << " in Roman numerals is: " << romanYear << endl;
    
    return 0;
}

// Function to convert decimal year to Roman numerals
string convertToRoman(int year) {
    string roman = "";
    
    // Define Roman numeral values from largest to smallest
    const int decimalValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    // Convert the year
    for (int i = 0; i < 13; i++) {
        while (year >= decimalValues[i]) {
            roman += romanSymbols[i];
            year -= decimalValues[i];
        }
    }
    
    return roman;
}
