#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char code[20];
    char name[50];
    int creditHours;
    char department[50];
} Course;

typedef struct {
    char id[20];
    char name[50];
    char department[50];
} Faculty;

typedef struct {
    char roomNumber[20];
    int capacity;
    char department[50];
} Classroom;

typedef struct {
    char scheduleID[20];
    char courseCode[20];
    char facultyID[20];
    char roomNumber[20];
    char day[10];
    char timeSlot[10];
} Schedule;

Course courses[50];
Faculty faculties[50];
Classroom classrooms[50];
Schedule schedules[100];

int courseCount = 0;
int facultyCount = 0;
int classroomCount = 0;
int scheduleCount = 0;

void saveCoursesToFile() {
    FILE *file = fopen("courses.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < courseCount; i++) {
        fprintf(file, "%s %s %d %s\n", courses[i].code, courses[i].name, courses[i].creditHours, courses[i].department);
    }
    fclose(file);
}

void loadCoursesFromFile() {
    FILE *file = fopen("courses.txt", "r");
    if (file == NULL) {
        printf("No existing course data found.\n");
        return;
    }
    while (fscanf(file, "%s %s %d %s", courses[courseCount].code, courses[courseCount].name, &courses[courseCount].creditHours, courses[courseCount].department) != EOF) {
        courseCount++;
    }
    fclose(file);
}

void saveFacultiesToFile() {
    FILE *file = fopen("faculties.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < facultyCount; i++) {
        fprintf(file, "%s %s %s\n", faculties[i].id, faculties[i].name, faculties[i].department);
    }
    fclose(file);
}

void loadFacultiesFromFile() {
    FILE *file = fopen("faculties.txt", "r");
    if (file == NULL) {
        printf("No existing faculty data found.\n");
        return;
    }
    while (fscanf(file, "%s %s %s", faculties[facultyCount].id, faculties[facultyCount].name, faculties[facultyCount].department) != EOF) {
        facultyCount++;
    }
    fclose(file);
}

void saveClassroomsToFile() {
    FILE *file = fopen("classrooms.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < classroomCount; i++) {
        fprintf(file, "%s %d %s\n", classrooms[i].roomNumber, classrooms[i].capacity, classrooms[i].department);
    }
    fclose(file);
}

void loadClassroomsFromFile() {
    FILE *file = fopen("classrooms.txt", "r");
    if (file == NULL) {
        printf("No existing classroom data found.\n");
        return;
    }
    while (fscanf(file, "%s %d %s", classrooms[classroomCount].roomNumber, &classrooms[classroomCount].capacity, classrooms[classroomCount].department) != EOF) {
        classroomCount++;
    }
    fclose(file);
}

void saveSchedulesToFile() {
    FILE *file = fopen("schedules.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < scheduleCount; i++) {
        fprintf(file, "%s %s %s %s %s %s\n", schedules[i].scheduleID, schedules[i].courseCode, schedules[i].facultyID, schedules[i].roomNumber, schedules[i].day, schedules[i].timeSlot);
    }
    fclose(file);
}

void loadSchedulesFromFile() {
    FILE *file = fopen("schedules.txt", "r");
    if (file == NULL) {
        printf("No existing schedule data found.\n");
        return;
    }
    while (fscanf(file, "%s %s %s %s %s %s", schedules[scheduleCount].scheduleID, schedules[scheduleCount].courseCode, schedules[scheduleCount].facultyID, schedules[scheduleCount].roomNumber, schedules[scheduleCount].day, schedules[scheduleCount].timeSlot) != EOF) {
        scheduleCount++;
    }
    fclose(file);
}

void addCourse() {
    Course newCourse;
    printf("Enter Course Code: ");
    scanf("%s", newCourse.code);
    printf("Enter Course Name: ");
    scanf("%s", newCourse.name);
    printf("Enter Credit Hours: ");
    scanf("%d", &newCourse.creditHours);
    printf("Enter Department: ");
    scanf("%s", newCourse.department);

    courses[courseCount++] = newCourse;
    printf("Course added successfully!\n");
}

void addFaculty() {
    Faculty newFaculty;
    printf("Enter Faculty ID: ");
    scanf("%s", newFaculty.id);
    printf("Enter Faculty Name: ");
    scanf("%s", newFaculty.name);
    printf("Enter Department: ");
    scanf("%s", newFaculty.department);

    faculties[facultyCount++] = newFaculty;
    printf("Faculty added successfully!\n");
}

void addClassroom() {
    Classroom newClassroom;
    printf("Enter Room Number: ");
    scanf("%s", newClassroom.roomNumber);
    printf("Enter Capacity: ");
    scanf("%d", &newClassroom.capacity);
    printf("Enter Department: ");
    scanf("%s", newClassroom.department);

    classrooms[classroomCount++] = newClassroom;
    printf("Classroom added successfully!\n");
}

void scheduleClass() {
    Schedule newSchedule;
    printf("Enter Schedule ID: ");
    scanf("%s", newSchedule.scheduleID);
    printf("Enter Course Code: ");
    scanf("%s", newSchedule.courseCode);
    printf("Enter Faculty ID: ");
    scanf("%s", newSchedule.facultyID);
    printf("Enter Room Number: ");
    scanf("%s", newSchedule.roomNumber);
    printf("Enter Day: ");
    scanf("%s", newSchedule.day);
    printf("Enter Time Slot: ");
    scanf("%s", newSchedule.timeSlot);

    schedules[scheduleCount++] = newSchedule;
    printf("Class scheduled successfully!\n");
}

void displayTimetable() {
    printf("Timetable:\n");
    for (int i = 0; i < scheduleCount; i++) {
        printf("Schedule ID: %s, Course Code: %s, Faculty ID: %s, Room Number: %s, Day: %s, Time Slot: %s\n",
               schedules[i].scheduleID, schedules[i].courseCode, schedules[i].facultyID,
               schedules[i].roomNumber, schedules[i].day, schedules[i].timeSlot);
    }
}

int main() {
    loadCoursesFromFile();
    loadFacultiesFromFile();
    loadClassroomsFromFile();
    loadSchedulesFromFile();

    int choice;
    while (1) {
        printf("\nCollege Timetable Management System\n");
        printf("1. Add Course\n");
        printf("2. Add Faculty\n");
        printf("3. Add Classroom\n");
        printf("4. Schedule Class\n");
        printf("5. Display Timetable\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCourse();
                saveCoursesToFile();
                break;
            case 2:
                addFaculty();
                saveFacultiesToFile();
                break;
            case 3:
                addClassroom();
                saveClassroomsToFile();
                break;
            case 4:
                scheduleClass();
                saveSchedulesToFile();
                break;
            case 5:
                displayTimetable();
                break;
            case 6:
                saveCoursesToFile();
                saveFacultiesToFile();
                saveClassroomsToFile();
                saveSchedulesToFile();
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
