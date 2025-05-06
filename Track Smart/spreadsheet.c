//-------------------------------------------------------------------------------------------
// Written by: Neelendra Mishra
// ------------------------------------------------------------------------------------------

/*
                                                           ============================
                                                                PROGRAM DESCRIPTION:
                                                           ===========================

                        This C program is a simple Spreadsheet Management System that calculates and shows student grades for COMP 348.
                    It uses a menu where users can view and manage student records, such as displaying the spreadsheet, sorting data, updating records,
         and creating grade histograms. The program reads student data from a file (students.txt) and calculates final grades based on the weighted course components.


                                                           ===============================
                                                               ALGORITHM OF THE PROGRAM:
                                                           ===============================

                                                     !! A Thorough Explanation Of Every Element. !!


        * Included the necessary libraries (`stdio.h`, `stdlib.h`, etc.) and define any necessary constants and structures.

        * Created a `Student` struct to hold student information (ID, name, assignment grades, midterm, final exam, total grade, letter grade).

        * Created a function to read and parse data from `students.txt` and store it in memory (using an array or another data structure).
                        
        * Displayed a welcome message and initialize the main menu loop.

        * The program loops until the user selects the quit option. It clears the screen before displaying the menu again after every action.

        * Use a switch-case statement to handle different menu options, including displaying the spreadsheet, sorting, updating records, and exiting.

        * Clear the screen using the `system("clear")` function before redisplaying the menu.

        * After each operation, re-display the updated data or results (such as a histogram or sorted spreadsheet).



                                                        ======================================================
                                                                **** Explaining Each Option In Detail ****
                                                        ======================================================


                1) Displaying Spreadsheet (Option 1): 

                    * Showing the full list of students in a neat tabular format with the following columns:
                        Student ID, Last Name, First Name, Assignment Grades, Midterm, Exam, Total Grade, and Letter Grade.

                    * Calculating the Total Grade and Letter Grade dynamically based on the weighted contribution of
                        assignments (25%), midterm (25%), and final exam (50%).

                    * Displaying the list sorted by student ID by default.


                2) Displaying Grade in the form of Histogram (Option 2):

                        * Generating and displaying a simple text-based histogram showing the distribution of letter grades (A, B, C, D, F).

                        * Showing how many students earned each letter grade, such as how many received an A, B, and so on.


                3) Setting Sort Column (Option 3):

                        * Allowing the user to select a field by which to sort the students (e.g., by student ID, last name, exam grade, or total grade).

                        * Sorting the list using the `qsort()` function, and displaying the spreadsheet in the new order the next time Option 1 (Displaying Spreadsheet) is selected.


                4) Updating Last Name (Option 4):

                        * Prompting the user to enter a student ID, then allowing them to update the last name for that student.

                        * Reflecting the changes in the spreadsheet and displaying the updated list.


                5) Updating Exam Grade (Option 5):

                        * Prompting the user to enter a student ID, then allowing them to update the exam grade for that student.

                        * Recalculating the total grade and letter grade based on the new exam grade.

                        * Reflecting the changes in both the spreadsheet and the grade histogram.


                6) Adjusting Grade Mappings (Option 6):

                        * Allowing the user to change the default grade mappings (e.g., A >= 80, B >= 70, etc.).

                        * Automatically updating the letter grades for all students based on the new mappings.

                        * Reflecting the updated letter grades in both the spreadsheet and histogram.


                7) Deleting Student (Option 7):

                        * Prompting the user to enter a student ID, then removing the student with that ID from the spreadsheet.

                        * Updating the list, and the spreadsheet will no longer include the deleted student.


                8) Exiting the Program (Option 8):

                        * Displaying a goodbye message and gracefully exiting the program.


*/

//                                               - - - - START OF THE CODE - - - -

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "ordering.h"
#include "calc.h"


// Creating a Function to display the menu
void displayMenu()
{
    printf("Spreadsheet Menu\n");
    printf("-----------------\n");
    printf("1. Display Spreadsheet\n");
    printf("2. Display Histogram\n");
    printf("3. Set Sort Column\n");
    printf("4. Update Last Name\n");
    printf("5. Update Exam Grade\n");
    printf("6. Update Grade Mapping\n");
    printf("7. Delete Student\n");
    printf("8. Exit\n");
}

int main()
{
    int choice, numStudents = 0;
    int capacity = 10;
    Student *students = malloc(capacity * sizeof(Student));

    if (students == NULL)
    {
        perror("Failed to allocate memory");
        return 1;
    }
    // Loading the data from file
    readData(students, &numStudents, &capacity); 

    do
    {
        system("cls"); // Clear the screen in Windows
        displayMenu();
        printf("Selection: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displaySpreadsheet(students, numStudents);
            break;
        case 2:
            displayHistogram(students, numStudents);
            break;
        case 3:
            sortData(students, numStudents);
            break;
        case 4:
            updateLastName(students, numStudents);
            break;
        case 5:
            updateExamGrade(students, numStudents);
            break;
        case 6:
            adjustGradeMapping(students, numStudents);
            break;
        case 7:
            removeStudent(students, &numStudents);
            break;
        case 8:
            printf("Goodbye and thanks for using our spreadsheet app.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

        if (choice != 8)
        {
            printf("\nPress 'c' or 'C' to continue ");
            char proceed;
            do
            {
                scanf(" %c", &proceed);
            } while ((proceed != 'c') && (proceed != 'C'));
        }
    } while (choice != 8);

    free(students); // Free dynamically allocated memory
    return 0;
}

 //                                                             - - - - END OF THE CODE - - - -
