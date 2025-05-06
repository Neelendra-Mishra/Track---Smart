//-------------------------------------------------------------------------------------------
// Written by: Neelendra Mishra
// ------------------------------------------------------------------------------------------


//                                                           - - - - START OF THE CODE - - - -

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ordering.h"
#include "data.h"

// Defining a global variable to hold the current sorting criterion
        int currentSortOrder = 1;  


// Creating a comparison function for sorting by Student ID
int compareById(const void *a, const void *b)
    {
        const Student *studentA = (const Student *)a;
        const Student *studentB = (const Student *)b;
        return studentA->id - studentB->id;
    }


// Creating a comparison function for sorting by Last Name
int compareByLastName(const void *a, const void *b)
    {
        const Student *studentA = (const Student *)a;
        const Student *studentB = (const Student *)b;
        return strcmp(studentA->lastName, studentB->lastName);
    }

// Creating a comparison function for sorting by Exam Grade in descending order
int compareByExamDesc(const void *a, const void *b)
    {
        const Student *studentA = (const Student *)a;
        const Student *studentB = (const Student *)b;
        return studentB->exam - studentA->exam; // Descending order
    }

// Creating a comparison function for sorting by Total Grade in descending order
int compareByTotalDesc(const void *a, const void *b)
    {
        const Student *studentA = (const Student *)a;
        const Student *studentB = (const Student *)b;
        if (studentB->total > studentA->total)
            return 1; // studentB is greater
        if (studentB->total < studentA->total)
            return -1; // studentA is greater
        return 0;      // They are equal
    }


// Creating a comparison function for sorting by Letter Grade (with A  being the first and F being the last)
int compareByGrade(const void *a, const void *b)
    {
        const Student *studentA = (const Student *)a;
        const Student *studentB = (const Student *)b;
        return studentA->grade - studentB->grade; // A < B < C < D < E < F
    }


// Creating a function to apply sorting based on currentSortOrder
void applySort(Student *students, int numStudents)
    {
        switch (currentSortOrder)
        {
        case 1:
            qsort(students, numStudents, sizeof(Student), compareById);
            break;
        case 2:
            qsort(students, numStudents, sizeof(Student), compareByLastName);
            break;
        case 3:
            qsort(students, numStudents, sizeof(Student), compareByGrade); // Sort by letter grade
            break;
        case 4:
            qsort(students, numStudents, sizeof(Student), compareByTotalDesc); // Sort by total marks
            break;
        default:
            printf("Invalid choice, sorting by Student ID by default.\n");
            qsort(students, numStudents, sizeof(Student), compareById);
            currentSortOrder = 1; // Reset to default if invalid
        }
    }


// Creating a function to update the sorting choice based on user input
void sortData(Student *students, int numStudents)
    {
        printf("Column Options\n");
        printf("---------------\n");
        printf("1. Student ID\n");
        printf("2. Last Name\n");
        printf("3. Grade\n");        
        printf("4. Total Marks\n\n"); 
        printf("Sort Column: ");
        scanf("%d", &currentSortOrder); // Saving user choice

        applySort(students, numStudents); // Applying the selected sorting
        printf("\nSort Column updated\n");
    }

//                                                                               - - - - END OF THE CODE - - - -