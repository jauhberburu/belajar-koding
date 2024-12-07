#include <iostream>
#include <map>
#include <string>

class Student {
public:
    std::string studentId;
    std::string studentName;
    std::string courseDetails;
    double finalGrade;

    Student(const std::string &id, const std::string &name, const std::string &course, double grade)
        : studentId(id), studentName(name), courseDetails(course), finalGrade(grade) {}
    
    void display() const {
        std::cout << "Student ID: " << studentId << "\nStudent Name: " << studentName
                  << "\nCourse Details: " << courseDetails << "\nFinal Grade: " << finalGrade << "\n";
    }
};

int main() {
    std::map<std::string, Student> students;
    int numberOfStudents;
    
    std::cout << "Enter the number of students: ";
    std::cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; ++i) {
        std::string studentId, studentName, courseDetails;
        int assignmentScores, examScores;

        std::cout << "Enter Student ID: ";
        std::cin >> studentId;
        
        std::cout << "Enter Student Name: ";
        std::cin >> studentName;
        
        std::cout << "Enter Course Details: ";
        std::cin >> courseDetails;
        
        std::cout << "Enter Assignment Scores: ";
        std::cin >> assignmentScores;
        
        std::cout << "Enter Exam Scores: ";
        std::cin >> examScores;
        
        // Calculate Final Grade
        double finalGrade = (assignmentScores * 0.4) + (examScores * 0.6);
        
        // Check for Errors
        if (assignmentScores < 0 || examScores < 0) {
            std::cout << "Error: Negative scores are not allowed.\n";
            --i; // Repeat the current iteration
            continue;
        }
        
        // Storing Grades
        students.emplace(studentId, Student(studentId, studentName, courseDetails, finalGrade));
    }
    
    // Displaying Student Data
    for (const auto &entry : students) {
        entry.second.display();
    }

    return 0;
}