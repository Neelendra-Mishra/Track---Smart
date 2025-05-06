//-------------------------------------------------------------------------------------------
// Written by: Neelendra Mishra
// ------------------------------------------------------------------------------------------


//                                                              - - - - START OF THE CODE - - - -

// data.h

#ifndef DATA_H
#define DATA_H

// Defining the maximum number of students that can be stored
    #define MAX_STUDENTS 100

// Defining the structure for a Student, which includes the student's ID, name, assignment grades, midterm, exam, total grade, and letter grade
    typedef struct {
        int id;
        char lastName[50];
        char firstName[50];
        int a1, a2, a3, midterm, exam;
        float total;
        char grade;
    } Student;

// Various functions
    void readData(Student *students, int *numStudents, int *capacity);
    void displaySpreadsheet(Student *students, int numStudents);  
    void removeStudent(Student *students, int *numStudents);      
    void updateLastName(Student *students, int numStudents);
    void updateExamGrade(Student *students, int numStudents);
    void displayHistogram(Student *students, int numStudents);

#endif


//                                                             - - - - END OF THE CODE - - - -