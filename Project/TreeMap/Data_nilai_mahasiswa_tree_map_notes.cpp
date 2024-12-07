#include <iostream>
#include <map>
#include <string>

// Kelas untuk menyimpan data mahasiswa
class Student {
public:
    std::string studentId;       // ID Mahasiswa
    std::string studentName;     // Nama Mahasiswa
    std::string courseDetails;   // Detail Kursus
    double finalGrade;           // Nilai Akhir

    // Konstruktor
    Student(const std::string &id, const std::string &name, const std::string &course, double grade)
        : studentId(id), studentName(name), courseDetails(course), finalGrade(grade) {}
    
    // Fungsi untuk menampilkan data mahasiswa
    void display() const {
        std::cout << "Student ID: " << studentId << "\nStudent Name: " << studentName
                  << "\nCourse Details: " << courseDetails << "\nFinal Grade: " << finalGrade << "\n";
    }
};

int main() {
    std::map<std::string, Student> students;  // Map untuk menyimpan data mahasiswa
    int numberOfStudents;
    
    // Meminta jumlah mahasiswa yang akan diinput
    std::cout << "Enter the number of students: ";
    std::cin >> numberOfStudents;

    // Loop untuk mengumpulkan data mahasiswa
    for (int i = 0; i < numberOfStudents; ++i) {
        std::string studentId, studentName, courseDetails;
        int assignmentScores, examScores;

        // Mengumpulkan data mahasiswa
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
        
        // Menghitung nilai akhir
        double finalGrade = (assignmentScores * 0.4) + (examScores * 0.6);
        
        // Mengecek kesalahan (nilai negatif tidak diperbolehkan)
        if (assignmentScores < 0 || examScores < 0) {
            std::cout << "Error: Negative scores are not allowed.\n";
            --i; // Ulangi iterasi saat ini
            continue;
        }
        
        // Menyimpan data mahasiswa ke dalam map
        students.emplace(studentId, Student(studentId, studentName, courseDetails, finalGrade));
    }
    
    // Menampilkan data semua mahasiswa
    for (const auto &entry : students) {
        entry.second.display();
    }

    return 0;
}
