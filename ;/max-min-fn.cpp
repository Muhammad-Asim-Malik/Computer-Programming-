//Function to find min and max in an array

#include <iostream>
using namespace std;

// Function declaration
void getExtremes(float& min, float& max, float a[], int n);

// Block diagram:
// Inputs: float array a[], array size n
// Outputs (by reference): min, max
// Processing: Finds minimum and maximum values in the array

int main() {
    // Test array
    float numbers[] = {5.2, 3.7, 9.8, 2.1, 7.5, 4.6};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    float minimum, maximum;
    
    // Display the array
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Call the function to find min and max
    getExtremes(minimum, maximum, numbers, size);
    
    // Display results
    cout << "Minimum value: " << minimum << endl;
    cout << "Maximum value: " << maximum << endl;
    
    return 0;
}

// Function definition
void getExtremes(float& min, float& max, float a[], int n) {
    // Initialize min and max with first element
    min = a[0];
    max = a[0];
    
    // Traverse the array to find min and max
    for (int i = 1; i < n; i++) {
        // Update min if current element is smaller
        if (a[i] < min) {
            min = a[i];
        }
        
        // Update max if current element is larger
        if (a[i] > max) {
            max = a[i];
        }
    }
    
    // At this point, min and max contain the extreme values
    // They are passed by reference, so the original variables will be updated
}
