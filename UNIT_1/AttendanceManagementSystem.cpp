#include <iostream>   // Header file for input and output operations
#include <string>     // Header file for string data type
#include <fstream>    // Header file for file handling

using namespace std;

// ==========================================================
// Class : Student
// Stores student details and attendance information
// ==========================================================
class Student {
private:
    int rollNo;        // Student roll number
    string name;       // Student name
    int totalDays;     // Total number of attendance days
    int presentDays;   // Number of days student was present

public:

    // Constructor to initialize student details
    Student(int r, string n)
        : rollNo(r), name(n), totalDays(0), presentDays(0) {}

    // Function to mark attendance
    void markAttendance(bool isPresent) {

        // Increase total working days
        totalDays++;

        // If student is present, increase present days count
        if (isPresent) {
            presentDays++;
        }
    }

    // Function to calculate attendance percentage
    double getAttendancePercentage() const {

        // Avoid division by zero
        if (totalDays == 0) {
            return 0.0;
        }

        return (presentDays * 100.0) / totalDays;
    }

    // Function to display student details
    void display() const {

        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Attendance: "
             << getAttendancePercentage()
             << "%" << endl;
    }

    // ======================================================
    // Extension Activity 1
    // Function to check exam eligibility
    // Minimum attendance required = 75%
    // ======================================================
    void checkEligibility() const {

        if (getAttendancePercentage() >= 75) {
            cout << name << " is Eligible for Exam" << endl;
        }
        else {
            cout << name << " is Not Eligible for Exam" << endl;
        }
    }

    // ======================================================
    // Extension Activity 2
    // Function to check whether student is a defaulter
    // ======================================================
    bool isDefaulter() const {
        return getAttendancePercentage() < 75;
    }

    // Getter function to return student name
    string getName() const {
        return name;
    }
};

// ==========================================================
// Main Function
// ==========================================================
int main() {

    // Creating student objects
    Student s1(101, "Shree");
    Student s2(102, "Samiksha");

  
    s1.markAttendance(true);
    s1.markAttendance(true);
    s1.markAttendance(false);

    s2.markAttendance(true);
    s2.markAttendance(true);
    s2.markAttendance(true);

    // Display attendance report
    cout << "=== Attendance Report ===" << endl;
    s1.display();
    s2.display();

    // ------------------------------------------------------
    // Extension Activity 1
    // Display eligibility report
    // ------------------------------------------------------
    cout << "\n=== Eligibility Report ===" << endl;

    s1.checkEligibility();
    s2.checkEligibility();

    // ------------------------------------------------------
    // Extension Activity 2
    // Generate defaulter report
    // ------------------------------------------------------
    cout << "\n=== Defaulter Report ===" << endl;

    if (s1.isDefaulter()) {
        cout << s1.getName() << " is a Defaulter" << endl;
    }

    if (s2.isDefaulter()) {
        cout << s2.getName() << " is a Defaulter" << endl;
    }

    // ------------------------------------------------------
    // Extension Activity 3
    // Store attendance record in a text file
    // ------------------------------------------------------
    ofstream file("attendance.txt");

    // Check whether file is opened successfully
    if (file.is_open()) {

        file << "Attendance Report" << endl;
        file << "=================" << endl;

        file << "Shree : "
             << s1.getAttendancePercentage()
             << "%" << endl;

        file << "Samiksha : "
             << s2.getAttendancePercentage()
             << "%" << endl;

        // Close the file after writing data
        file.close();

        cout << "\nAttendance record stored in attendance.txt" << endl;
    }

    return 0;
}
