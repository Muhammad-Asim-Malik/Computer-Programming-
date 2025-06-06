// String Analysis

#include <iostream>
#include <string>
using namespace std;

// Function declarations
void analyzeString(const string& input, int& chars, int& spaces, int& tabs, int& lines);

// Block diagram:
// Inputs: string input
// Outputs (by reference): chars, spaces, tabs, lines
// Processing: Counts characters, spaces, tabs, and lines in the input string

int main() {
    string userInput;
    int totalChars = 0, totalSpaces = 0, totalTabs = 0, totalLines = 0;
    
    cout << "Enter a string (press Enter and then Ctrl+Z on Windows or Ctrl+D on Unix/Linux to finish):\n";
    
    // Read input, potentially with multiple lines
    string line;
    getline(cin, line);
    userInput = line;
    while (getline(cin, line)) {
        userInput += "\n" + line;
    }
    
    // Analyze the string
    analyzeString(userInput, totalChars, totalSpaces, totalTabs, totalLines);
    
    // Display results
    cout << "\nString Analysis Results:\n";
    cout << "Total Characters: " << totalChars << endl;
    cout << "Total Spaces: " << totalSpaces << endl;
    cout << "Total Tabs: " << totalTabs << endl;
    cout << "Total Lines: " << totalLines << endl;
    
    return 0;
}

// Function to analyze a string
void analyzeString(const string& input, int& chars, int& spaces, int& tabs, int& lines) {
    chars = 0;
    spaces = 0;
    tabs = 0;
    lines = 1; // Start with 1 line, as even a string without newlines has at least one line
    
    // Analyze each character in the string
    for (char c : input) {
        chars++; // Count every character
        
        // Check special characters
        if (c == ' ') {
            spaces++;
        } else if (c == '\t') {
            tabs++;
        } else if (c == '\n') {
            lines++;
        }
    }
}
