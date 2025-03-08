#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to convert letter grade to grade points (According to AU Regulations)
float getGradePoint(const string& grade) {
    if (grade == "A") return 4.00;
    else if (grade == "A-") return 3.67;
    else if (grade == "B+") return 3.33;
    else if (grade == "B") return 3.00;
    else if (grade == "B-") return 2.67;
    else if (grade == "C+") return 2.33;
    else if (grade == "C") return 2.00;
    else if (grade == "C-") return 1.67;
    else if (grade == "D") return 1.00;
    else return 0.00; // "F" or invalid grades return 0.00
}

// Function to calculate SGPA
float calculateSGPA(int subjectCount) {
    float totalPoints = 0.0, totalCredits = 0.0;

    for (int i = 0; i < subjectCount; i++) {
        int credits;
        string grade;

        cout << "\nCredits for Subject " << (i + 1) << ": ";
        cin >> credits;

        cout << "Grade (A, A-, B+, B, B-, C+, C, C-, D, F): ";
        cin >> grade;

        float gradePoint = getGradePoint(grade);
        totalPoints += gradePoint * credits;
        totalCredits += credits;
    }

    return (totalCredits > 0) ? totalPoints / totalCredits : 0.0;
}

int main() {
    int semesterCount;

    cout << "SGPA and CGPA Calculator\n";
    cout << "-------------------------\n";
    cout << "Number of semesters: ";
    cin >> semesterCount;

    float cumulativeSGPA = 0.0, totalSemesters = 0.0;

    // Store SGPA for each semester
    float sgpas[semesterCount];

    for (int i = 0; i < semesterCount; i++) {
        int subjectCount;
        cout << "\nSubjects for Semester " << (i + 1) << ": ";
        cin >> subjectCount;

        float sgpa = calculateSGPA(subjectCount);
        sgpas[i] = sgpa; // Store the SGPA for this semester
        cumulativeSGPA += sgpa;
        totalSemesters++;
    }

    // Print SGPA for each semester after all inputs
    cout << "\n-------------------------------------------------\n";
    cout << "| " << setw(10) << "Semester" << " | " << setw(10) << "SGPA" << " |\n";
    cout << "-------------------------------------------------\n";
    for (int i = 0; i < semesterCount; i++) {
        cout << "| " << setw(10) << (i + 1) << " | " << setw(10) << fixed << setprecision(2) << sgpas[i] << " |\n";
    }
    cout << "-------------------------------------------------\n";

    // Calculate CGPA (As per AU's regulation)
    float cgpa = cumulativeSGPA / totalSemesters;
    cout << "| " << setw(10) << "CGPA" << " | " << setw(10) << fixed << setprecision(2) << cgpa << " |\n";
    cout << "-------------------------------------------------\n";

    // Determine Academic Standing
    cout << "\nAcademic Standing: ";
    if (cgpa >= 3.67) cout << "High Honours\n";
    else if (cgpa >= 3.33) cout << "Honours\n";
    else if (cgpa >= 3.00) cout << "Good\n";
    else if (cgpa >= 2.67) cout << "Fair\n";
    else if (cgpa >= 2.00) cout << "Satisfactory\n";
    else if (cgpa >= 1.80) cout << "Warning\n";
    else if (cgpa >= 1.50) cout << "Seriouos Warning\n";
    else cout << "Dismissed & ineligible to rejoin\n";

    return 0;
}
