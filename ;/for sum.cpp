#include <iostream>

using namespace std;

int main() {
    int sum = 0; // Variable to hold the sum

    // Use a for loop to print numbers from 1 to 10 and calculate their sum
    cout << "Numbers from 1 to 10:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << endl; // Print the current number
        sum += i;         // Add the current number to the sum
    }

    // Display the sum
    cout << "Sum of numbers from 1 to 10: " << sum << endl;

    return 0;
}
