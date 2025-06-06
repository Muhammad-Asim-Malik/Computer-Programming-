#include <iostream>

using namespace std;

int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    // Check if the number is positive or negative
    if (number > 0) {
        cout << number << " is a positive integer." << endl;
    } else if (number < 0) {
        cout << number << " is a negative integer." << endl;
    } else {
        cout << "The number is zero." << endl; // Optional: handle zero case
    }

    return 0;
}
