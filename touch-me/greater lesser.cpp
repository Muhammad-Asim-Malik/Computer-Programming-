#include <iostream>

using namespace std;

int main() {
    int num1, num2;

    // Get user input for the two numbers
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Determine which number is greater, lesser, or if they are equal
    if (num1 > num2) {
        cout << num1 << " is greater than " << num2 << "." << endl;
    } else if (num1 < num2) {
        cout << num1 << " is lesser than " << num2 << "." << endl;
    } else {
        cout << "Both numbers are equal." << endl;
    }

    return 0;
}
