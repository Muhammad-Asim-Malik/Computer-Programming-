// Function to calculate standard deviation

#include <iostream>
#include <cmath>
using namespace std;

// Function declaration
double stdev(double x[], int n);

// Block diagram:
// Inputs: double array x[], array size n
// Outputs: standard deviation value
// Processing: Calculates mean, then sum of squared differences, then standard deviation

int main() {
    // Test array
    double data[] = {2.4, 5.1, 3.7, 6.9, 4.2};
    int size = sizeof(data) / sizeof(data[0]);
    
    // Display the array
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    // Calculate and display standard deviation
    double standardDeviation = stdev(data, size);
    cout << "Standard Deviation: " << standardDeviation << endl;
    
    return 0;
}

// Function definition
double stdev(double x[], int n) {
    // Step 1: Calculate the mean (average)
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += x[i];
    }
    double mean = sum / n;
    
    // Step 2: Calculate sum of squared differences from mean
    double sumSquaredDiff = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = x[i] - mean;
        sumSquaredDiff += diff * diff;
    }
    
    // Step 3: Divide by n and take square root
    double variance = sumSquaredDiff / n;
    double stdDev = sqrt(variance);
    
    return stdDev;
}
