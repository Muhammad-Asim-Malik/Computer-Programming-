#include <iostream>

using namespace std;

int main() {
    int number;

    // Get user input for the number
    cout << "Enter a number to display its multiplication table: ";
    cin >> number;

    // Print the multiplication table using a for loop
    cout << "Multiplication Table for " << number << ":" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << number << " x " << i << " = " << number * i << endl;
    }

    return 0;
}
