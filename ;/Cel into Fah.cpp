#include <iostream>
using namespace std;

int main() {
    // Variable to store temperature in Celsius
    float celsius, fahrenheit;

    // Input temperature in Celsius
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9.0 / 5.0) + 32;

    // Output the result
    cout << "Temperature in Fahrenheit: " << fahrenheit << " °F" << endl;

    return 0;
}
