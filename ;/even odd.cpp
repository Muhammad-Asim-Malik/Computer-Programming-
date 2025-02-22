#include <iostream>

using namespace std;

int main() {
    int number;

    // Get user input
    cout << "Enter an integer: ";
    cin >> number;

    // Check if the number is even or odd
    if (number % 2 == 0) {
        cout << number << " is an even number." << endl;
    } else {
        cout << number << " is an odd number." << endl;
    }

    return 0;
}
