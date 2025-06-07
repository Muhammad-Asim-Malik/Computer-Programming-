#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

class TeacherPortal {
private:
    static const int MAX_STUDENTS = 100;
    static const int MAX_COLUMNS = 50;

    string data[MAX_STUDENTS][MAX_COLUMNS];
    double totalMarks[MAX_STUDENTS];
    string grades[MAX_STUDENTS];

    int numStudents;
    int numColumns;

    int quizIndices[MAX_COLUMNS];
    int assignmentIndices[MAX_COLUMNS];
    int numQuizzes, numAssignments;
    int midIndex, finalIndex, projectIndex;

    double quizWeight, assignWeight, midWeight, finalWeight, projectWeight;
    double classAverage;
    
    // Maximum marks for different assessment types
    double quizMaxMarks, assignmentMaxMarks, midMaxMarks, finalMaxMarks, projectMaxMarks;

public:
    TeacherPortal()
        : numStudents(0), numColumns(0),
          numQuizzes(0), numAssignments(0),
          midIndex(-1), finalIndex(-1), projectIndex(-1),
          classAverage(0),
          quizMaxMarks(10), assignmentMaxMarks(10), midMaxMarks(100), 
          finalMaxMarks(100), projectMaxMarks(40) {
        // Initialize arrays
        for (int i = 0; i < MAX_COLUMNS; i++) {
            quizIndices[i] = -1;
            assignmentIndices[i] = -1;
        }
    }

    int loadCSV(const string &filename);        // Returns 1 for success, 0 for failure
    void parseHeader();
    void inputWeights();
    void inputMaxMarks();
    void calculateTotals();
    void assignGrades();
    void showResults();
    void saveResults(const string &filename);
    void searchStudent(const string &roll);
    int isValidNumber(const string &str);       // Returns 1 if valid, 0 if not
    double stringToDouble(const string &str);
};

// This function removes spaces from beginning and end of a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

// This function checks if a string contains a valid number
// Returns 1 if valid, 0 if not valid
int TeacherPortal::isValidNumber(const string &str) {
    if (str.empty()) return 0;
    stringstream ss(str);
    double val;
    if (ss >> val && ss.eof()) {
        return 1;  // Valid number
    }
    return 0;  // Not valid
}

// This function converts string to double number
double TeacherPortal::stringToDouble(const string &str) {
    if (isValidNumber(str) == 0) return 0.0;
    stringstream ss(str);
    double val;
    ss >> val;
    return val;
}

// This function loads data from CSV file
// Returns 1 if successful, 0 if failed
int TeacherPortal::loadCSV(const string &filename) {
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return 0;  // Failed to open
    }

    cout << "File opened successfully." << endl;
    string line;
    numStudents = 0;

    while (getline(file, line) && numStudents < MAX_STUDENTS) {
        stringstream ss(line);
        string cell;
        int col = 0;

        while (getline(ss, cell, ',') && col < MAX_COLUMNS) {
            data[numStudents][col] = trim(cell);
            col++;
        }
        numColumns = col;
        numStudents++;
    }

    file.close();
    
    if (numStudents == 0) {
        cout << "No data found in file." << endl;
        return 0;  // No data found
    }
    
    cout << "Loaded " << numStudents << " rows with " << numColumns << " columns." << endl;
    return 1;  // Success
}

// This function finds where quizzes, assignments, midterm, final, and project are located
void TeacherPortal::parseHeader() {
    if (numStudents == 0) return;
    
    // Reset counters and indices
    numQuizzes = numAssignments = 0;
    midIndex = finalIndex = projectIndex = -1;
    
    for (int i = 0; i < MAX_COLUMNS; i++) {
        quizIndices[i] = -1;
        assignmentIndices[i] = -1;
    }
    
    cout << "\nHeader columns found:" << endl;
    for (int i = 0; i < numColumns; i++) {
        string header = data[0][i];
        cout << i << ": " << header << endl;
        
        if (header == "Q") {
            quizIndices[numQuizzes] = i;
            numQuizzes++;
        } else if (header == "A") {
            assignmentIndices[numAssignments] = i;
            numAssignments++;
        } else if (header == "M") {
            midIndex = i;
        } else if (header == "F") {
            finalIndex = i;
        } else if (header == "P") {
            projectIndex = i;
        }
    }
    
    cout << "\nFound:" << endl;
    cout << "Quizzes: " << numQuizzes << endl;
    cout << "Assignments: " << numAssignments << endl;
    if (midIndex >= 0) {
        cout << "Midterm: Yes" << endl;
    } else {
        cout << "Midterm: No" << endl;
    }
    if (finalIndex >= 0) {
        cout << "Final: Yes" << endl;
    } else {
        cout << "Final: No" << endl;
    }
    if (projectIndex >= 0) {
        cout << "Project: Yes" << endl;
    } else {
        cout << "Project: No" << endl;
    }
}

// This function gets weights from user (must total 100)
void TeacherPortal::inputWeights() {
    double total = 0;
    do {
        cout << "\nEnter weights (must total 100%):" << endl;
        
        if (numQuizzes > 0) {
            cout << "Quiz weight: ";
            cin >> quizWeight;
        } else {
            quizWeight = 0;
        }
        
        if (numAssignments > 0) {
            cout << "Assignment weight: ";
            cin >> assignWeight;
        } else {
            assignWeight = 0;
        }
        
        if (midIndex >= 0) {
            cout << "Midterm weight: ";
            cin >> midWeight;
        } else {
            midWeight = 0;
        }
        
        if (finalIndex >= 0) {
            cout << "Final weight: ";
            cin >> finalWeight;
        } else {
            finalWeight = 0;
        }
        
        if (projectIndex >= 0) {
            cout << "Project weight: ";
            cin >> projectWeight;
        } else {
            projectWeight = 0;
        }
        
        total = quizWeight + assignWeight + midWeight + finalWeight + projectWeight;
        
        if (total < 99.9 || total > 100.1) { // Allow small rounding errors
            cout << "Total is " << total << "%. Must equal 100%. Try again.\n";
        }
    } while (total < 99.9 || total > 100.1);
}

// This function gets maximum marks for each type of assessment
void TeacherPortal::inputMaxMarks() {
    cout << "\nEnter maximum marks for each assessment type:" << endl;
    
    if (numQuizzes > 0) {
        cout << "Quiz maximum marks: ";
        cin >> quizMaxMarks;
    }
    
    if (numAssignments > 0) {
        cout << "Assignment maximum marks: ";
        cin >> assignmentMaxMarks;
    }
    
    if (midIndex >= 0) {
        cout << "Midterm maximum marks: ";
        cin >> midMaxMarks;
    }
    
    if (finalIndex >= 0) {
        cout << "Final maximum marks: ";
        cin >> finalMaxMarks;
    }
    
    if (projectIndex >= 0) {
        cout << "Project maximum marks: ";
        cin >> projectMaxMarks;
    }
}

// This function calculates total marks for each student
void TeacherPortal::calculateTotals() {
    if (numStudents <= 1) {
        classAverage = 0;
        return;
    }
    
    classAverage = 0;
    
    // Skip header row (index 0), start from student data
    for (int i = 1; i < numStudents; i++) {
        double total = 0;
        
        // Calculate quiz average
        if (numQuizzes > 0 && quizWeight > 0) {
            double quizSum = 0;
            for (int j = 0; j < numQuizzes; j++) {
                int idx = quizIndices[j];
                if (idx >= 0 && idx < numColumns) {
                    double score = stringToDouble(data[i][idx]);
                    quizSum += score;
                }
            }
            double quizAvg = quizSum / (numQuizzes * quizMaxMarks);
            total += quizAvg * quizWeight;
        }
        
        // Calculate assignment average
        if (numAssignments > 0 && assignWeight > 0) {
            double assignSum = 0;
            for (int j = 0; j < numAssignments; j++) {
                int idx = assignmentIndices[j];
                if (idx >= 0 && idx < numColumns) {
                    double score = stringToDouble(data[i][idx]);
                    assignSum += score;
                }
            }
            double assignAvg = assignSum / (numAssignments * assignmentMaxMarks);
            total += assignAvg * assignWeight;
        }
        
        // Add midterm
        if (midIndex >= 0 && midWeight > 0) {
            double mid = stringToDouble(data[i][midIndex]);
            total += (mid / midMaxMarks) * midWeight;
        }
        
        // Add final
        if (finalIndex >= 0 && finalWeight > 0) {
            double finalExam = stringToDouble(data[i][finalIndex]);
            total += (finalExam / finalMaxMarks) * finalWeight;
        }
        
        // Add project
        if (projectIndex >= 0 && projectWeight > 0) {
            double project = stringToDouble(data[i][projectIndex]);
            total += (project / projectMaxMarks) * projectWeight;
        }
        
        totalMarks[i] = total;
        classAverage += total;
    }
    
    classAverage = classAverage / (numStudents - 1);
    cout << "\nClass average: " << classAverage << "%" << endl;
}

// This function assigns letter grades based on class average
void TeacherPortal::assignGrades() {
    int avg = round(classAverage);
    
    for (int i = 1; i < numStudents; i++) {
        double mark = totalMarks[i];
        string grade;
        
        if (mark < avg - 22) grade = "F";
        else if (mark < avg - 17) grade = "D";
        else if (mark < avg - 12) grade = "C";
        else if (mark < avg - 7) grade = "C+";
        else if (mark <= avg + 2) grade = "B";
        else if (mark <= avg + 7) grade = "B+";
        else grade = "A";
        
        grades[i] = grade;
    }
}

// This function displays all student results
void TeacherPortal::showResults() {
    if (numStudents <= 1) {
        cout << "No student data to display." << endl;
        return;
    }
    
    cout << "\n=================================================" << endl;
    cout << "                STUDENT RESULTS" << endl;
    cout << "=================================================" << endl;
    cout << "Roll\t\tName\t\t\tTotal\tGrade" << endl;
    cout << "-------------------------------------------------" << endl;
    
    for (int i = 1; i < numStudents; i++) {
        cout << data[i][0] << "\t\t" << data[i][1] << "\t\t\t" 
             << totalMarks[i] << "\t" << grades[i] << endl;
    }
    
    cout << "-------------------------------------------------" << endl;
    cout << "Class Average: " << classAverage << "%" << endl;
    cout << "=================================================" << endl;
}

// This function saves results to a CSV file
void TeacherPortal::saveResults(const string &filename) {
    ofstream out(filename.c_str());
    if (!out.is_open()) {
        cout << "Failed to open file for saving: " << filename << endl;
        return;
    }
    
    out << "Roll,Name,Total,Grade" << endl;
    
    for (int i = 1; i < numStudents; i++) {
        out << data[i][0] << "," << data[i][1] << "," 
            << totalMarks[i] << "," << grades[i] << endl;
    }
    
    out.close();
    cout << "Results saved to " << filename << endl;
}

void TeacherPortal::searchStudent(const string &roll) {
    string search = trim(roll);
    
    for (int i = 1; i < numStudents; i++) {
        string studentRoll = trim(data[i][1]); // Roll numbers are in column 1, not 0
        
        if (studentRoll == search) {
            cout << "\n==============================" << endl;
            cout << "        STUDENT FOUND" << endl;
            cout << "==============================" << endl;
            cout << "Roll: " << studentRoll << endl;
            cout << "Name: " << data[i][0] << endl; // Names are in column 0
            cout << "Total: " << totalMarks[i] << "%" << endl;
            cout << "Grade: " << grades[i] << endl;
            cout << "==============================" << endl;
            return;
        }
    }
    
    cout << "Student with roll number '" << search << "' not found." << endl;
}

int main() {
    TeacherPortal portal;
    string filename;
    
    cout << "=== Teacher Portal - Grade Calculator ===" << endl;
    cout << "Enter CSV file name: ";
    getline(cin, filename);
    
    // Try to load the file
    if (portal.loadCSV(filename) == 0) {
        cout << "Error loading file. Exiting." << endl;
        return 1;
    }
    
    portal.parseHeader();
    portal.inputWeights();
    portal.inputMaxMarks();
    portal.calculateTotals();
    portal.assignGrades();
    
    int choice;
    do {
        cout << "\n===============================" << endl;
        cout << "         MENU OPTIONS" << endl;
        cout << "===============================" << endl;
        cout << "1. Display Results" << endl;
        cout << "2. Save Results to CSV" << endl;
        cout << "3. Search Student by Roll" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice (1-4): ";
        
        cin >> choice;
        
        if (choice == 1) {
            portal.showResults();
        }
        else if (choice == 2) {
            string outFile;
            cout << "Enter output filename: ";
            cin.ignore(); // This clears the input buffer
            getline(cin, outFile);
            portal.saveResults(outFile);
        }
        else if (choice == 3) {
            string roll;
            cout << "Enter roll number: ";
            cin.ignore(); // This clears the input buffer
            getline(cin, roll);
            portal.searchStudent(roll);
        }
        else if (choice == 4) {
            cout << "Thank you for using Teacher Portal!" << endl;
        }
        else {
            cout << "Invalid choice. Please enter 1-4." << endl;
        }
        
    } while (choice != 4);

    return 0;
}
