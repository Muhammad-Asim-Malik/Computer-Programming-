#include <iostream>
#include <string> // Include the string header for using std::string

using namespace std;

int main() {
    string fullName; // Variable to store the full name

    // Prompt the user to enter their full name
    cout << "Enter your full name: ";
    getline(cin, fullName); // Use getline to read the full line of input

    // Display the full name
    cout << "Your full name is: " << fullName << endl;

    return 0;
}
