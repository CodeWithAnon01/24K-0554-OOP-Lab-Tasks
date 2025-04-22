#include <iostream>
#include <string>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(string courseCode, int credits) : courseCode(courseCode), credits(credits) {}

    virtual void calculateGrade() = 0;
    virtual void displayInfo() = 0;

    virtual ~Course() {}
};

class LectureCourse : public Course {
public:
    LectureCourse(string courseCode, int credits) : Course(courseCode, credits) {}

    void calculateGrade() override {
        cout << "Calculating grade for LectureCourse: " << courseCode << endl;
    }

    void displayInfo() override {
        cout << "Lecture Course Code: " << courseCode << ", Credits: " << credits << endl;
    }
};

class LabCourse : public Course {
public:
    LabCourse(string courseCode, int credits) : Course(courseCode, credits) {}

    void calculateGrade() override {
        cout << "Calculating grade for LabCourse: " << courseCode << endl;
    }

    void displayInfo() override {
        cout << "Lab Course Code: " << courseCode << ", Credits: " << credits << endl;
    }
};

int main() {
    Course* course1 = new LectureCourse("CS101", 3);
    Course* course2 = new LabCourse("CHEM201", 4);

    course1->displayInfo();
    course1->calculateGrade();

    cout << endl;

    course2->displayInfo();
    course2->calculateGrade();

    delete course1;
    delete course2;

    return 0;
}

// Output
// Lecture Course Code: CS101, Credits: 3
// Calculating grade for LectureCourse: CS101

// Lab Course Code: CHEM201, Credits: 4
// Calculating grade for LabCourse: CHEM201
