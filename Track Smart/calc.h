//-------------------------------------------------------------------------------------------
// Written by: Neelendra Mishra
// ------------------------------------------------------------------------------------------


//                                                              - - - - START OF THE CODE - - - -


// Including the header file that defines the Student structure and other data types
#ifndef CALC_H
#define CALC_H

#include "data.h"

// Function to calculate the total grade for a student based on the weighted components (e.g., assignments, midterms, exams)
    float calculateTotal(Student student);

// Function to determine the letter grade (e.g., A, B, C, etc.) based on the total grade
    char calculateGrade(float total);

//Function to adjust the grade mappings and recalculate the letter grades for all students
    void adjustGradeMapping(Student *students, int numStudents);

#endif

//                                                             - - - - END OF THE CODE - - - -