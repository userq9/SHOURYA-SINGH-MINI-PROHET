#include <stdio.h>
#include <stdlib.h>

struct student
{
    int id;
    char name[50];
    float marks;
    struct student *next;
};

struct student *head = NULL;

void addStudent()
{
    struct student *newNode;
    newNode = (struct student *)malloc(sizeof(struct student));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\nEnter ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Name: ");
    scanf("%s", newNode->name);

    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = head;
    head = newNode;

    printf("Student Added Successfully!\n");
}

void displayStudents()
{
    struct student *temp = head;

    if (temp == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    while (temp != NULL)
    {
        printf("\nID: %d", temp->id);
        printf("\nName: %s", temp->name);
        printf("\nMarks: %.2f\n", temp->marks);
        printf("----------------------\n");
        temp = temp->next;
    }
}

void searchStudent()
{
    int id;
    printf("\nEnter ID to search: ");
    scanf("%d", &id);

    struct student *temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\nStudent Found!\n");
            printf("Name: %s\nMarks: %.2f\n", temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("\nStudent Not Found!\n");
}

void deleteStudent()
{
    int id;
    printf("\nEnter ID to delete: ");
    scanf("%d", &id);

    struct student *temp = head;
    struct student *prev = NULL;

    if (temp != NULL && temp->id == id)
    {
        head = temp->next;
        free(temp);
        printf("\nStudent Deleted Successfully!\n");
        return;
    }

    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nStudent Not Found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("\nStudent Deleted Successfully!\n");
}

void updateStudent()
{
    int id;
    printf("\nEnter ID to update: ");
    scanf("%d", &id);

    struct student *temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\nEnter New Name: ");
            scanf("%s", temp->name);

            printf("Enter New Marks: ");
            scanf("%f", &temp->marks);

            printf("\nStudent Updated Successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("\nStudent Not Found!\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            updateStudent();
            break;
        case 6:
            printf("\nExiting...\n");
            exit(0);
        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}