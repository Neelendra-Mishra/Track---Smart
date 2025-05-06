//-------------------------------------------------------------------------------------------
// Written by: Neelendra Mishra
// ------------------------------------------------------------------------------------------


//                                                      ---- START OF THE CODE ----


// Including standard libraries and adding custom header files

#include <stdio.h>
#include <string.h> // Required for (strcpy)
#include "calc.h"
#include "data.h"
#include "grades.h"


// Setting grade boundaries (default values)
int grade_A = 80;
int grade_B = 70;
int grade_C = 60;
int grade_D = 50;


// Creating a function for calculating the total grade for a student.

float calculateTotal(Student student)
{
    float assignments = ((student.a1 + student.a2 + student.a3) / 120.0) * 25.0; // Average of the assignments (assuming total marks 120 total)
    float midterm = (student.midterm / 25.0) * 25.0;                             // Midterm (assuming total marks 25)
    float exam = (student.exam / 40.0) * 50.0;                                   // Exam (assuming total marks 40)

    return assignments + midterm + exam;                                         // Total grade
}


// Creating a function to calculate the letter grade based on the total
char calculateGrade(float total)
{
    if (total >= grade_A)
        return 'A';
    if (total >= grade_B)
        return 'B';
    if (total >= grade_C)
        return 'C';
    if (total >= grade_D)
        return 'D';
    return 'F'; // If any grade is below letter D.
}


// Creating a function to update a student's last name
void updateLastName(Student *students, int numStudents)
{
    int id;
    char newLastName[50];

    displaySpreadsheet(students, numStudents); // Displaying the current students
    printf("\n\nEnter Student ID: ");
    scanf("%d", &id);
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].id == id)
        {
            printf("\nEnter updated Last Name: ");
            scanf("%s", newLastName);
            strcpy(students[i].lastName, newLastName);
            printf("Last name updated\n");
            return;
        }
    }
    printf("Student ID not found.\n"); // ID not found
}

// Creating a function to update the exam grade for a student
void updateExamGrade(Student *students, int numStudents)
{
    int id, newGrade;

    displaySpreadsheet(students, numStudents); 
    printf("\n\nEnter Student ID: ");
    scanf("%d", &id);
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].id == id)
        {
            printf("\nEnter updated exam grade: ");
            scanf("%d", &newGrade);

            // Validating the grade
            if (newGrade >= 0 && newGrade <= 40)
            {
                students[i].exam = newGrade;                             // Update exam grade.
                students[i].total = calculateTotal(students[i]);         // Recalculate total.
                students[i].grade = calculateGrade(students[i].total);   // Update letter grade.
                printf("\nExam grade updated\n");
            }
            else
            {
                printf("Invalid grade. Must be between 0 and 40.\n");
            }
            return; // Exit the function after update
        }
    }
    printf("Student ID not found.\n"); // ID not found
}


// Creating a function to adjust the grade mappings
void adjustGradeMapping(Student *students, int numStudents)
{
    printf("Current Mapping:\n");
    printf("A: >= %d\n", grade_A);
    printf("B: >= %d\n", grade_B);
    printf("C: >= %d\n", grade_C);
    printf("D: >= %d\n", grade_D);
    printf("F:  < %d\n", grade_D);
    printf("\n\n");

    // Asking user for the new boundaries
    printf("Enter new A baseline: ");
    scanf("%d", &grade_A);
    printf("Enter new B baseline: ");
    scanf("%d", &grade_B);
    printf("Enter new C baseline: ");
    scanf("%d", &grade_C);
    printf("Enter new D baseline: ");
    scanf("%d", &grade_D);

    for (int i = 0; i < numStudents; i++)
    {
        students[i].total = calculateTotal(students[i]);       // Recalculating the total grade
        students[i].grade = calculateGrade(students[i].total); // Updating the letter grade
    }
    printf("\n\nNew Mapping:\n");
    printf("A: >= %d\n", grade_A);
    printf("B: >= %d\n", grade_B);
    printf("C: >= %d\n", grade_C);
    printf("D: >= %d\n", grade_D);
    printf("F:  < %d\n", grade_D);
}


// Creating a function to display a histogram of the grades
void displayHistogram(Student *students, int numStudents)
{
    int grades[5] = {0}; // A, B, C, D, F

    // Counting number of students in each grade category
    for (int i = 0; i < numStudents; i++)
    {
        switch (students[i].grade)
        {
        case 'A':
            grades[0]++;
            break;
        case 'B':
            grades[1]++;
            break;
        case 'C':
            grades[2]++;
            break;
        case 'D':
            grades[3]++;
            break;
        case 'F':
            grades[4]++;
            break;
        }
    }


    // Displaying the histogram using '*' symbols
    printf("COMP 348 Grade Distribution\n\n");
    printf("A: ");
    for (int i = 0; i < grades[0]; i++)
    {
        printf("*");
    }
    printf("\nB: ");
    for (int i = 0; i < grades[1]; i++)
    {
        printf("*");
    }
    printf("\nC: ");
    for (int i = 0; i < grades[2]; i++)
    {
        printf("*");
    }
    printf("\nD: ");
    for (int i = 0; i < grades[3]; i++)
    {
        printf("*");
    }
    printf("\nF: ");
    for (int i = 0; i < grades[4]; i++)
    {
        printf("*");
    }
    printf("\n");
}


//                                                                  ---- END OF THE CODE ----