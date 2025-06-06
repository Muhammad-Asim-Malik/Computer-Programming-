// Mean, Median, and Mode

#include <iostream>
#include <algorithm> // For sort function
#include <map>       // For frequency counting
using namespace std;

// Function declarations
double calculateMean(int arr[], int n);
double calculateMedian(int arr[], int n);
int calculateMode(int arr[], int n);

int main() {
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    // Validate input
    if (n <= 0) {
        cout << "Number of elements must be positive!" << endl;
        return 1;
    }
    
    // Dynamically allocate array
    int* numbers = new int[n];
    
    // Input array elements
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> numbers[i];
    }
    
    // Calculate and display statistical measures
    double mean = calculateMean(numbers, n);
    double median = calculateMedian(numbers, n);
    int mode = calculateMode(numbers, n);
    
    cout << "\nStatistical Results:\n";
    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Mode: " << mode << endl;
    
    // Free allocated memory
    delete[] numbers;
    
    return 0;
}

// Function to calculate mean
double calculateMean(int arr[], int n) {
    double sum = 0.0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    return sum / n;
}

// Function to calculate median
double calculateMedian(int arr[], int n) {
    // Create a copy of the array to avoid modifying the original
    int* sortedArr = new int[n];
    for (int i = 0; i < n; i++) {
        sortedArr[i] = arr[i];
    }
    
    // Sort the array
    sort(sortedArr, sortedArr + n);
    
    double median;
    
    // Calculate median based on array size
    if (n % 2 == 0) {
        // Even number of elements - average of middle two
        median = (sortedArr[n/2 - 1] + sortedArr[n/2]) / 2.0;
    } else {
        // Odd number of elements - middle element
        median = sortedArr[n/2];
    }
    
    // Free allocated memory
    delete[] sortedArr;
    
    return median;
}

// Function to calculate mode
int calculateMode(int arr[], int n) {
    // Use a map to count frequencies
    map<int, int> frequency;
    
    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }
    
    int maxFrequency = 0;
    int mode = arr[0]; // Default to first element in case all elements appear equally often
    
    // Find element with maximum frequency
    for (const auto& pair : frequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mode = pair.first;
        }
    }
    
    return mode;
}
