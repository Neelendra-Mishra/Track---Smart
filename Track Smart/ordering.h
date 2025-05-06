//-------------------------------------------------------------------------------------------
// Written by: Neelendra Mishra
// ------------------------------------------------------------------------------------------


//                                                              - - - - START OF THE CODE - - - -

#ifndef ORDERING_H
#define ORDERING_H

// Included (data.h) to access the Student structure
    #include "data.h" 

// Function prototypes used for sorting
    void sortData(Student *students, int numStudents);

// Functions prototypes used for comparison functions
    int compareById(const void *a, const void *b);
    int compareByLastName(const void *a, const void *b);
    int compareByExamDesc(const void *a, const void *b);
    int compareByTotalDesc(const void *a, const void *b);
    void sortData(Student *students, int numStudents);
    void applySort(Student *students, int numStudents);

#endif


//                                                                  - - - - END OF THE CODE - - - -
