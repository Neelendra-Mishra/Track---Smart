//-------------------------------------------------------------------------------------------
// Written by: Neelendra Mishra
// ------------------------------------------------------------------------------------------


//                                                              - - - - START OF THE CODE - - - -

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "ordering.h"
#include "calc.h"

void readData(Student *students, int *numStudents, int *capacity)
{
    FILE *file = fopen("students.txt", "r");
    if (!file)
    {
        perror("Failed to open file");
        exit(1);
    }

    char line[256];
    *numStudents = 0;

    while (fgets(line, sizeof(line), file))
    {
        if (*numStudents >= *capacity)
        {
            *capacity += 10;
            students = realloc(students, *capacity * sizeof(Student));
            if (students == NULL)
            {
                perror("Failed to reallocate memory");
                exit(1);
            }
        }

// Parse each line into the student structure fields
        sscanf(line, "%d|%[^|]|%[^|]|%d|%d|%d|%d|%d",
               &students[*numStudents].id, students[*numStudents].lastName,
               students[*numStudents].firstName, &students[*numStudents].a1,
               &students[*numStudents].a2, &students[*numStudents].a3,
               &students[*numStudents].midterm, &students[*numStudents].exam);
               students[*numStudents].total = calculateTotal(students[*numStudents]);
               students[*numStudents].grade = calculateGrade(students[*numStudents].total);
        (*numStudents)++;
    }
    fclose(file);
}


// Function to display the student data in a tabular format

void displaySpreadsheet(Student *students, int numStudents)
{
    printf("COMP 348 GRADE SHEET\n\n");
    applySort(students, numStudents); // Ensure data is sorted before displaying
    printf("ID      Last       First       A1   A2   A3   Mid  Exam  Total  Grade\n");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < numStudents; i++)
    {
        printf("%-8d %-10s %-10s %-4d %-4d %-4d %-4d %-4d %-6.2f %-7c\n",
               students[i].id,
               students[i].lastName,
               students[i].firstName,
               students[i].a1,
               students[i].a2,
               students[i].a3,
               students[i].midterm,
               students[i].exam,
               students[i].total,
               students[i].grade);
    }
}

// Function to remove a student by their ID
void removeStudent(Student *students, int *numStudents)
{
    int id;

    // Display the current list of students
         displaySpreadsheet(students, *numStudents); 

    printf("Enter Student ID: ");

    // Get the student ID from the user
         scanf("%d", &id);

    // Find the student with the given ID
        for (int i = 0; i < *numStudents; i++)
        {
            if (students[i].id == id)
            {
                // Shift the remaining students to fill the gap
                for (int j = i; j < *numStudents - 1; j++)

                {
                    // Move each student one position up
                    students[j] = students[j + 1]; 
                }

                 // Reduce the number of students
                (*numStudents)--; 
                printf("Student successfully deleted\n");
                return;
            }
        }

        // Message if student ID is not found
                printf("Student ID not found.\n");
}

//                                                                   - - - - END OF THE CODE - - - -