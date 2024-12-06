#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Creating an unordered_map to store student grades
    unordered_map<string, float> studentGrades;

    // Adding student grades to the unordered_map
    studentGrades["John"] = 85.5;
    studentGrades["Emily"] = 92.0;
    studentGrades["Michael"] = 78.3;
    studentGrades["Sarah"] = 89.7;
    studentGrades["David"] = 76.9;

    // Displaying the student grades
    cout << "Student Grades:" << endl;
    for (const auto& pair : studentGrades) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Accessing a specific student's grade
    string studentName;
    cout << "\nEnter student's name to get the grade: ";
    cin >> studentName;

    if (studentGrades.find(studentName) != studentGrades.end()) {
        cout << studentName << "'s grade: " << studentGrades[studentName] << endl;
    } else {
        cout << "Student not found!" << endl;
    }

    return 0;
}
