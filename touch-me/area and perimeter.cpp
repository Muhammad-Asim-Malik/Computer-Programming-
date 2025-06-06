#include <iostream>

using namespace std;

int main() {
    double length, width, area, perimeter;

    // Get user input for length and width
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    // Calculate area and perimeter
    area = length * width;
    perimeter = 2 * (length + width);

    // Display the results
    cout << "Area of the rectangle: " << area << endl;
    cout << "Perimeter of the rectangle: " << perimeter << endl;

    return 0;
}
