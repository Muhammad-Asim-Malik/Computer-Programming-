#include <iostream>
using namespace std;

int main() {
    // Variables for weight and height
    double weight, height, bmi;

    // Input weight in kilograms
    cout << "Enter your weight (in kg): ";
    cin >> weight;

    // Input height in meters
    cout << "Enter your height (in meters): ";
    cin >> height;

    // Calculate BMI
    bmi = weight / (height * height);

    // Output the BMI value
    cout << "Your Body Mass Index (BMI) is: " << bmi << endl;

    // Suggestion based on BMI value
    cout << "BMI Categories:\n";
    if (bmi < 18.5) {
        cout << "Underweight\n";
       
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << "Normal weight\n";
        
    } else if (bmi >= 25 && bmi < 29.9) {
        cout << "Overweight\n";
        
    } else {
        cout << "Obesity\n";
    }

    return 0;
}
