#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[50];
    float salary;
} Employee;

typedef struct
{
    int SS, MM, HH;
} Time;

void set_employee(Employee *emp);
void set_time(Time *time);
void get_employee(Employee *emp);
void get_time(Time *time);

Time subtract_time(Time *T1, Time *T2);

int main()
{
    // Employee emp;
    // set_employee(&emp);
    // get_employee(&emp);

    Time t1, t2, t3;

    set_time(&t1);
    set_time(&t2);
    t3 = subtract_time(&t1, &t2);

    get_time(&t1);
    get_time(&t2);
    printf("==========================================\n");
    get_time(&t3);
    printf("==========================================\n");

    return 0;
}

void set_employee(Employee *emp)
{
    printf("Employee ID: ");
    scanf("%d", &emp->id);

    getchar(); // Clear newline left in buffer after scanf

    fflush(stdin);

    printf("Employee NAME: ");
    fgets(emp->name, sizeof(emp->name), stdin);
    emp->name[strlen(emp->name) - 1] = '\0';

    printf("Employee SALARY: ");
    scanf("%f", &emp->salary);
}

void set_time(Time *time)
{
    printf("HH MM SS (24hr): ");
    scanf("%d %d %d", &time->HH, &time->MM, &time->SS);
}

void get_employee(Employee *emp)
{
    printf("%d %s %.2f\n", emp->id, emp->name, emp->salary);
}

void get_time(Time *time)
{
    printf("%d:%d:%d\n", time->HH, time->MM, time->SS);
}

Time subtract_time(Time *T1, Time *T2)
{
    Time diff;
    int secs = abs(((T1->HH * 3600) + (T1->MM * 60) + T1->SS) - ((T2->HH * 3600) + (T2->MM * 60) + T2->SS));
    printf("%d \n", secs);
    diff.HH = secs / 3600;
    diff.MM = (secs % 3600) / 60;
    diff.SS = secs % 60;
    return diff;
}
