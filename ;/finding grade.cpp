#include <iostream>

using namespace std;

int main() {
    int score;

    // Get user input for the score
    cout << "Enter the student's score (0-100): ";
    cin >> score;

    // Determine the grade using if-else statements
    if (score >= 90 && score <= 100) {
        cout << "Grade: A" << endl;
    } else if (score >= 80 && score < 90) {
        cout << "Grade: B" << endl;
    } else if (score >= 70 && score < 80) {
        cout << "Grade: C" << endl;
    } else if (score >= 60 && score < 70) {
        cout << "Grade: D" << endl;
    } else if (score >= 0 && score < 60) {
        cout << "Grade: F" << endl;
    } else {
        cout << "Invalid score. Please enter a score between 0 and 100." << endl;
    }

    return 0;
}
